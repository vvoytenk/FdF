/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <vvoytenk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 18:07:35 by vvoytenk          #+#    #+#             */
/*   Updated: 2018/03/28 18:07:36 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		keys(int keycode, t_fdf *fdf)
{
	check_center(fdf);
	rot_key(keycode, fdf);
	move_key(keycode, fdf);
	zoom_key(keycode, fdf);
	exit_key(keycode);
	if (keycode == 15 || keycode == 3)
		change_colour(keycode, fdf);
	redraw(fdf);
	return (0);
}

void	redraw(t_fdf *fdf)
{
	t_image *img;

	img = &(fdf->image);
	img->ptr = mlx_new_image(fdf->mlx, WID, HEI);
	img->data = mlx_get_data_addr(img->ptr, &(img->bits_per_pixel),
		&(img->size_line), &(img->endian));
	draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image.ptr, 0, 0);
	mlx_destroy_image(fdf->mlx, fdf->image.ptr);
}

void	change_fdf(t_fdf *fdf)
{
	size_t	i;
	size_t	j;
	int		n;

	i = 0;
	zoom(fdf, (fdf->col_num > fdf->num_line ? (WID * 0.2) / fdf->col_num
		: (HEI * 0.2) / fdf->num_line) * 2);
	while (i < fdf->num_line)
	{
		j = 0;
		while (j < fdf->col_num)
		{
			n = -1;
			while (++n < 4)
				fdf->dots[i][j] = rot_x(&fdf->dots[i][j], -1, fdf);
			while (++n < 7)
				fdf->dots[i][j] = rot_y(&fdf->dots[i][j], -1, fdf);
			while (++n < 19)
				fdf->dots[i][j] = rot_z(&fdf->dots[i][j], 1, fdf);
			j++;
		}
		i++;
	}
}

int		exit_x(void)
{
	exit(1);
}
