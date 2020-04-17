/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:03:09 by sgouifer          #+#    #+#             */
/*   Updated: 2019/08/14 19:03:09 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"

int		x_hook(void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	free(fractol);
	ft_putendl("fractol:	Ended");
	exit(0);
	return (0);
}

int		mouse_hook_keys(int button, int x, int y, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		zoom(button, fractol);
	if (button == MOUSE_THIRD_BUTTON)
		reset(button, fractol);
	if (button == MOUSE_LEFT_BUTTON)
		mouse_left_click(button, fractol, x, y);
	return (0);
}

int		mouse_hook_move(int x, int y, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	fractol->mouse_x = x;
	fractol->mouse_y = y;
	if (fractol->shape_number == JULIA && !fractol->lock_shape)
		mouse_move_julia(fractol);
	if (fractol->shape_number == TREE && !fractol->lock_shape)
		mouse_move_tree(fractol);
	return (0);
}
