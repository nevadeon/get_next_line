/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:40:37 by ndavenne          #+#    #+#             */
/*   Updated: 2024/03/14 20:08:32 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;
	size_t		read_bytes;

	if (buffer == NULL)
	{
		buffer = (char *) malloc(sizeof(char) * (1));
		if (buffer == NULL)
			return (NULL);
		buffer[0] = '\0';
	}
	while (ft_strchr(buffer, '\n'))
	{
		buffer = realloc(buffer, ft_strlen(buffer) + BUFFER_SIZE + 1);
		read_bytes = read(fd, (buffer + ft_strlen(buffer)), BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[ft_strlen(buffer) + BUFFER_SIZE] = '\0';
	}
	return (line);
}

int	main(void)
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	close(fd);
	return (0);
}
