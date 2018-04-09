/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <vvoytenk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 15:50:08 by vvoytenk          #+#    #+#             */
/*   Updated: 2018/03/29 15:50:10 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		zoom(t_fdf *fdf, double scale)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < fdf->num_line)
	{
		j = 0;
		while (j < fdf->col_num)
		{
			fdf->dots[i][j].x = (fdf->dots[i][j].x - fdf->center->x)
			* scale + fdf->center->x;
			fdf->dots[i][j].y = (fdf->dots[i][j].y - fdf->center->y)
			* scale + fdf->center->y;
			fdf->dots[i][j].z = fdf->dots[i][j].z * scale;
			j++;
		}
		i++;
	}
}
