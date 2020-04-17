/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:03:09 by sgouifer          #+#    #+#             */
/*   Updated: 2019/08/16 17:06:49 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	add_t_complex(t_complex n1, t_complex n2)
{
	t_complex	temp;

	temp.real = n1.real + n2.real;
	temp.imag = n1.imag + n2.imag;
	return (temp);
}

t_complex	multiply_t_complex(t_complex n1, t_complex n2)
{
	t_complex	temp;

	temp.real = n1.real * n2.real - n1.imag * n2.imag;
	temp.imag = n1.real * n2.imag + n1.imag * n2.real;
	return (temp);
}

t_complex	power_t_complex(t_complex n1, int power)
{
	t_complex	result;
	int			i;

	i = 0;
	result = n1;
	while (i < power - 1)
	{
		result = multiply_t_complex(n1, result);
		i++;
	}
	return (result);
}
