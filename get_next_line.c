/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:40:37 by ndavenne          #+#    #+#             */
/*   Updated: 2024/03/22 16:02:48 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*_free(char *s)
{
	free(s);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	size_t		line_len;
	ssize_t		read_bytes;

	line = (char *) malloc(sizeof(char));
	if (line == NULL)
		return (NULL);
	line[0] = '\0';
	while (!ft_strchr(line, '\n'))
	{
		line_len = ft_strlen(line);
		line = realloc(line, line_len + BUFFER_SIZE + 1);
		if (line == NULL)
			return (NULL);
		if (buffer[0] != '\0')
			ft_strcpy(line, buffer);
		else
		{
			read_bytes = read(fd, (line + line_len), BUFFER_SIZE);
			if (read_bytes == -1)
				return (_free(line));
			line[line_len + read_bytes] = '\0';
		}
	}
	ft_trim_extra(buffer, line, '\n');
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	close(fd);
	return (0);
}
