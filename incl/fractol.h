/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:16:51 by rjaakonm          #+#    #+#             */
/*   Updated: 2020/01/15 18:06:36 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WINDOW_X 1300
# define WINDOW_Y 1000
# define WHITE 0xffffff
# define THREADS 20

typedef struct		s_fract
{
	int		fractal;
	int		cur_x;
	int		cur_y;
	double	r_min;
	double	r_max;
	double	i_min;
	double	i_max;
	double	z_r;
	double	z_i;
	int		img_width;
	int		img_height;
	int		limit_i;
	double	limit_z;
	double	zoom;
	int		color;
	int		color_x;
	double	move_x;
	double	move_y;
	int		mousemove;
	int		mouse_1;
	int		mouse_2;
	int		mouse_x;
	int		mouse_y;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*data_addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		thread;
}					t_fract;

void				make_fractal(t_fract *node);

int					deal_key(int key, t_fract *node);

int					exit_free(t_fract *node);
void				node_values(t_fract *node);
void				add_texts(t_fract *node);
void				check_color(int nb, int limit_i, t_fract *node);
void				refresh(t_fract *node);

void				make_mandelbrot(t_fract *node);

void				make_julia(t_fract *node);

void				make_ship(t_fract *node);

int					mouse_move(int x, int y, t_fract *node);
int					mouse_release(int button, int x, int y, t_fract *node);
int					mouse_press(int button, int x, int y, t_fract *node);

#endif
