/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anytos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agadhgad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:22:47 by agadhgad          #+#    #+#             */
/*   Updated: 2018/04/14 16:22:48 by agadhgad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dsalgo.h"

char	*anytos(const char *format, ...)
{
	char		*s;
	va_list		arglist;

	s = malloc(sizeof(char) * 256);
	va_start(arglist, format);
	vprintf(format, arglist);
	va_end(arglist);
	return (s);
}


char	*itos(void *d)
{
	return (anytos("%d", *(int*)d));
}

char	*utos(void *u)
{
	return (anytos("%u", *(unsigned int*)u));
}

char	*stos(void *s){
	return anytos("%u", *(char*)s);
}
