/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <vvoytenk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 20:26:04 by vvoytenk          #+#    #+#             */
/*   Updated: 2018/03/31 20:26:06 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dots		rot_x(t_dots *a, int dir, t_fdf *fdf)
{
	t_dots	temp;
	double	l;
	double	y;

	y = a->y - fdf->center->y;
	l = (dir < 0) ? -0.03 : 0.03;
	temp.x = a->x;
	temp.y = y * cos(l) + a->z * sin(l) + fdf->center->y;
	temp.z = -y * sin(l) + a->z * cos(l);
	temp.colour = a->colour;
	return (temp);
}

t_dots		rot_y(t_dots *a, int dir, t_fdf *fdf)
{
	t_dots	temp;
	double	l;
	double	x;

	x = a->x - fdf->center->x;
	l = (dir < 0) ? -0.03 : 0.03;
	temp.x = x * cos(l) + a->z * sin(l) + fdf->center->x;
	temp.y = a->y;
	temp.z = -x * sin(l) + a->z * cos(l);
	temp.colour = a->colour;
	return (temp);
}

t_dots		rot_z(t_dots *a, int dir, t_fdf *fdf)
{
	t_dots	temp;
	double	l;
	double	x;
	double	y;

	x = a->x - fdf->center->x;
	y = a->y - fdf->center->y;
	l = (dir < 0) ? -0.03 : 0.03;
	temp.x = x * cos(l) - y * sin(l) + fdf->center->x;
	temp.y = x * sin(l) + y * cos(l) + fdf->center->y;
	temp.z = a->z;
	temp.colour = a->colour;
	return (temp);
}

void		rotation(t_fdf *fdf, int keycode)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < fdf->num_line)
	{
		j = 0;
		while (j < fdf->col_num)
		{
			if (keycode == P_X)
				fdf->dots[i][j] = rot_x(&fdf->dots[i][j], 1, fdf);
			else if (keycode == P_Y)
				fdf->dots[i][j] = rot_y(&fdf->dots[i][j], 1, fdf);
			else if (keycode == P_Z)
				fdf->dots[i][j] = rot_z(&fdf->dots[i][j], 1, fdf);
			else if (keycode == M_X)
				fdf->dots[i][j] = rot_x(&fdf->dots[i][j], -1, fdf);
			else if (keycode == M_Y)
				fdf->dots[i][j] = rot_y(&fdf->dots[i][j], -1, fdf);
			else if (keycode == M_Z)
				fdf->dots[i][j] = rot_z(&fdf->dots[i][j], -1, fdf);
			j++;
		}
		i++;
	}
}
