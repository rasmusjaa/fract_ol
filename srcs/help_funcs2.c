/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_funcs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 09:23:17 by rjaakonm          #+#    #+#             */
/*   Updated: 2020/01/16 10:28:50 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

double	to_real(int x, int img_width, double r_min, double r_max)
{
	double	range;

	range = r_max - r_min;
	return (x * (range / (img_width)) + r_min);
}

double	to_imaginary(int y, int img_height, double i_min, double i_max)
{
	double	range;

	range = i_max - i_min;
	return (y * (range / img_height) + i_min);
}

void	image_set(int x, int y, t_fract *node)
{
	*(int*)(node->data_addr + (((y * WINDOW_X) + x)
		* node->bpp)) = node->color;
}

void	copy_node(t_fract *copy, t_fract *node, int i)
{
	ft_memcpy(copy, node, sizeof(t_fract));
	copy->thread = i;
}

int		exit_free(t_fract *node)
{
	free(node);
	exit(0);
}
