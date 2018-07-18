#include "dsalgo.h"

#include <stdio.h>

struct s_vector	*split(char *s, char *d)
{
	struct s_vector *v;
	int dlen;
	int l;
	int i;

	v = vectorptr();
	dlen = strlen(d);
	l = 0;
	i = 0;
	while (s[i])
	{
		if (strncmp(s + i, d, dlen) == 0)
		{
			if (l != i)
				vpush(v, strndup(s + l, i-l) );
			i += dlen;
			l = i;
		}
		else
			i += 1;
	}
	if (l != i)
		vpush(v, strndup(s + l, i-l) );
	return (v);
}

int startswith(char *s, char *d)
{
	size_t i;

	if (!s || !d)
		return (FALSE);
	i = 0;
	while (s[i] && d[i] && s[i] == d[i])
	{
		i += 1;
	}
	if (!d[i])
		return (TRUE);
	return (FALSE);
}

int endswith(char *s, char *d)
{
	size_t i;
	size_t b;

	i = strlen(d);
	if (i > strlen(s))
		return FALSE;
	b = 0;
	while (s[i + b] && d[b] && s[i + b] == d[b])
	{
		b += 1;
	}
	if (!d[b])
		return TRUE;
	return FALSE;
}

int contains(char *s, char *d)
{
	size_t i;
	size_t n;

	i = 0;
	n = strlen(d);
	while (s[i])
	{
		if (strncmp(s + i, d, n) == 0)
			return TRUE;
		i += 1;
	}
	return FALSE;
}

char	*prepend(char *s, char *pre)
{
	char *ns;
	int		i;
	int		j;

	ns = malloc(strlen(s) + strlen(pre));
	i = 0;
	j = -1;
	while (pre[++j])
		ns[i++] = pre[j];
	j = -1;
	while (s[++j])
		ns[i++] = s[j];
	ns[i] = 0;
	free(s);
	return (ns);
}

char	*append(char *s, char *app)
{
	char *ns;
	int		i;
	int		j;

	ns = malloc(strlen(s) + strlen(app));
	i = 0;
	j = -1;
	while (s[++j])
		ns[i++] = s[j];
	j = -1;
	while (app[++j])
		ns[i++] = app[j];
	ns[i] = 0;
	free(s);
	return (ns);
}

char	*join(char separator, char **args)
{
	char	*s;
	size_t	size;
	char *sp;
	int i;

	size = 0;
	s = malloc(1);
	s[0] = 0;
	sp = malloc(2);
	sp[1] = 0;
	sp[0] = separator;
	i = 0;
	while (args[i])
	{
		s = append(s, args[i]);
		if (args[i+1])
			s = append(s, sp);
		i += 1;
	}
	return (s);
}

char *str(const char *s){
	return strdup(s);
}
