/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 18:30:21 by rjaakonm          #+#    #+#             */
/*   Updated: 2020/01/14 16:54:56 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include "ft_printf.h"

/*
** numpad: / * r_min, 8 9 r_max, 5 6, i_min, 2 3 i_max
*/

static void	deal_key2(int key, t_fract *node)
{
	if (key == 82)
		node_values(node);
	else if (key == 81)
		node->r_min += 0.1;
	else if (key == 75)
		node->r_min -= 0.1;
	else if (key == 91)
		node->r_max += 0.1;
	else if (key == 92)
		node->r_max -= 0.1;
	else if (key == 87)
		node->i_min += 0.1;
	else if (key == 88)
		node->i_min -= 0.1;
	else if (key == 84)
		node->i_max += 0.1;
	else if (key == 85)
		node->i_max -= 0.1;
}

/*
** arrow left right down up: movement, - and +: zoom, space mouse
*/

static void	deal_key1(int key, t_fract *node)
{
	if (key == 53)
		exit (0);
	if (key == 123)
		node->move_x -= 20;
	else if (key == 124)
		node->move_x += 20;
	else if (key == 125)
		node->move_y += 20;
	else if (key == 126)
		node->move_y -= 20;
	else if (key == 78)
		node->zoom *= 0.9;
	else if (key == 69)
		node->zoom *= 1.1;
	else if (key == 49)
	{
		if (node->mousemove == 0)
		{
			node->mouse_x = node->img_width / 2;
			node->mouse_y = node->img_height / 2;
			node->mousemove = 1;
		}
		else
			node->mousemove = 0;
	}
}

int			deal_key(int key, t_fract *node)
{
	ft_printf("key %d\n", key);
	deal_key1(key, node);
	deal_key2(key, node);
	mlx_destroy_image(node->mlx_ptr, node->img_ptr);
	node->img_ptr = mlx_new_image(node->mlx_ptr, WINDOW_X, WINDOW_Y);
	mlx_clear_window(node->mlx_ptr, node->win_ptr);
	make_fractal(node);
	return (0);
}
