/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_funcs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 09:23:17 by rjaakonm          #+#    #+#             */
/*   Updated: 2020/01/16 12:32:40 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

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
