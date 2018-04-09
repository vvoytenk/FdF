/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <vvoytenk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:38:00 by vvoytenk          #+#    #+#             */
/*   Updated: 2018/04/03 18:47:25 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t		read_file(char *file)
{
	int		fd;
	size_t	line_num;
	char	*line;

	line_num = 0;
	line = NULL;
	fd = open(file, O_RDONLY);
	if ((read(fd, line, 0)) < 0)
		return (0);
	while (get_next_line(fd, &line))
	{
		line_num++;
		free(line);
	}
	close(fd);
	return (line_num);
}

char		**get_rows(size_t line_num, char *file)
{
	int		fd;
	char	*line;
	char	**buf;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (0);
	}
	if (!(buf = (char **)malloc(sizeof(char *) * line_num + 1)))
		return (NULL);
	while (get_next_line(fd, &line))
	{
		buf[i++] = ft_strdup(line);
		free(line);
	}
	buf[i] = NULL;
	close(fd);
	return (buf);
}
