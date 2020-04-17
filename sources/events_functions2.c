/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:03:09 by sgouifer          #+#    #+#             */
/*   Updated: 2019/08/14 19:03:09 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"

void	to_draw_plane(int keycode, t_fractol *fractol)
{
	if (fractol->to_draw_plane == 1)
		fractol->to_draw_plane = 0;
	else if (fractol->to_draw_plane == 0)
		fractol->to_draw_plane = 1;
	draw_fractol(fractol);
}

void	reset(int keycode, t_fractol *fractol)
{
	fractol->offset_x = OFFSET_X_DEFAULT;
	fractol->offset_y = OFFSET_Y_DEFAULT;
	fractol->zoom = ZOOM_DEFAULT;
	fractol->max_iter = MAX_ITER_DEFAULT;
	fractol->sp_iters = S_LVL_DEFAULT;
	fractol->to_draw_plane = D_PLANE_DEFAULT;
	fractol->r = R_DEFAULT;
	fractol->g = G_DEFAULT;
	fractol->b = B_DEFAULT;
	fractol->easter = D_EASTER_DEFAULT;
	fractol->sp_c = SIERPINSKI_COLOR;
	fractol->tree_angle = T_ANGLE;
	fractol->tree_depth = T_DEPTH;
	fractol->tree_b_angle1 = T_B_ANGLE;
	fractol->tree_b_angle2 = T_B_ANGLE;
	fractol->power = POWER_DEFAULT;
	fractol->lock_shape = LOCK_SHAPE_DEFAULT;
	fractol->barnsley_iter = BARNSLEY_ITER;
	draw_fractol(fractol);
}

void	julia_change(int keycode, t_fractol *fractol)
{
	double step;

	step = 0.1;
	if (keycode == KEY_J)
	{
		fractol->julia_imag += step;
		fractol->julia_real += step;
	}
	else if (keycode == KEY_K)
	{
		fractol->julia_imag -= step;
		fractol->julia_real -= step;
	}
	draw_fractol(fractol);
}

void	sierpinski_iters(int keycode, t_fractol *fractol)
{
	int step;
	int step2;

	step = 1;
	step2 = 200000;
	if (keycode == KEY_S)
	{
		affect_int(&fractol->sp_iters, step);
		affect_int(&fractol->barnsley_iter, step2);
	}
	if (keycode == KEY_D)
	{
		affect_int(&fractol->sp_iters, -step);
		affect_int(&fractol->barnsley_iter, -step2);
	}
	draw_fractol(fractol);
}

void	multi_fractal(int keycode, t_fractol *fractol)
{
	int step;

	step = 1;
	if (keycode == KEY_Y)
		affect_int(&fractol->power, step);
	if (keycode == KEY_U)
		affect_int(&fractol->power, -step);
	draw_fractol(fractol);
}
