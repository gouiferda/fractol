/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:03:09 by sgouifer          #+#    #+#             */
/*   Updated: 2019/08/14 19:03:09 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_point		pr_pt(t_fractol *fractol, t_point p)
{
	p.y = p.y * -1;
	p.x *= fractol->zoom;
	p.y *= fractol->zoom;
	p.z *= fractol->zoom;
	p.x += fractol->offset_x;
	p.y += fractol->offset_y;
	return (p);
}

void		add_px(t_fractol *fractol, double x, double y, int color)
{
	int		i;

	if (x > 0 && y > 0 && x < fractol->screen_w && y < fractol->screen_h)
	{
		i = (x * fractol->bpp / 8) + (y * fractol->size_line);
		fractol->img_data[i] = color;
		fractol->img_data[++i] = color >> 8;
		fractol->img_data[++i] = color >> 16;
	}
}

void		set_point(t_point *point, double x, double y)
{
	point->x = x;
	point->y = y;
}
