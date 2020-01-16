/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:24:57 by rjaakonm          #+#    #+#             */
/*   Updated: 2020/01/16 10:43:49 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"

int			mouse_move(int x, int y, t_fract *node)
{
	if (node->mouse_1 == 1)
	{
		node->move_x -= node->mouse_x - x;
		node->move_y -= node->mouse_y - y;
		refresh(node);
	}
	else if (node->mouse_2 == 1)
	{
		node->color_x -= node->mouse_x - x;
		node->color_x -= node->mouse_y - y;
		if (node->color_x < 1 || node->color_x > 10000)
			node->color_x = 1;
		refresh(node);
	}
	else if (node->mousemove == 1)
	{
		node->z_r -= (float)(node->mouse_x - x) / 200;
		node->z_i -= (float)(node->mouse_y - y) / 200;
		refresh(node);
	}
	node->mouse_x = x;
	node->mouse_y = y;
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
	return (0);
}

static void	mouse_press2(int button, int x, int y, t_fract *node)
{
	node->move_x -= (x - WINDOW_X / 2);
	node->move_y -= (y - WINDOW_Y / 2);
	if (button == 4)
	{
		node->zoom *= 1.2;
		node->move_x *= 1.2;
		node->move_y *= 1.2;
		node->move_x += (x - WINDOW_X / 2);
		node->move_y += (y - WINDOW_Y / 2);
	}
	if (button == 5)
	{
		node->zoom *= 0.8;
		node->move_x *= 0.8;
		node->move_y *= 0.8;
		node->move_x += (x - WINDOW_X / 2);
		node->move_y += (y - WINDOW_Y / 2);
	}
}

int			mouse_press(int button, int x, int y, t_fract *node)
{
	if (button == 1)
		node->mouse_1 = 1;
	else if (button == 2)
		node->mouse_2 = 1;
	else if (button == 3 || button == 4 || button == 5)
		mouse_press2(button, x, y, node);
	refresh(node);
	return (0);
}
