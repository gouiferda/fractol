/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:03:09 by sgouifer          #+#    #+#             */
/*   Updated: 2019/08/14 19:03:09 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_color_by_iter(t_fractol *fractol, int iterations)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)iterations / (double)fractol->max_iter;
	r = (int)(fractol->r * (1 - t) * t * t * t * 255);
	g = (int)(fractol->g * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(fractol->b * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (r << 16) + (g << 8) + (b);
}

int		get_color_by_depth(t_fractol *fractol, int depth)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)depth / T_DEPTH_MAX;
	r = (int)(fractol->r * (1 - t) * t * t * t * 255);
	g = (int)(fractol->g * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(fractol->b * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (r << 16) + (g << 8) + (b);
}

int		get_color_by_level(t_fractol *fractol, int level)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)level + 5;
	r = (int)(fractol->r * (1 - t) * t * t * t * 255);
	g = (int)(fractol->g * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(fractol->b * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (r << 16) + (g << 8) + (b);
}
