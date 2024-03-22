/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:40:34 by ndavenne          #+#    #+#             */
/*   Updated: 2024/03/22 16:02:37 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (c == '\0')
		return (s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_trim_extra(char *buffer, char *line, char c)
{
	char	*end_line;
	int		i;

	i = 0;
	end_line = ft_strchr(line, c) + 1;
	while (end_line[i] != '\0')
		*buffer++ = end_line[i++];
	*buffer = '\0';
	*end_line = '\0';
}

void	ft_strcpy(char *d, char *s)
{
	char	*s_cpy;

	s_cpy = s;
	while (*s != '\0')
		*d++ = *s++;
	*d = '\0';
	*s_cpy = '\0';
}
