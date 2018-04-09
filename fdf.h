/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <vvoytenk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 16:59:22 by vvoytenk          #+#    #+#             */
/*   Updated: 2018/04/01 16:59:34 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <math.h>

# define WID 1600
# define HEI 1200

# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define P_X 12
# define M_X 0
# define P_Y 13
# define M_Y 1
# define P_Z 14
# define M_Z 2
# define P_COLOUR 15
# define M_COLOUR 3

# define EXIT 53

typedef struct	s_var
{
	double		x;
	double		y;
}				t_var;

typedef struct	s_dots
{
	double		x;
	double		y;
	double		z;
	int			colour;
}				t_dots;

typedef struct	s_image
{
	void		*ptr;
	char		*data;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_image;

typedef struct	s_fdf
{
	t_dots		**dots;
	t_dots		*center;
	t_image		image;
	size_t		num_line;
	size_t		col_num;
	void		*mlx;
	void		*win;
}				t_fdf;

size_t			read_file(char *file);
char			**get_rows(size_t line_num, char *file);
size_t			columns(char **s);
t_fdf			*get_struct(char **buf, size_t num_line, size_t col_num);
t_fdf			*memory(size_t num_line, size_t num_col);
t_dots			fill_struct(size_t y, size_t x, char *val);
int				valid(char **row, size_t col_num);
void			create_window(t_fdf *fdf);
void			create_image(t_fdf *fdf);
void			draw(t_fdf *fdf);
void			drawline(t_fdf *fdf, t_dots a, t_dots b);
void			put_colour2img(t_image *img, double x, double y, int colour);
void			move2cntr(t_fdf *fdf);
void			check_center(t_fdf *fdf);
void			move_key(int keycode, t_fdf *fdf);
void			move_y(t_fdf *fdf, int move);
void			move_x(t_fdf *fdf, int move);
void			colour_key(int keycode, t_fdf *fdf);
int				keys(int keycode, t_fdf *fdf);
void			redraw(t_fdf *fdf);
void			rotation(t_fdf *fdf, int keycode);
void			rot_key(int keycode, t_fdf *fdf);
void			zoom(t_fdf *fdf, double scale);
void			zoom_key(int keycode, t_fdf *fdf);
void			change_fdf(t_fdf *fdf);
t_dots			rot_z(t_dots *a, int dir, t_fdf *fdf);
t_dots			rot_y(t_dots *a, int dir, t_fdf *fdf);
t_dots			rot_x(t_dots *a, int dir, t_fdf *fdf);
void			exit_key(int keycode);
int				exit_x(void);
void			error(void);
void			change_colour(int sign, t_fdf *fdf);

#endif
