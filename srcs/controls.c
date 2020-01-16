/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 18:30:21 by rjaakonm          #+#    #+#             */
/*   Updated: 2020/01/16 13:12:42 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include <stdlib.h>

/*
** 123: fractal, ~ rgb
*/

static void	deal_key3(int key, t_fract *node)
{
	if (key == 18)
	{
		node->fractal = 1;
		node_values(node);
	}
	else if (key == 19)
	{
		node->fractal = 2;
		node_values(node);
	}
	else if (key == 20)
	{
		node->fractal = 3;
		node_values(node);
	}
	else if (key == 50)
	{
		if (node->rgb == 0)
			node->rgb = 1;
		else
			node->rgb = 0;
	}
}

/*
** numpad: 0: reset, 4682: multiply
*/

static void	deal_key2(int key, t_fract *node)
{
	if (key == 82)
		node_values(node);
	else if (key == 86)
		node->x_mult *= 1.1;
	else if (key == 88)
		node->x_mult *= 0.9;
	else if (key == 91)
		node->y_mult *= 0.9;
	else if (key == 84)
		node->y_mult *= 1.1;
}

/*
** esc: exit, 123: fractal, arrows: move, -+: iterations, space: mouse
*/

static void	deal_key1(int key, t_fract *node)
{
	if (key == 53)
		exit(0);
	else if (key == 123)
		node->move_x -= 20;
	else if (key == 124)
		node->move_x += 20;
	else if (key == 125)
		node->move_y += 20;
	else if (key == 126)
		node->move_y -= 20;
	else if (key == 78)
		node->limit_i -= 1;
	else if (key == 69)
		node->limit_i += 1;
	else if (key == 49)
	{
		if (node->mousemove == 0)
			node->mousemove = 1;
		else
			node->mousemove = 0;
	}
}

int			deal_key(int key, t_fract *node)
{
	deal_key1(key, node);
	deal_key2(key, node);
	deal_key3(key, node);
	refresh(node);
	return (0);
}
