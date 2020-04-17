/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol_controls.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:03:09 by sgouifer          #+#    #+#             */
/*   Updated: 2019/08/14 19:03:09 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_controls1(t_fractol *f, int *y_p, int t_o, int b_o)
{
	void	*mlx;
	void	*win;
	int		y;

	y = *y_p;
	mlx = f->mlx;
	win = f->win;
	mlx_string_put(mlx, win, 10, y += 20, GREEN, "Controls:");
	mlx_string_put(mlx, win, t_o, y += 30, WHITE, "Show/Hide Controls:");
	mlx_string_put(mlx, win, b_o, y, GREEN, "M");
	mlx_string_put(mlx, win, t_o, y += 30, WHITE, "Show/Hide Information:");
	mlx_string_put(mlx, win, b_o, y, GREEN, "W");
	mlx_string_put(mlx, win, t_o, y += 30, WHITE, "Show/Hide Plane:");
	mlx_string_put(mlx, win, b_o, y, GREEN, "P");
	mlx_string_put(mlx, win, t_o, y += 30, WHITE, "Change Shape:");
	mlx_string_put(mlx, win, b_o, y, GREEN, "< / >");
	mlx_string_put(mlx, win, t_o, y += 30, WHITE, "Zoom:");
	mlx_string_put(mlx, win, b_o, y, GREEN, "+ / -");
	mlx_string_put(mlx, win, t_o, y += 30, WHITE, "Move:");
	mlx_string_put(mlx, win, b_o, y, GREEN, "Arrows");
	*y_p = y;
}

void	draw_controls2(t_fractol *f, int *y_p, int t_o, int b_o)
{
	void	*mlx;
	void	*win;
	int		y;

	y = *y_p;
	mlx = f->mlx;
	win = f->win;
	if (f->shape_number == 1 || f->shape_number == 2 || f->shape_number == 7)
	{
		mlx_string_put(mlx, win, t_o, y += 30, WHITE, "Change Iterations:");
		mlx_string_put(mlx, win, b_o, y, GREEN, "I/L");
		mlx_string_put(mlx, win, t_o, y += 30, WHITE, "Change Multiplicity:");
		mlx_string_put(mlx, win, b_o, y, GREEN, "Y/U");
	}
	if (f->shape_number == 2)
	{
		mlx_string_put(mlx, win, t_o, y += 30, WHITE, "Change constant:");
		mlx_string_put(mlx, win, b_o, y, GREEN, "J/K");
	}
	if (f->shape_number == 4 || f->shape_number == 2)
	{
		mlx_string_put(mlx, win, t_o, y += 30, WHITE, "Toggle lock:");
		mlx_string_put(mlx, win, b_o, y, GREEN, ";");
	}
	*y_p = y;
}

void	draw_controls3(t_fractol *f, int *y_p, int t_o, int b_o)
{
	void	*mlx;
	void	*win;
	int		y;

	y = *y_p;
	mlx = f->mlx;
	win = f->win;
	if (f->shape_number == 3 || f->shape_number == 6)
	{
		mlx_string_put(mlx, win, t_o, y += 30, WHITE, "Change Iterations:");
		mlx_string_put(mlx, win, b_o, y, GREEN, "S/D");
	}
	if (f->shape_number == 4)
	{
		mlx_string_put(mlx, win, t_o, y += 30, WHITE, "Tree:");
		mlx_string_put(mlx, win, 65, y += 30, WHITE, "Depth");
		mlx_string_put(mlx, win, b_o, y, GREEN, "A/Q");
		mlx_string_put(mlx, win, 65, y += 30, WHITE, "Branch angle");
		mlx_string_put(mlx, win, b_o, y, GREEN, "Z/X");
		mlx_string_put(mlx, win, 65, y += 30, WHITE, "Fractal Angle");
		mlx_string_put(mlx, win, b_o, y, GREEN, "F/V");
	}
	*y_p = y;
}

void	draw_controls4(t_fractol *f, int *y_p, int t_o, int b_o)
{
	void	*mlx;
	void	*win;
	int		y;
	int		t_o2;

	t_o2 = t_o * 2;
	y = *y_p;
	mlx = f->mlx;
	win = f->win;
	if (f->shape_number != 3 && f->shape_number != 6)
	{
		mlx_string_put(mlx, win, t_o, y += 30, WHITE, "Colors:");
		mlx_string_put(mlx, win, t_o2, y += 30, WHITE, "Change red:");
		mlx_string_put(mlx, win, b_o, y, GREEN, "R / T");
		mlx_string_put(mlx, win, t_o2, y += 30, WHITE, "Change green:");
		mlx_string_put(mlx, win, b_o, y, GREEN, "G / H");
		mlx_string_put(mlx, win, t_o2, y += 30, WHITE, "Change blue:");
		mlx_string_put(mlx, win, b_o, y, GREEN, "B / N");
		mlx_string_put(mlx, win, t_o, y += 30, WHITE, "Reset colors:");
		mlx_string_put(mlx, win, b_o, y, GREEN, "C");
	}
	*y_p = y;
}

void	draw_controls5(t_fractol *f, int *y_p, int t_o, int b_o)
{
	void	*mlx;
	void	*win;
	int		y;
	int		titles_offset2;

	titles_offset2 = t_o * 2;
	y = *y_p;
	mlx = f->mlx;
	win = f->win;
	if (f->shape_number == 5)
	{
		mlx_string_put(mlx, win, t_o, y += 30, WHITE, "Change Iterations:");
		mlx_string_put(mlx, win, b_o, y, GREEN, "I/L");
	}
	if (f->shape_number == 3)
	{
		mlx_string_put(mlx, win, t_o, y += 30, WHITE, "Easter eggs:");
		mlx_string_put(mlx, win, b_o, y, GREEN, "E");
	}
	mlx_string_put(mlx, win, t_o, y += 30, WHITE, "Reset:");
	mlx_string_put(mlx, win, b_o, y, GREEN, "SPACE");
	mlx_string_put(mlx, win, t_o, y += 30, WHITE, "Exit:");
	mlx_string_put(mlx, win, b_o, y, GREEN, "ESCAPE");
	*y_p = y;
}
