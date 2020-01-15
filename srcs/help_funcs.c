/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:25:28 by rjaakonm          #+#    #+#             */
/*   Updated: 2020/01/15 18:30:56 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "fractol.h"
#include "mlx.h"
#include <math.h>

int			exit_free(t_fract *node)
{
	free(node);
	exit(0);
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
	if (node->fractal == 1)
	{
		node->r_min = -2.0;
		node->r_max = 1.0;
		node->i_min = -1.5;
		node->i_max = 1.5;
		node->img_width = 1000;
		node->img_height = 1000;
		node->limit_i = 50;
		node->limit_z = 4.0;
		node->move_x = 0;
		node->move_y = 0;
		node->z_r = 0.0;
		node->z_i = 0.0;
	}
	else if (node->fractal == 2)
	{
		node->r_min = -2.0;
		node->r_max = 2.0;
		node->i_min = -2.0;
		node->i_max = 2.0;
		node->img_width = 1300;
		node->img_height = 1000;
		node->limit_i = 150;
		node->limit_z = 4.0;
		node->move_x = 0;
		node->move_y = 0;
		node->z_r = 0.0;
		node->z_i = 0.0;
	}
	else if (node->fractal == 3)
	{
		node->r_min = -2.0;
		node->r_max = 1.0;
		node->i_min = 1.5;
		node->i_max = -0.5;
		node->img_width = 1000;
		node->img_height = 1000;
		node->limit_i = 32;
		node->limit_z = 4.0;
		node->zoom = 10;
		node->move_x = -5900;
		node->move_y = 0;
		node->z_r = 0.0;
		node->z_i = 0.0;
	}
}

void		add_texts(t_fract *node)
{
	mlx_string_put(node->mlx_ptr, node->win_ptr, 10, 10, 0xffffff,
		"CONTROLS:");
	mlx_string_put(node->mlx_ptr, node->win_ptr, 10, 30, 0xffffff,
		"PROJECTIONS: 1 = , 2 = ");
	mlx_string_put(node->mlx_ptr, node->win_ptr, 10, 50, 0xffffff,
		"EXIT: Esc");
}

void		check_color(int nb, int limit_i, t_fract *node)
{
	double	divided;

	divided = (double)nb / (double)limit_i;
   	node->color = divided * 0x00ffff * node->color_x;
}

void		refresh(t_fract *node)
{
	mlx_destroy_image(node->mlx_ptr, node->img_ptr);
	node->img_ptr = mlx_new_image(node->mlx_ptr, WINDOW_X, WINDOW_Y);
	mlx_clear_window(node->mlx_ptr, node->win_ptr);
	make_fractal(node);
}
