/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_f_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:03:09 by sgouifer          #+#    #+#             */
/*   Updated: 2019/08/14 19:03:09 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_tree(t_point p1, double ang, int depth, t_fractol *f)
{
	t_point p2;

	if (depth == 0)
		return ;
	p2.x = p1.x + (int)(cos(DEGTORAD(ang)) * depth * (f->zoom / 16));
	p2.y = p1.y + (int)(sin(DEGTORAD(ang)) * depth * (f->zoom / 16));
	draw_line(p1, p2, f, get_color_by_depth(f, depth));
	draw_tree(p2, ang - f->tree_b_angle1, depth - 1, f);
	draw_tree(p2, ang + f->tree_b_angle2, depth - 1, f);
}

void	draw_tree_f(t_fractol *fractol)
{
	double	x_start;
	double	x_finish;
	double	y_finish;
	t_point p1;

	x_start = fractol->offset_x + (fractol->zoom * -2);
	x_finish = fractol->offset_x + (fractol->zoom * 2);
	y_finish = fractol->offset_y + (fractol->zoom * 2);
	p1.x = (x_start + x_finish) / 2;
	p1.y = y_finish;
	if (fractol->to_draw_plane)
		draw_plane(fractol);
	draw_tree(p1, fractol->tree_angle, fractol->tree_depth, fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img_ptr, 0, 0);
}
