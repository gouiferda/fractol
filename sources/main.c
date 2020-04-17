/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:03:09 by sgouifer          #+#    #+#             */
/*   Updated: 2019/08/14 19:03:09 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_fractol	*fractol;

	if (ac != 2)
		msg(USAGE, 0, EXIT);
	fractol = init_fractol();
	valid_shape_name(av[1], fractol->shapes_names);
	select_shape(av[1], &fractol->shape_number);
	run_fractol(fractol);
	draw_fractol(fractol);
	mlx_hook(fractol->win, 2, 0, keys_hook, fractol);
	mlx_hook(fractol->win, 4, 0, mouse_hook_keys, fractol);
	mlx_hook(fractol->win, 6, 0, mouse_hook_move, fractol);
	mlx_hook(fractol->win, 17, 0, x_hook, fractol);
	ft_putendl("fractol:	Looping");
	mlx_loop(fractol->mlx);
	ft_putendl("fractol:	Finished");
	return (0);
}
