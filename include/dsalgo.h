#ifndef DSALGO
# define DSALGO

#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#ifndef TRUE
# define TRUE 1
#endif

#ifndef FALSE
# define FALSE 0
#endif

/*
** vector.c
** a dynamic resizable array of pointer
**
*/

typedef struct	s_vector
{
	void *container;
	size_t size;
	size_t capacity;
	size_t bsize;
	int		storingaddr;
}				Vector;

struct s_vector *vectorptr(void);
struct s_vector *vector(size_t bsize);
int vpush(struct s_vector *vector, void *data);
void *vget(struct s_vector *vector, size_t i);
size_t vsize(struct s_vector *vector);
int vempty(struct s_vector *vector);
void *vpop(struct s_vector *vector);

void *vzone(struct s_vector *vector);
//void *vextract(struct s_vector **vector); //return the zone and clean the vector
struct s_vector *vinitb(size_t bsize);
int vremove(struct s_vector **vector);
int vremovedeep(struct s_vector **vector);
void vprint(struct s_vector *v, char *(*ftoa)(void*));
void vprintln(struct s_vector *v, char *(*ftoa)(void*));
void vprintstr(struct s_vector *v);

/*
** string.c
** basic string manipulation function
**
** split(char *s, char *d as delimiter): return a vector of the splitted string
*/

#include <string.h>

struct s_vector	*split(char *str, char *delimiter);
int				startswith(char *s, char *d);
int				endswith(char *s, char *d);
int				contains(char *s, char *d);
char			*prepend(char *s, char *pre);
char			*append(char *s, char *app);
char			*join(char separator, char **args);
char			*str(const char *s);

/*
** anytos.c //any to string
** utility functions to convert a type to a string
**
** note: you should free the string after using it.
*/
#include <stdarg.h>
#include <stdio.h>

char *anytos(const char* format, ...);

char *itos(void *d);
char *utos(void *u);
char	*stos(void *s);

#endif
