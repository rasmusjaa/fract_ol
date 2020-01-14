/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:16:12 by rjaakonm          #+#    #+#             */
/*   Updated: 2020/01/14 16:27:35 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "ft_printf.h"
#include "fractol.h"

void		make_fractal(t_fract *node)
{
	if(node->fractal == 1)
		make_mandelbrot(node);
	else if(node->fractal == 2)
		make_mandelbrot(node);
	else if(node->fractal == 3)
		make_mandelbrot(node);
}

static void	mlx_stuff(t_fract *node)
{
	node->mlx_ptr = mlx_init();
	node->win_ptr = mlx_new_window(node->mlx_ptr, WINDOW_X, WINDOW_Y, "FRACTOL");
	node_values(node);
	node->img_ptr = mlx_new_image(node->mlx_ptr, WINDOW_X, WINDOW_Y);
	node->data_addr = mlx_get_data_addr(node->img_ptr,
		&node->bpp, &node->size_line, &node->endian);
	node->bpp /= 8;
	make_fractal(node);
	mlx_hook(node->win_ptr, 2, 0, deal_key, node);
	mlx_hook(node->win_ptr, 4, 0, mouse_press, node);
	mlx_hook(node->win_ptr, 5, 0, mouse_release, node);
	mlx_hook(node->win_ptr, 6, 0, mouse_move, node);
	mlx_hook(node->win_ptr, 17, 0, exit_free, node);
	mlx_loop(node->mlx_ptr);
}

static int	choose_fract(char *str, t_fract *node)
{
	if(str[0] == '1' && str[1] == '\0')
	{
		node->fractal = 1;
		return (0);
	}
	if(str[0] == '2' && str[1] == '\0')
	{
		node->fractal = 2;
		return (0);
	}
	if(str[0] == '3' && str[1] == '\0')
	{
		node->fractal = 3;
		return (0);
	}
	else
		return (-1);
}

int			main(int ac, char **av)
{
	t_fract	*node;

	if (!(node = (t_fract *)malloc(sizeof(t_fract))))
		return (1);
	if (ac != 2 || choose_fract(av[1], node) < 0)
	{
		ft_printf("Usage:\n1: Mandelbrot\n2: Julia\n3: Something\n");
		exit_free(node);
	}
	mlx_stuff(node);
	return (0);
}
