/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:24:44 by rjaakonm          #+#    #+#             */
/*   Updated: 2020/01/15 18:09:15 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include "ft_printf.h"

static double	abs_d(double x)
{
	if (x < 0)
		return (-1 * x);
	else
		return (x);
}

static void		image_set(int x, int y, t_fract *node)
{
	*(int*)(node->data_addr + (((y * WINDOW_X) + x)
		* node->bpp)) = node->color;
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
	while(i < limit_i && z_r * z_r + z_i * z_i < limit_z)
	{
		tmp = z_r * z_r - z_i * z_i;
		z_i = 2 * abs_d(z_i * z_r) - c_i;
		z_r = tmp - c_r;
		i++;
	}
	return (i);
}

static double	to_real(int x, int img_width, double r_min, double r_max)
{
	double	range;

	range = r_max - r_min;
	return (x * (range / img_width) + r_min);
}

static double	to_imaginary(int y, int img_height, double i_min, double i_max)
{
	double	range;

	range = i_max - i_min;
	return (y * (range / img_height) + i_min);
}

void			make_ship(t_fract *node)
{
	int		y;
	int		x;
	double	c_r;
	double	c_i;
	int		nb = 0;

	y = node->thread;
	while (y < node->img_height)
	{
		x = 0;
		while (x < node->img_width)
		{
			c_r = to_real(x - node->move_x, node->img_width, node->r_min, node->r_max) / node->zoom;
			c_i = to_imaginary(y - node->move_y, node->img_height, node->i_min, node->i_max) / node->zoom;
			nb = ship(c_r, c_i, node->limit_i, node);
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
