/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:03:09 by sgouifer          #+#    #+#             */
/*   Updated: 2019/08/14 19:03:09 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	valid_shape_name(char *shape_name, char **tab)
{
	int i;

	i = 0;
	while (i < SHAPES_COUNT)
	{
		if (!ft_strcmp(shape_name, tab[i]))
			return ;
		i++;
	}
	msg(USAGE, 0, EXIT);
}

void	select_shape(char *shape_name, int *shape_number)
{
	if (!ft_strcmp(shape_name, MANDELBROT_NAME))
		*shape_number = 1;
	else if (!ft_strcmp(shape_name, JULIA_NAME))
		*shape_number = 2;
	else if (!ft_strcmp(shape_name, SIERPINSKI_NAME))
		*shape_number = 3;
	else if (!ft_strcmp(shape_name, TREE_NAME))
		*shape_number = 4;
	else if (!ft_strcmp(shape_name, BURNING_NAME))
		*shape_number = 5;
	else if (!ft_strcmp(shape_name, BARNSLEY_NAME))
		*shape_number = 6;
	else if (!ft_strcmp(shape_name, TRICON_NAME))
		*shape_number = 7;
	else
		*shape_number = 1;
}

void	msg(char *msg, int is_error, int to_exit)
{
	if (is_error)
		ft_putstr("Fractol Error: ");
	ft_putendl(msg);
	if (to_exit)
		exit(0);
}
