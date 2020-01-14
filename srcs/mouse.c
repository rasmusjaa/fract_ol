/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:24:57 by rjaakonm          #+#    #+#             */
/*   Updated: 2020/01/14 16:55:56 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include "ft_printf.h"

int			mouse_move(int x, int y, t_fract *node)
{
	if (node->mouse_1 == 1)
	{
		node->move_x -= node->mouse_x - x;
		node->move_y -= node->mouse_y - y;
		node->mouse_x = x;
		node->mouse_y = y;
	}
	if (node->mousemove == 1)
	{
		node->z_r -= (float)(node->mouse_x - x) / 200;
		node->z_i -= (float)(node->mouse_y - y) / 200;
		node->mouse_x = x;
		node->mouse_y = y;
	}
	mlx_destroy_image(node->mlx_ptr, node->img_ptr);
	node->img_ptr = mlx_new_image(node->mlx_ptr, WINDOW_X, WINDOW_Y);
	mlx_clear_window(node->mlx_ptr, node->win_ptr);
	make_fractal(node);
	return (0);
}

int			mouse_release(int button, int x, int y, t_fract *node)
{
	if (button == 1)
	{
		node->mouse_x = x;
		node->mouse_y = y;
		node->mouse_1 = 0;
	}
	if (button == 2)
	{
		node->mouse_x = x;
		node->mouse_y = y;
		node->mouse_2 = 0;
	}
	return (0);
}

int			mouse_press(int button, int x, int y, t_fract *node)
{
	if (button == 1)
	{
		node->mouse_x = x;
		node->mouse_y = y;
		node->mouse_1 = 1;
	}
	if (button == 2)
	{
		node->mouse_x = x;
		node->mouse_y = y;
		node->mouse_2 = 1;
	}
	if (button == 4)
	{
		node->zoom *= 1.1;
		mlx_destroy_image(node->mlx_ptr, node->img_ptr);
		node->img_ptr = mlx_new_image(node->mlx_ptr, WINDOW_X, WINDOW_Y);
		mlx_clear_window(node->mlx_ptr, node->win_ptr);
		make_fractal(node);
	}
	if (button == 5)
	{
		node->zoom *= 1.1;
		mlx_destroy_image(node->mlx_ptr, node->img_ptr);
		node->img_ptr = mlx_new_image(node->mlx_ptr, WINDOW_X, WINDOW_Y);
		mlx_clear_window(node->mlx_ptr, node->win_ptr);
		make_fractal(node);
	}
	ft_printf("zoom %f\n", node->zoom);
	return (0);
}
