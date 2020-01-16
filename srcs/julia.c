/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:39:08 by rjaakonm          #+#    #+#             */
/*   Updated: 2020/01/16 13:11:42 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"

static int	julia(double c_r, double c_i, int limit_i, t_fract *node)
{
	int		i;
	double	z_r;
	double	z_i;
	double	limit_z;
	double	tmp;

	i = 0;
	limit_z = 4.0;
	z_r = (node->cur_x - node->move_x - node->img_width / 2)
			/ (node->zoom * node->img_width / (node->x_mult * 2));
	z_i = (node->cur_y - node->move_y - node->img_height / 2)
			/ (node->zoom * node->img_width / (node->y_mult * 2));
	while (i < limit_i && z_r * z_r + z_i * z_i < limit_z)
	{
		tmp = z_r * z_r - z_i * z_i + c_r;
		z_i = (2 * z_i * z_r + c_i);
		z_r = tmp;
		i++;
	}
	return (i);
}

void		make_julia(t_fract *node)
{
	int		y;
	int		x;
	double	c_r;
	double	c_i;
	int		nb;

	c_r = -0.705 + node->z_r;
	c_i = 0.26 + node->z_i;
	y = node->thread;
	while (y < node->img_height)
	{
		node->cur_y = y;
		x = 0;
		while (x < node->img_width)
		{
			node->cur_x = x;
			nb = julia(c_r, c_i, node->limit_i, node);
			node->color = 0x000000;
			if (nb != node->limit_i)
				check_color(nb, node->limit_i, node);
			image_set(x, y, node);
			x++;
		}
		y += THREADS;
	}
}
