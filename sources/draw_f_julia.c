/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_f_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:03:09 by sgouifer          #+#    #+#             */
/*   Updated: 2019/08/14 19:03:09 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_iters_julia(t_fractol *fractol, double x, double y)
{
	t_complex	c;
	t_complex	z;
	int			i;

	x = (x - fractol->offset_x) / fractol->zoom;
	y = (y - fractol->offset_y) / fractol->zoom;
	c.real = fractol->julia_real;
	c.imag = fractol->julia_imag;
	z.real = x;
	z.imag = y;
	i = 0;
	while (i < fractol->max_iter &&
		((z.real * z.real) + (z.imag * z.imag) < 4))
	{
		z = add_t_complex(power_t_complex(z, fractol->power), c);
		i++;
	}
	return (i);
}
