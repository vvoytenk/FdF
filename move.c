/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <vvoytenk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 22:25:56 by vvoytenk          #+#    #+#             */
/*   Updated: 2018/03/21 22:26:00 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		move_x(t_fdf *fdf, int move)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < fdf->num_line)
	{
		j = 0;
		while (j < fdf->col_num)
		{
			fdf->dots[i][j].x = fdf->dots[i][j].x + move;
			fdf->dots[i][j].y = fdf->dots[i][j].y;
			fdf->dots[i][j].z = fdf->dots[i][j].z;
			fdf->dots[i][j].colour = fdf->dots[i][j].colour;
			j++;
		}
		i++;
	}
}

void		move_y(t_fdf *fdf, int move)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < fdf->num_line)
	{
		j = 0;
		while (j < fdf->col_num)
		{
			fdf->dots[i][j].y = fdf->dots[i][j].y + move;
			fdf->dots[i][j].x = fdf->dots[i][j].x;
			fdf->dots[i][j].z = fdf->dots[i][j].z;
			fdf->dots[i][j].colour = fdf->dots[i][j].colour;
			j++;
		}
		i++;
	}
}
