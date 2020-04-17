/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:03:09 by sgouifer          #+#    #+#             */
/*   Updated: 2019/08/14 19:03:09 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_axis(t_fractol *fractol)
{
	t_point p0;
	t_point p1;
	t_point p2;
	t_point p3;

	p0.x = -2;
	p0.y = 0;
	p1.x = 2;
	p1.y = 0;
	draw_line(pr_pt(fractol, p0), pr_pt(fractol, p1), fractol, WHITE);
	p2.x = 0;
	p2.y = 2;
	p3.x = 0;
	p3.y = -2;
	draw_line(pr_pt(fractol, p2), pr_pt(fractol, p3), fractol, WHITE);
}

void	draw_plane(t_fractol *fractol)
{
	double	x;
	double	y;
	t_point	point1;
	t_point	point2;

	draw_axis(fractol);
	x = -2;
	y = -2;
	while (x <= 2)
	{
		y = -2;
		while (y <= 2)
		{
			point1.x = x;
			point1.y = y;
			point2 = pr_pt(fractol, point1);
			add_px(fractol, point2.x, point2.y, WHITE);
			y++;
		}
		x++;
	}
}

void	draw_pupil(t_fractol *f, double offset_x, double offset_y)
{
	double r;
	double x;
	double y;

	r = f->zoom / 12;
	x = f->x_start;
	y = f->y_start;
	while (x <= f->x_finish)
	{
		y = f->y_start;
		while (y <= f->y_finish)
		{
			if (r >= sqrt(((x - offset_x) * (x - offset_x))
				+ (y - offset_y) * (y - offset_y)))
				add_px(f, x, y, BLACK);
			y++;
		}
		x++;
	}
}

void	draw_rainbow(t_fractol *fractol)
{
	t_point	p0;
	t_point	p1;
	t_point	p2;
	t_point	p3;
	int		step;

	step = -2;
	set_point(&p0, 0, fractol->screen_h);
	set_point(&p1, -1, 0);
	draw_line(p0, pr_pt(fractol, p1), fractol, WHITE);
	set_point(&p0, 1, 0);
	set_point(&p1, fractol->screen_w, fractol->screen_h);
	draw_line(pr_pt(fractol, p0), p1, fractol, RED1);
	p1.y += step;
	draw_line(pr_pt(fractol, p0), p1, fractol, ORANGE);
	p1.y += step;
	draw_line(pr_pt(fractol, p0), p1, fractol, YELLOW);
	p1.y += step;
	draw_line(pr_pt(fractol, p0), p1, fractol, GREEN);
	p1.y += step;
	draw_line(pr_pt(fractol, p0), p1, fractol, AQUA);
	p1.y += step;
	draw_line(pr_pt(fractol, p0), p1, fractol, BLUE1);
	p1.y += step;
	draw_line(pr_pt(fractol, p0), p1, fractol, PURPLE);
}

void	draw_eye(t_fractol *fractol)
{
	double x;
	double y;
	double offset_x;
	double offset_y;

	offset_x = fractol->offset_x;
	offset_y = fractol->offset_y - (fractol->zoom * 0.7);
	adjust_plane_cords(fractol);
	x = fractol->x_start;
	y = fractol->y_start;
	while (x <= fractol->x_finish)
	{
		y = fractol->y_start;
		while (y <= fractol->y_finish)
		{
			if (fractol->zoom / 6 >= sqrt(((x - offset_x) * (x - offset_x))
				+ (y - offset_y) * (y - offset_y)))
				add_px(fractol, x, y, WHITE);
			y++;
		}
		x++;
	}
	draw_pupil(fractol, offset_x, offset_y);
	draw_rainbow(fractol);
}
