/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_functions3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:03:09 by sgouifer          #+#    #+#             */
/*   Updated: 2019/08/14 19:03:09 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"

void	change_fractol(int keycode, t_fractol *fractol)
{
	if (keycode == LEFT_BRACKET)
	{
		if (fractol->shape_number - 1 > 0)
			fractol->shape_number--;
	}
	else if (keycode == RIGHT_BRACKET)
	{
		if (fractol->shape_number < SHAPES_COUNT)
			fractol->shape_number++;
	}
	draw_fractol(fractol);
}

void	show_menu(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_M && !fractol->to_draw_info)
	{
		if (fractol->to_draw_controls == 1)
			fractol->to_draw_controls = 0;
		else if (fractol->to_draw_controls == 0)
			fractol->to_draw_controls = 1;
		draw_fractol(fractol);
	}
}

void	show_info(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_W && !fractol->to_draw_controls)
	{
		if (fractol->to_draw_info == 1)
			fractol->to_draw_info = 0;
		else if (fractol->to_draw_info == 0)
			fractol->to_draw_info = 1;
		draw_fractol(fractol);
	}
}

void	change_easter(int keycode, t_fractol *fractol)
{
	if (fractol->easter == 0)
		fractol->easter = 1;
	else if (fractol->easter == 1)
		fractol->easter = 0;
	draw_fractol(fractol);
}

void	lock_shape(int keycode, t_fractol *fractol)
{
	if (fractol->lock_shape == 0)
		fractol->lock_shape = 1;
	else if (fractol->lock_shape == 1)
		fractol->lock_shape = 0;
	draw_fractol(fractol);
}
