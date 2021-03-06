/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_f_tricon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:03:09 by sgouifer          #+#    #+#             */
/*   Updated: 2019/08/14 19:03:09 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_iters_tricon(t_fractol *fractol, double x, double y)
{
	t_complex	c;
	t_complex	z;
	t_complex	tmp;
	int			i;

	x = (x - fractol->offset_x) / fractol->zoom;
	y = (y - fractol->offset_y) / fractol->zoom;
	c.real = x;
	c.imag = y;
	z.imag = 0;
	z.real = 0;
	i = 0;
	while (i < fractol->max_iter &&
		((z.real * z.real) + (z.imag * z.imag) < 4))
	{
		tmp.real = z.real * z.real - z.imag * z.imag + x;
		z.imag = -2 * (z.real * z.imag) + y;
		z.real = (tmp.real);
		z = power_t_complex(z, fractol->power - 1);
		i++;
	}
	return (i);
}
