/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_functions1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:03:09 by sgouifer          #+#    #+#             */
/*   Updated: 2019/08/14 19:03:09 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"

void	mouse_move_julia(t_fractol *fractol)
{
	double plane_mouse_x;
	double plane_mouse_y;

	plane_mouse_x = (double)fractol->mouse_x;
	plane_mouse_y = (double)fractol->mouse_y;
	plane_mouse_x -= fractol->offset_x;
	plane_mouse_x /= fractol->zoom;
	plane_mouse_y -= fractol->offset_y;
	plane_mouse_y /= fractol->zoom;
	fractol->julia_real = plane_mouse_x;
	fractol->julia_imag = plane_mouse_y;
	draw_fractol(fractol);
}

void	position(int keycode, t_fractol *fractol)
{
	if (keycode == ARROW_LEFT)
		affect_double2(&fractol->offset_x, MOVE_STEPS);
	else if (keycode == ARROW_RIGHT)
		affect_double2(&fractol->offset_x, -MOVE_STEPS);
	else if (keycode == ARROW_UP)
		affect_double2(&fractol->offset_y, MOVE_STEPS);
	else if (keycode == ARROW_DOWN)
		affect_double2(&fractol->offset_y, -MOVE_STEPS);
	draw_fractol(fractol);
}

void	zoom(int keycode, t_fractol *fractol)
{
	if (keycode == MOUSE_SCROLL_UP)
	{
		affect_double(&fractol->zoom, ZOOM_STEPS);
	}
	else if (keycode == MOUSE_SCROLL_DOWN)
	{
		affect_double(&fractol->zoom, -ZOOM_STEPS);
	}
	if (keycode == N_PLUS)
	{
		affect_double(&fractol->zoom, ZOOM_STEPS);
	}
	else if (keycode == N_MINUS)
	{
		affect_double(&fractol->zoom, -ZOOM_STEPS);
	}
	draw_fractol(fractol);
}

void	iterate(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_I)
	{
		affect_int2(&fractol->max_iter, 1);
	}
	else if (keycode == KEY_L)
	{
		if (fractol->max_iter - 1 > 0)
			affect_int2(&fractol->max_iter, -1);
	}
	draw_fractol(fractol);
}

void	color(int keycode, t_fractol *fractol)
{
	int color_steps;

	color_steps = 1;
	if (keycode == KEY_R)
		affect_double(&fractol->r, color_steps);
	else if (keycode == KEY_T)
		affect_double(&fractol->r, -color_steps);
	else if (keycode == KEY_G)
		affect_double(&fractol->g, color_steps);
	else if (keycode == KEY_H)
		affect_double(&fractol->g, -color_steps);
	else if (keycode == KEY_B)
		affect_double(&fractol->b, color_steps);
	else if (keycode == KEY_N)
		affect_double(&fractol->b, -color_steps);
	else if (keycode == KEY_C)
	{
		fractol->r = R_DEFAULT;
		fractol->g = G_DEFAULT;
		fractol->b = B_DEFAULT;
	}
	draw_fractol(fractol);
}
