/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_colour.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <vvoytenk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:06:03 by vvoytenk          #+#    #+#             */
/*   Updated: 2018/03/30 19:06:05 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		change_colour(int sign, t_fdf *fdf)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < fdf->num_line)
	{
		j = 0;
		while (j < fdf->col_num)
		{
			if (sign > 0)
				fdf->dots[i][j].colour += 0xB29858;
			if (sign < 0)
				fdf->dots[i][j].colour -= 0xB29858;
			j++;
		}
		i++;
	}
}
