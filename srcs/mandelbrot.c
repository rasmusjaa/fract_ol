/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:24:44 by rjaakonm          #+#    #+#             */
/*   Updated: 2020/01/14 17:03:03 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include "ft_printf.h"

static void	add_texts(t_fract *node)
{
	mlx_string_put(node->mlx_ptr, node->win_ptr, 10, 10, 0xffffff,
		"CONTROLS:");
	mlx_string_put(node->mlx_ptr, node->win_ptr, 10, 30, 0xffffff,
		"PROJECTIONS: 1 = , 2 = ");
	mlx_string_put(node->mlx_ptr, node->win_ptr, 10, 50, 0xffffff,
		"EXIT: Esc");
}

static void	image_set(int x, int y, t_fract *node)
{
	*(int*)(node->data_addr + (((y * WINDOW_X) + x)
		* node->bpp)) = node->color;
}

static int	mandelbrot(double c_r, double c_i, int limit_i, t_fract *node)
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
		z_i = 2 * z_i * z_r + c_i;
		z_r = tmp + c_r;
		i++;
	}
	return (i);
}

double		to_real(int x, int img_width, double r_min, double r_max)
{
	double	range;

	range = r_max - r_min;
	return (x * (range / img_width) + r_min);
}

double		to_imaginary(int y, int img_height, double i_min, double i_max)
{
	double	range;

	range = i_max - i_min;
	return (y * (range / img_height) + i_min);
}

void		check_color(int nb, int limit_i, t_fract *node)
{
	float	divided;

	divided = (float)nb / (float)limit_i;
	if (divided > 0.9)
		node->color = 0x006EC2;
	else if (divided > 0.8)
		node->color = 0x00BCC6;
	else if (divided > 0.7)
		node->color = 0x00CA87;
	else if (divided > 0.6)
		node->color = 0x00CE3B;
	else if (divided > 0.5)
		node->color = 0x13D200;
	else if (divided > 0.4)
		node->color = 0x65D500;
	else if (divided > 0.3)
		node->color = 0xBAD900;
	else if (divided > 0.2)
		node->color = 0xDDA800;
	else if (divided > 0.1)
		node->color = 0xE15500;
	else
		node->color = 0xE50000;
}

void		make_mandelbrot(t_fract *node)
{
	int		y;
	int		x;
	double	c_r;
	double	c_i;
	int		nb = 0;

	y = 0;
	while (y < node->img_height)
	{
		x = 0;
		while (x < node->img_width)
		{
			c_r = to_real(x - node->move_x, node->img_width, node->r_min, node->r_max) / node->zoom;
			c_i = to_imaginary(y - node->move_y, node->img_height, node->i_min, node->i_max) / node->zoom;
			nb = mandelbrot(c_r, c_i, node->limit_i, node);
			if (nb != node->limit_i)
				check_color(nb, node->limit_i, node);
			else
				node->color = 0x000000;
			image_set(x, y, node);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(node->mlx_ptr, node->win_ptr, node->img_ptr, 0, 0);
	add_texts(node);
}
