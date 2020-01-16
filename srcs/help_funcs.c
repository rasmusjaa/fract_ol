/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:25:28 by rjaakonm          #+#    #+#             */
/*   Updated: 2020/01/16 10:43:37 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

static void	node_values2(t_fract *node)
{
	if (node->fractal == 2)
	{
		node->r_min = -2.0;
		node->r_max = 2.0;
		node->i_min = -2.0;
		node->i_max = 2.0;
		node->img_width = 1300;
		node->img_height = 1000;
		node->limit_i = 150;
	}
	else if (node->fractal == 3)
	{
		node->r_min = -1.8;
		node->r_max = 1.0;
		node->i_min = 1.5;
		node->i_max = -1.5;
		node->img_width = 1000;
		node->img_height = 1000;
		node->limit_i = 32;
		node->zoom = 10;
		node->move_x = -6200;
		node->move_y = 100;
	}
}

void		node_values(t_fract *node)
{
	node->mousemove = 0;
	node->zoom = 1;
	node->color = 0x000000;
	node->color_x = 1;
	node->move_x = 0;
	node->move_y = 0;
	node->mouse_1 = 0;
	node->mouse_2 = 0;
	node->z_r = 0.0;
	node->z_i = 0.0;
	node->limit_z = 4.0;
	node->rgb = 1;
	if (node->fractal == 1)
	{
		node->r_min = -2.0;
		node->r_max = 1.0;
		node->i_min = -1.5;
		node->i_max = 1.5;
		node->img_width = 1000;
		node->img_height = 1000;
		node->limit_i = 50;
	}
	else
		node_values2(node);
}

void		add_texts(t_fract *node)
{
	mlx_string_put(node->mlx_ptr, node->win_ptr, 1010, 10, 0xffffff,
		"CONTROLS:");
	mlx_string_put(node->mlx_ptr, node->win_ptr, 1010, 30, 0xffffff,
		"PROJECTIONS: 1 2 3");
	mlx_string_put(node->mlx_ptr, node->win_ptr, 1010, 50, 0xffffff,
		"BLACK AND WHITE: ~");
	mlx_string_put(node->mlx_ptr, node->win_ptr, 1010, 70, 0xffffff,
		"UNLOCK TRANSMORPH: Space");
	mlx_string_put(node->mlx_ptr, node->win_ptr, 1010, 90, 0xffffff,
		"MOVE: Arrows / Mouse 1");
	mlx_string_put(node->mlx_ptr, node->win_ptr, 1010, 110, 0xffffff,
		"COLORS: Mouse 2");
	mlx_string_put(node->mlx_ptr, node->win_ptr, 1010, 130, 0xffffff,
		"CHOOSE CENTER: Mouse middle");
	mlx_string_put(node->mlx_ptr, node->win_ptr, 1010, 150, 0xffffff,
		"ZOOM: Mouse scroll");
	mlx_string_put(node->mlx_ptr, node->win_ptr, 1010, 170, 0xffffff,
		"ITERATIONS: Numpad +-");
	mlx_string_put(node->mlx_ptr, node->win_ptr, 1010, 190, 0xffffff,
		"SHAPE: Numpad =/895623");
	mlx_string_put(node->mlx_ptr, node->win_ptr, 1010, 210, 0xffffff,
		"RESET: Numpad 0");
	mlx_string_put(node->mlx_ptr, node->win_ptr, 1010, 230, 0xffffff,
		"EXIT: Esc");
}

void		check_color(int nb, int limit_i, t_fract *node)
{
	double	divided;

	divided = (double)nb / (double)limit_i;
	node->color = divided * 0x00ffff * node->color_x;
	if (node->rgb == 0)
		node->color = (unsigned int)(divided * (float)0x0000ff) * 0x10101;
}

void		refresh(t_fract *node)
{
	mlx_destroy_image(node->mlx_ptr, node->img_ptr);
	node->img_ptr = mlx_new_image(node->mlx_ptr, WINDOW_X, WINDOW_Y);
	mlx_clear_window(node->mlx_ptr, node->win_ptr);
	make_fractal(node);
}
