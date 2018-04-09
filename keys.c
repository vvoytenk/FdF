/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <vvoytenk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 20:35:58 by vvoytenk          #+#    #+#             */
/*   Updated: 2018/03/31 20:35:59 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rot_key(int keycode, t_fdf *fdf)
{
	rotation(fdf, keycode);
}

void	exit_key(int keycode)
{
	if (keycode == EXIT)
		exit(1);
}

void	zoom_key(int keycode, t_fdf *fdf)
{
	if (keycode == 6)
		zoom(fdf, 1.1);
	else if (keycode == 7)
		zoom(fdf, 1 / 1.1);
}

void	move_key(int keycode, t_fdf *fdf)
{
	if (keycode == LEFT)
		move_x(fdf, -15);
	else if (keycode == RIGHT)
		move_x(fdf, 15);
	else if (keycode == UP)
		move_y(fdf, -15);
	else if (keycode == DOWN)
		move_y(fdf, 15);
}

void	colour_key(int keycode, t_fdf *fdf)
{
	if (keycode == P_COLOUR)
		change_colour(1, fdf);
	if (keycode == M_COLOUR)
		change_colour(-1, fdf);
}
