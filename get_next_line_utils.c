/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 13:28:43 by cjulienn          #+#    #+#             */
/*   Updated: 2021/08/04 12:45:44 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	unsigned long	counter;

	counter = 0;
	while (str[counter])
		counter++;
	return (counter);
}

char	*ft_strchr(const char *s, int c)
{
	char			*new_ptr;
	char			d;
	size_t			iter;

	iter = 0;
	if (!s)
		return (NULL);
	d = (char)c;
	new_ptr = (char *)s;
	while (s[iter])
	{
		if (s[iter] != d)
			new_ptr++;
		else
			return (new_ptr);
		iter++;
	}
	if (s[iter] == d)
		return (new_ptr);
	else
		return (NULL);
}

char	*ft_strjoin_and_free(char const *s1, char const *s2)
{
	char			*copy;
	size_t			i;
	size_t			j;

	copy = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * (sizeof(char)));
	if (!(copy))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		copy[i] = s2[j];
		i++;
		j++;
	}
	copy[i] = '\0';
	free((void *)s1);
	return (copy);
}

char	*ft_strdup(const char *str)
{
	char				*copy;
	unsigned long		sizer;
	int					i;

	sizer = ft_strlen(str) + 1;
	copy = malloc(sizer * (sizeof(char)));
	if (!(copy))
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
