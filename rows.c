/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rows.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <vvoytenk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 18:12:00 by vvoytenk          #+#    #+#             */
/*   Updated: 2018/04/03 18:52:56 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t		columns(char **s)
{
	size_t	col_num;
	int		i;

	col_num = 0;
	i = -1;
	while (s[col_num])
		col_num++;
	while (s[++i])
		free(s[i]);
	free(s);
	return (col_num);
}

t_fdf		*memory(size_t num_line, size_t num_col)
{
	t_fdf	*fdf;
	size_t	i;

	i = 0;
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	fdf->dots = (t_dots **)malloc(sizeof(t_dots*) * num_line);
	fdf->center = (t_dots*)malloc(sizeof(t_dots));
	fdf->num_line = num_line;
	fdf->col_num = num_col;
	while (i < num_line)
	{
		fdf->dots[i] = (t_dots *)malloc(sizeof(t_dots) * num_col);
		i++;
	}
	return (fdf);
}

int			get_colour(char *val)
{
	size_t	i;

	i = 0;
	if (ft_strchr(val, ','))
	{
		while (val[i] != ',')
			i++;
		return (ft_atoi_base(val + i + 3, 16));
	}
	return (0xFFFFFF);
}

t_dots		fill_struct(size_t y, size_t x, char *val)
{
	t_dots	dot;

	dot.x = (int)x;
	dot.y = (int)y;
	dot.z = ft_atoi(val);
	dot.colour = get_colour(val);
	return (dot);
}

t_fdf		*get_struct(char **buf, size_t num_line, size_t col_num)
{
	t_fdf	*fdf;
	size_t	i;
	size_t	j;
	char	**split_line;

	i = 0;
	fdf = memory(num_line, col_num);
	while (i < num_line)
	{
		j = 0;
		split_line = ft_strsplit(buf[i], ' ');
		if (!valid(split_line, fdf->col_num))
			return (0);
		while (j < col_num)
		{
			fdf->dots[i][j] = fill_struct(i, j, split_line[j]);
			free(split_line[j]);
			j++;
		}
		i++;
		free(split_line);
	}
	return (fdf);
}
