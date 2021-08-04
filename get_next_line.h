/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 13:28:47 by cjulienn          #+#    #+#             */
/*   Updated: 2021/08/04 13:41:25 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef	BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_utils
{
	size_t		reader;
	size_t		i;
	size_t		j;
	char		buffer;
}				t_utils;

char	*get_next_line(int fd);
char	*ft_output(ssize_t reader, char **stc_line, int iter);
char	*ft_cut_rtn(const char *line);
char	*ft_cut_line(ssize_t reader, char *line);
char	*ft_strjoin_and_free(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *str);

#endif