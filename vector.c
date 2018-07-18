#include "dsalgo.h"

#include <stdio.h>

int vupgrade(struct s_vector *v)
{
	void	*tmp;
	size_t	i;
	size_t	p;

	if (!(tmp = malloc(v->bsize * v->capacity * 2)))
		return (0);
	i = 0;
	p = 0;
	while (i < v->size)
	{
		memcpy(tmp + p, v->container + p, v->bsize);
		p += v->bsize;
		i += 1;
	}
	free(v->container);
	v->container = tmp;
	v->capacity *= 2;
	return (1);
}

int vpush(struct s_vector *vector, void *data)
{
	if (!vector || !data)
		return (0);
	if (vector->size + 1 >= vector->capacity)
	{
		if (!vupgrade(vector))
			return (0);
	}
	memcpy(vector->container + (vector->bsize * vector->size),
		(vector->storingaddr) ? &data : data,
		vector->bsize);
	vector->size += 1;
	return (1);
}

void *vget(struct s_vector *vector, size_t i)
{
	void *tmp;

	if (!vector)
		return (NULL);
	if (i >= vector->size)
		return (NULL);

	tmp = vector->container + (vector->bsize * i);
	if (vector->storingaddr)
		return (*(void**)tmp);
	return (tmp);
}

void *vpop(struct s_vector *vector)
{
	void *tmp;

	if (!vector)
		return (NULL);
	if (vector->size == 0)
		return (NULL);
	tmp = vget(vector, vector->size-1);
	vector->size -= 1;
	return (tmp);
}

int vempty(struct s_vector *vector){
	if (!vector)
		return (0);
	return vector->size == 0;
}

struct s_vector *vector(size_t bsize)
{
	struct s_vector *vector;

	vector = malloc(sizeof(struct s_vector));
	if (!vector)
		return (NULL);
	vector->capacity = 1024;
	vector->container = malloc(bsize * vector->capacity);
	if (!vector->container)
		return (NULL);
	vector->size = 0;
	vector->bsize = bsize;
	vector->storingaddr = FALSE;
	return (vector);
}

struct s_vector *vectorptr(void)
{
	struct s_vector *v;

	v = vector(sizeof(void*));
	v->storingaddr = TRUE;
	return (v);
}

void *vzone(struct s_vector *vector)
{
	if (!vector)
		return (NULL);
	return vector->container;
}

size_t vsize(struct s_vector *vector)
{
	if (!vector)
		return (0);
	return (vector->size);
}

static int _vremovedeep(struct s_vector *vector)
{
	size_t	i;
	size_t	p;

	if (!vector || !vector->container)
		return (0);
	p = 0;
	i = 0;
	while (i < vector->size)
	{
		free(*(void**)(vector->container + p));
		p += vector->bsize;
		i += 1;
	}
	return (1);
}

int vremovedeep(struct s_vector **vector)
{
	_vremovedeep(*vector);
	free((*vector)->container);
	free(*vector);
	*vector = NULL;
	return (1);
}

int vremove(struct s_vector **vector)
{
	free((*vector)->container);
	free(*vector);
	*vector = NULL;
	return (1);
}

static void _vprint(struct s_vector *v, char *(*ftoa)(void*), int ln)
{
	size_t	i;
	char	*tmp;

	i = 0;
	printf("%zu: [", vsize(v));
	while (i < vsize(v))
	{
		tmp = ftoa(vget(v, i));
		printf("%s",tmp);
		if (i + 1 < vsize(v))
		{
			printf((ln) ? ",\n" : ", ");
		}
		free(tmp);
		i += 1;
	}
	printf("]\n");
}

void vprint(struct s_vector *v, char *(*ftoa)(void*))
{
	_vprint(v, ftoa, FALSE);
}

void vprintln(struct s_vector *v, char *(*ftoa)(void*))
{
	_vprint(v, ftoa, TRUE);
}
void vprintstr(struct s_vector *v){
	_vprint(v, stos, FALSE);
}

/*
struct s_array *vtoa(struct s_vector *vector)
{
	return (NULL);
}*/
