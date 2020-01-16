/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:24:44 by rjaakonm          #+#    #+#             */
/*   Updated: 2020/01/16 10:29:48 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"

static int		mandelbrot(double c_r, double c_i, int limit_i, t_fract *node)
{
	int		i;
	double	z_r;
	double	z_i;
	double	limit_z;
	double	tmp;

	i = 0;
	z_r = node->z_r;
	z_i = node->z_i;
	limit_z = 4.0;
	while (i < limit_i && z_r * z_r + z_i * z_i < limit_z)
	{
		tmp = z_r * z_r - z_i * z_i;
		z_i = 2 * z_i * z_r + c_i;
		z_r = tmp + c_r;
		i++;
	}
	return (i);
}

void			make_mandelbrot(t_fract *node)
{
	int		y;
	int		x;
	double	c_r;
	double	c_i;
	int		nb;

	y = node->thread;
	while (y < node->img_height)
	{
		x = 0;
		while (x < node->img_width)
		{
			c_r = to_real(x - node->move_x, node->img_width,
				node->r_min, node->r_max) / node->zoom;
			c_i = to_imaginary(y - node->move_y, node->img_height,
				node->i_min, node->i_max) / node->zoom;
			nb = mandelbrot(c_r, c_i, node->limit_i, node);
			node->color = 0x000000;
			if (nb != node->limit_i)
				check_color(nb, node->limit_i, node);
			image_set(x, y, node);
			x++;
		}
		y += THREADS;
	}
}
