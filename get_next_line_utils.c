/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:40:34 by ndavenne          #+#    #+#             */
/*   Updated: 2024/03/14 20:09:29 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *s, char c)
{
	if (!s)
		return (1);
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

void	ft_strcat(char *d, char *s)
{
	while (*d)
		d++;
	while (*s)
	{
		*d = *s;
		d++;
		s++;
	}
	*d = '\0';
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, int n)
{
	const unsigned char	*s;
	unsigned char		*d;

	if (n != 0 && (dest == src))
		return (dest);
	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	while (n--)
		*d++ = *s++;
	return (dest);
}
