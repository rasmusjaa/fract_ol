/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:24:57 by rjaakonm          #+#    #+#             */
/*   Updated: 2020/01/15 18:14:58 by rjaakonm         ###   ########.fr       */
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
	}
	if (node->mouse_2 == 1)
	{
		ft_printf("%d\n", node->color_x);
			node->color_x -= node->mouse_x - x;
			node->color_x -= node->mouse_y - y;
		if (node->color_x < 1 || node->color_x > 10000)
			node->color_x = 1;
	}
	if (node->mousemove == 1)
	{
		node->z_r -= (float)(node->mouse_x - x) / 200;
		node->z_i -= (float)(node->mouse_y - y) / 200;
	}
	node->mouse_x = x;
	node->mouse_y = y;
	refresh(node);
	return (0);
}

int			mouse_release(int button, int x, int y, t_fract *node)
{
	node->mouse_x = x;
	node->mouse_y = y;
	if (button == 1)
		node->mouse_1 = 0;
	else if (button == 2)
		node->mouse_2 = 0;
	ft_printf("x %d y %d zoom %f\n", node->move_x, node->move_y, node->zoom);
	return (0);
}

int			mouse_press(int button, int x, int y, t_fract *node)
{
	if (button == 1)
		node->mouse_1 = 1;
	else if (button == 2)
		node->mouse_2 = 1;
	else if (button == 3)
	{
		node->move_x -= (x - WINDOW_X / 2);
		node->move_y -= (y - WINDOW_Y / 2);
	}
	else if (button == 4)
	{
		node->move_x -= (x - WINDOW_X / 2);
		node->move_y -= (y - WINDOW_Y / 2);
		node->zoom *= 1.2;
		node->move_x *= 1.2;
		node->move_y *= 1.2;
		node->move_x += (x - WINDOW_X / 2);
		node->move_y += (y - WINDOW_Y / 2);
	}
	else if (button == 5)
	{
		node->move_x -= (x - WINDOW_X / 2);
		node->move_y -= (y - WINDOW_Y / 2);
		node->zoom *= 0.8;
		node->move_x *= 0.8;
		node->move_y *= 0.8;
		node->move_x += (x - WINDOW_X / 2);
		node->move_y += (y - WINDOW_Y / 2);
	}
	refresh(node);
	return (0);
}
