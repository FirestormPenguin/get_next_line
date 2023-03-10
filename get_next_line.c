/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:23:30 by egiubell          #+#    #+#             */
/*   Updated: 2023/02/20 18:20:33 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *str)
{
	char	*buff;
	int		nb_read;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	nb_read = 1;
	while (!ft_strchr(str, '\n') && nb_read != 0)
	{
		nb_read = read(fd, buff, BUFFER_SIZE);
		if (nb_read == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[nb_read] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read_line(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	str = ft_new_str(str);
	return (line);
}

/*#include <stdio.h>
#include <fcntl.h>

int main()
{
	char	buf[100];
	int		fd;
	int		nb_read;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (1);	
	char *a = get_next_line(fd);
	char *b = get_next_line(fd);
	char *c = get_next_line(fd);
	//printf("%s", a);
	//printf("%s", b);
	//printf("%s", c);
	close(fd);
	return (0);
}*/
