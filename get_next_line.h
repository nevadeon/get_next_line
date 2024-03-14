/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:40:39 by ndavenne          #+#    #+#             */
/*   Updated: 2024/03/14 19:48:22 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef int				t_bool;
typedef unsigned long	t_ulong;

typedef struct s_fdline
{
	int		fd;
	char	*line;
}	t_fdline;

char	*get_next_line(int fd);
int		ft_strchr(char *s, char c);
void	ft_strcat(char *d, char *s);
int		slen(const char *s);
void	*ft_memcpy(void *dest, const void *src, int n);

#endif