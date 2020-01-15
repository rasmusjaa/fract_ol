/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:39:08 by rjaakonm          #+#    #+#             */
/*   Updated: 2020/01/15 18:01:25 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include "ft_printf.h"
#include <math.h>

static void	image_set(int x, int y, t_fract *node)
{
	*(int*)(node->data_addr + (((y * WINDOW_X) + x)
		* node->bpp)) = node->color;
}

static double	to_real(int x, int img_width, double r_min, double r_max)
{
	double	range;

	range = r_max - r_min;
	return (x * (range / (img_width)) + r_min);
}

static double	to_imaginary(int y, int img_height, double i_min, double i_max)
{
	double	range;

	range = i_max - i_min;
	return (y * (range / img_height) + i_min);
}

static int	julia(double c_r, double c_i, int limit_i, t_fract *node)
{
	int		i;
	double	z_r;
	double	z_i;
	double	limit_z;
	double	tmp;

	i = 0;
	limit_z = 4.0;
	z_r = to_real(node->cur_x - node->move_x, node->img_width, node->r_min, node->r_max) / (node->zoom);
	z_i = to_imaginary(node->cur_y - node->move_y, node->img_height, node->i_min, node->i_max) / (node->zoom);
	while(i < limit_i && z_r * z_r + z_i * z_i < limit_z)
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
	int		nb = 0;

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
			if (nb != node->limit_i)
				check_color(nb, node->limit_i, node);
			else
				node->color = 0x000000;
			image_set(x, y, node);
			x++;
		}
		y += THREADS;
	}
}
