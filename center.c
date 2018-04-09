/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <vvoytenk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 19:42:00 by vvoytenk          #+#    #+#             */
/*   Updated: 2018/03/17 19:42:00 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		check_center(t_fdf *fdf)
{
	fdf->center->x = (fdf->dots[fdf->num_line - 1][fdf->col_num - 1].x
		+ (int)fdf->dots[0][0].x) / 2;
	fdf->center->y = (fdf->dots[fdf->num_line - 1][fdf->col_num - 1].y
		+ (int)fdf->dots[0][0].y) / 2;
	fdf->center->z = 0;
	fdf->center->colour = 0;
}

void		move2cntr(t_fdf *fdf)
{
	int		mv_x;
	int		mv_y;

	mv_x = WID / 2 - (int)fdf->center->x;
	mv_y = HEI / 2 - (int)fdf->center->y;
	move_x(fdf, mv_x);
	move_y(fdf, mv_y);
}
