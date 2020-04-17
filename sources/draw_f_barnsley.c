/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_f_barnsley.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:03:09 by sgouifer          #+#    #+#             */
/*   Updated: 2019/08/14 19:03:09 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	barnsley_aff(double x, double y, double *xt, double *yt)
{
	double r;

	r = rand() % 100;
	if (r <= 1)
	{
		*xt = 0;
		*yt = 0.16 * y + 0;
	}
	else if (r <= 86)
	{
		*xt = 0.85 * x + 0.04 * y;
		*yt = -0.04 * x + 0.85 * y + 1.60;
	}
	else if (r <= 93)
	{
		*xt = 0.20 * x - 0.26 * y;
		*yt = 0.23 * x + 0.22 * y + 1.60;
	}
	else
	{
		*xt = -0.15 * x + 0.28 * y;
		*yt = 0.26 * x + 0.24 * y + 0.44;
	}
}

void	draw_barnsley_pixels(t_fractol *f, double x, double y)
{
	int m;
	int n;

	m = round(((f->x_start + f->x_finish) / 2) +
		(f->zoom / 4) * x);
	n = ((f->y_finish) - round((f->zoom / 4) * y));
	add_px(f, m, n, GREEN);
}

void	draw_barnsley_f(t_fractol *fractol)
{
	int		i;
	double	xt;
	double	yt;
	double	x;
	double	y;

	x = 0;
	y = 0;
	i = 0;
	adjust_plane_cords(fractol);
	while (i < fractol->barnsley_iter)
	{
		xt = 0;
		yt = 0;
		barnsley_aff(x, y, &xt, &yt);
		x = xt;
		y = yt;
		draw_barnsley_pixels(fractol, x, y);
		i++;
	}
	if (fractol->to_draw_plane)
		draw_plane(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img_ptr, 0, 0);
}
