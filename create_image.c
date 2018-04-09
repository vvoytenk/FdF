/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <vvoytenk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 16:27:00 by vvoytenk          #+#    #+#             */
/*   Updated: 2018/03/18 16:27:00 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			create_image(t_fdf *fdf)
{
	t_image		*img;

	img = &(fdf->image);
	img->ptr = mlx_new_image(fdf->mlx, WID, HEI);
	img->data = mlx_get_data_addr(img->ptr, &(img->bits_per_pixel),
											&(img->size_line), &(img->endian));
}

static t_var	initialize_var(t_dots a, t_dots b, int *steps)
{
	t_var		var;

	var.x = b.x - a.x;
	var.y = b.y - a.y;
	(*steps) = (int)(fabs(var.x) >= fabs(var.y) ? fabs(var.x) : fabs(var.y));
	var.x = (*steps) ? var.x / *steps : 0.0;
	var.y = (*steps) ? var.y / *steps : 0.0;
	return (var);
}

void			drawline(t_fdf *fdf, t_dots a, t_dots b)
{
	t_var		var;
	int			steps;
	double		i;

	var = initialize_var(a, b, &steps);
	i = 0;
	while (i++ <= steps)
	{
		put_colour2img(&(fdf->image), a.x, a.y, a.colour);
		a.x += var.x;
		a.y += var.y;
	}
}

void			put_colour2img(t_image *img, double x, double y, int colour)
{
	if (x < 0 || y < 0 || x >= WID || y >= HEI)
		return ;
	*(int *)(img->data + ((int)x + (int)y * WID) * 4) = colour;
}

void			draw(t_fdf *fdf)
{
	size_t		i;
	size_t		j;

	i = 0;
	create_image(fdf);
	while (i < fdf->num_line)
	{
		j = 0;
		while (j < fdf->col_num)
		{
			if (j < fdf->col_num - 1)
				drawline(fdf, fdf->dots[i][j], fdf->dots[i][j + 1]);
			if (i < fdf->num_line - 1)
				drawline(fdf, fdf->dots[i][j], fdf->dots[i + 1][j]);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image.ptr, 0, 0);
}
