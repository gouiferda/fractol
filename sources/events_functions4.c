/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_functions4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:03:09 by sgouifer          #+#    #+#             */
/*   Updated: 2019/08/14 19:03:09 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"

void	change_tree(int keycode, t_fractol *f)
{
	double	tree_angle_step;
	double	t_b_a_s;
	int		tree_depth_step;

	tree_angle_step = 10;
	t_b_a_s = 1;
	tree_depth_step = 1;
	if (keycode == KEY_A)
		if (f->tree_depth - tree_depth_step > 0)
			f->tree_depth -= tree_depth_step;
	if (keycode == KEY_Q)
		if (f->tree_depth + tree_depth_step < T_DEPTH_MAX)
			f->tree_depth += tree_depth_step;
	if (keycode == KEY_Z)
		affect_double3(&f->tree_b_angle1, &f->tree_b_angle2, t_b_a_s);
	if (keycode == KEY_X)
		affect_double3(&f->tree_b_angle1, &f->tree_b_angle2, -(t_b_a_s));
	if (keycode == KEY_F)
		f->tree_angle += tree_angle_step;
	if (keycode == KEY_V)
		f->tree_angle -= tree_angle_step;
	draw_fractol(f);
}

void	mouse_move_tree(t_fractol *fractol)
{
	double plane_mouse_x;
	double plane_mouse_y;

	plane_mouse_x = (double)fractol->mouse_x;
	plane_mouse_y = (double)fractol->mouse_y;
	plane_mouse_x -= fractol->offset_x;
	plane_mouse_x /= fractol->zoom;
	plane_mouse_y -= fractol->offset_y;
	plane_mouse_y /= fractol->zoom;
	fractol->tree_b_angle1 = -(double)fractol->mouse_x / 10;
	fractol->tree_b_angle2 = -(double)fractol->mouse_y / 5;
	draw_fractol(fractol);
}
