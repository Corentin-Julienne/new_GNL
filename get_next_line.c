/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 13:28:45 by cjulienn          #+#    #+#             */
/*   Updated: 2021/08/04 13:41:52 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*ft_output(ssize_t reader, char	**line, int iter)
{
	char	*rtn;
	
	if (reader < 0)
		return (NULL);
	if (reader == 0 && *line[0] == '\0')
	{
		if (iter > 0)
			free((void *)*line);
		return (NULL);
	}
	if (reader == 0 && *line == NULL)
		return (NULL);
	if (reader > 0 && *line == NULL)
		return (NULL);
	rtn = ft_cut_rtn(*line);
	if (!rtn)
		return (NULL);
	*line = ft_cut_line(reader, *line);
	if (reader > 0)
		return (rtn);
	else if (reader == 0 && *line == NULL)
		return (rtn);
	else
		return (NULL);
}

char	*ft_cut_rtn(const char *line)
{
	size_t	malloc_size;
	size_t	i;
	size_t	ln_rtn;
	char	*cutted_line;

	malloc_size = 0;
	ln_rtn = 0;
	if (ft_strchr(line, '\n'))
		ln_rtn++;
	while (line[malloc_size] != '\n' && line[malloc_size])
		malloc_size++;
	cutted_line = (char *)malloc(sizeof(char) * (malloc_size + 1 + ln_rtn));
	if (!cutted_line)
		return (NULL);
	i = 0;
	while (line[i] && malloc_size > 0)
	{
		cutted_line[i] = line[i];
		i++;
		malloc_size--;
	}
	cutted_line[i + ln_rtn] = '\0';
	if (ln_rtn > 0)
		cutted_line[i] = '\n';
	return (cutted_line);
}

char	*ft_cut_line(ssize_t reader, char *line)
{
	char	*cutted_stc;

	if (!line)
		return (NULL);
	if (reader == 0)
	{
		free((void *)line);
		return (NULL);
	}
	if (ft_strchr(line, '\n') && ft_strlen(ft_strchr(line, '\n')) > 1)
		cutted_stc = ft_strdup(ft_strchr(line, '\n') + 1);
	else if (ft_strchr(line, '\n') && ft_strlen(ft_strchr(line, '\n')) == 1)
		cutted_stc = ft_strdup("");
	else
		cutted_stc = ft_strdup(line);
	free((void *)line);
	if (!cutted_stc)
		return (NULL);
	return (cutted_stc);
}

char	*get_next_line(int fd)
{
	static char		*line = NULL;
	char			*buffer;
	ssize_t 		reader;
	static int		iter = -1;			

	iter++;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	reader = 1;
	while (ft_strchr(line, '\n') == NULL && reader > 0)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader < 0)
			break;
		buffer[reader] = '\0';
		if (!line)
			line = ft_strdup("");
		line = ft_strjoin_and_free(line, buffer);
		if (!line)
			break;
	}
	free(buffer);
	return (ft_output(reader, &line, iter));
}
