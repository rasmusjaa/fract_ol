/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:24:44 by rjaakonm          #+#    #+#             */
/*   Updated: 2020/01/16 14:05:03 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"

static double	abs_d(double x)
{
	if (x < 0)
		return (-1 * x);
	else
		return (x);
}

static int		ship(double c_r, double c_i, int limit_i, t_fract *node)
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
		tmp = node->plus1 * z_r * z_r - z_i * z_i;
		z_i = node->plus2 * 2 * abs_d(z_i * z_r) - c_i;
		z_r = tmp - c_r;
		i++;
	}
	return (i);
}

void			make_ship(t_fract *node)
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
			c_r = (x - node->move_x - node->img_width / 2)
				/ (node->zoom * node->img_width / (node->x_mult * 2));
			c_i = -1 * (y - node->move_y - node->img_height / 2)
				/ (node->zoom * node->img_width / (node->y_mult * 2));
			nb = ship(c_r, c_i, node->limit_i, node);
			node->color = 0x000000;
			if (nb != node->limit_i)
				check_color(nb, node->limit_i, node);
			image_set(x, y, node);
			x++;
		}
		y += THREADS;
	}
}
