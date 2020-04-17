/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_f_sierpinski.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:03:09 by sgouifer          #+#    #+#             */
/*   Updated: 2019/08/14 19:03:09 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_tr(t_point p1, t_point p2, t_point p3, t_fractol *f)
{
	draw_line(p1, p2, f, f->sp_c + 200);
	draw_line(p1, p3, f, f->sp_c);
	draw_line(p2, p3, f, f->sp_c + 100);
}

void	draw_trs(int iters, t_point p, int size, t_fractol *f)
{
	t_point	p1;
	t_point	p2;
	t_point	p3;
	t_point	temp;

	if (iters <= 0)
		return ;
	p1.x = p.x;
	p1.y = p.y;
	p2.x = p.x + (size / 2);
	p2.y = p.y + size;
	p3.x = p.x - (size / 2);
	p3.y = p.y + size;
	draw_tr(p1, p2, p3, f);
	draw_trs(iters - 1, p1, size / 2, f);
	temp.x = p.x - (size / 4) + size / 2;
	temp.y = p.y + (size / 2);
	draw_trs(iters - 1, temp, size / 2, f);
	temp.x = p.x - (size / 4);
	temp.y = p.y + size / 2;
	draw_trs(iters - 1, temp, size / 2, f);
}

void	draw_sierpinski_f(t_fractol *fractol)
{
	double	x_start;
	double	y_start;
	double	x_finish;
	t_point	p1;

	x_start = fractol->offset_x + (fractol->zoom * -2);
	y_start = fractol->offset_y + (fractol->zoom * -2);
	x_finish = fractol->offset_x + (fractol->zoom * 2);
	p1.x = (x_start + x_finish) / 2;
	p1.y = y_start;
	fractol->sp_c = get_color_by_level(fractol, fractol->sp_iters);
	draw_trs(fractol->sp_iters, p1, fractol->zoom * 4, fractol);
	if (fractol->to_draw_plane)
		draw_plane(fractol);
	if (fractol->easter)
		draw_easter_master(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img_ptr, 0, 0);
}
