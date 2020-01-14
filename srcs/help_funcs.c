/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:25:28 by rjaakonm          #+#    #+#             */
/*   Updated: 2020/01/14 16:30:34 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "fractol.h"

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
		node->limit_i = 25;
		node->limit_z = 4.0;
		node->move_x = 0;
		node->move_y = 0;
		node->z_r = 0.0;
		node->z_i = 0.0;
	}
}
