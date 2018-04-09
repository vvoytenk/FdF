/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <vvoytenk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:25:48 by vvoytenk          #+#    #+#             */
/*   Updated: 2018/03/30 20:25:50 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			error(void)
{
	ft_putstr("ERROR\n");
	exit(1);
}

int				main(int argc, char **argv)
{
	char		**buf;
	t_fdf		*fdf;
	size_t		num_line;
	size_t		col_num;

	if (argc == 2)
	{
		if ((num_line = read_file(argv[1])) == 0)
			error();
		buf = get_rows(num_line, argv[1]);
		col_num = columns(ft_strsplit(buf[0], ' '));
		if (!(fdf = (get_struct(buf, num_line, col_num))))
			error();
		create_window(fdf);
		check_center(fdf);
		change_fdf(fdf);
		move2cntr(fdf);
		draw(fdf);
		mlx_hook(fdf->win, 2, 3, keys, fdf);
		mlx_hook(fdf->win, 17, 0, exit_x, 0);
		mlx_loop(fdf->mlx);
	}
	else
		error();
	return (0);
}
