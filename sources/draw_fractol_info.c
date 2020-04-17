/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:03:09 by sgouifer          #+#    #+#             */
/*   Updated: 2019/08/14 19:03:09 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_info1(t_fractol *f, int *y_p, int t_o)
{
	void	*mlx;
	void	*win;
	int		y;
	char	res[20];
	float	n;

	n = (float)f->zoom / 170;
	ftoa(n, res, 2);
	y = *y_p;
	mlx = f->mlx;
	win = f->win;
	mlx_string_put(mlx, win, 10, y += 20, GREEN, "Information:");
	mlx_string_put(mlx, win, t_o, y += 30, WHITE, "Fractal number:");
	mlx_string_put(mlx, win, 210, y, GREEN,
		ft_strjoin(ft_strjoin(ft_itoa(f->shape_number), "/"),
			ft_itoa(SHAPES_COUNT)));
	mlx_string_put(mlx, win, t_o, y += 30, WHITE, "Fractal name:");
	mlx_string_put(mlx, win, 210, y, GREEN,
		f->shapes_names[f->shape_number - 1]);
	mlx_string_put(mlx, win, t_o, y += 30, WHITE, "Zoom:");
	mlx_string_put(mlx, win, 210, y, GREEN, ft_strjoin("x", res));
	*y_p = y;
}

void	draw_info2(t_fractol *f, int *y_p, int t_o)
{
	void	*mlx;
	void	*win;
	int		y;

	y = *y_p;
	mlx = f->mlx;
	win = f->win;
	if (f->shape_number == 1 || f->shape_number == 2 ||
		f->shape_number == 7 || f->shape_number == 5)
	{
		mlx_string_put(mlx, win, t_o, y += 30, WHITE, "Max iterations:");
		mlx_string_put(mlx, win, 210, y, GREEN, ft_itoa(f->max_iter));
		mlx_string_put(mlx, win, t_o, y += 30, WHITE, "Multiplicity:");
		mlx_string_put(mlx, win, 210, y, GREEN, ft_itoa(f->power - 1));
	}
	if (f->shape_number == 2)
	{
		mlx_string_put(mlx, win, t_o, y += 30, WHITE, "Julia Constant:");
		mlx_string_put(mlx, win, 210, y, GREEN,
			ft_strjoin(ft_strjoin(ft_itoa(f->julia_real), "+"),
				ft_strjoin(ft_itoa(f->julia_imag), "i")));
	}
	*y_p = y;
}

void	draw_info3(t_fractol *f, int *y_p, int t_o)
{
	void	*mlx;
	void	*win;
	int		y;

	y = *y_p;
	mlx = f->mlx;
	win = f->win;
	if (f->shape_number == 3)
	{
		mlx_string_put(mlx, win, t_o, y += 30, WHITE, "Iterations:");
		mlx_string_put(mlx, win, 210, y, GREEN, ft_itoa(f->sp_iters));
	}
	if (f->shape_number == 4)
	{
		mlx_string_put(mlx, win, t_o, y += 30, WHITE, "Depth:");
		mlx_string_put(mlx, win, 210, y, GREEN, ft_itoa(f->tree_depth));
		mlx_string_put(mlx, win, t_o, y += 30, WHITE, "Angle:");
		mlx_string_put(mlx, win, 210, y, GREEN, ft_itoa(f->tree_angle));
		mlx_string_put(mlx, win, t_o, y += 30, WHITE, "Branch angle 1:");
		mlx_string_put(mlx, win, 210, y, GREEN, ft_itoa(f->tree_b_angle1));
		mlx_string_put(mlx, win, t_o, y += 30, WHITE, "Branch angle 2:");
		mlx_string_put(mlx, win, 210, y, GREEN, ft_itoa(f->tree_b_angle2));
	}
	*y_p = y;
}

void	draw_info4(t_fractol *f, int *y_p, int t_o, int t_o2)
{
	void	*mlx;
	void	*win;
	int		y;

	y = *y_p;
	mlx = f->mlx;
	win = f->win;
	if (f->shape_number != 3 && f->shape_number != 6)
	{
		mlx_string_put(mlx, win, t_o, y += 30, WHITE, "Colors:");
		mlx_string_put(mlx, win, t_o2, y += 30, WHITE, "Red:");
		mlx_string_put(mlx, win, 210, y, GREEN, ft_itoa(f->r));
		mlx_string_put(mlx, win, t_o2, y += 30, WHITE, "Green:");
		mlx_string_put(mlx, win, 210, y, GREEN, ft_itoa(f->g));
		mlx_string_put(mlx, win, t_o2, y += 30, WHITE, "Blue:");
		mlx_string_put(mlx, win, 210, y, GREEN, ft_itoa(f->b));
	}
	if (f->shape_number == 4 || f->shape_number == 2)
	{
		mlx_string_put(mlx, win, t_o, y += 30, WHITE, "Locked:");
		mlx_string_put(mlx, win, 210, y, GREEN, (f->lock_shape) ? "Yes" : "No");
	}
	*y_p = y;
}

void	draw_info(t_fractol *f)
{
	int		y;
	void	*mlx;
	void	*win;
	int		t_o;
	int		titles_offset2;

	t_o = 20;
	titles_offset2 = 40;
	y = 0;
	mlx = f->mlx;
	win = f->win;
	mlx_put_image_to_window(f->mlx, f->win, f->img_ptr, 0, 0);
	draw_info1(f, &y, t_o);
	draw_info2(f, &y, t_o);
	draw_info3(f, &y, t_o);
	if (f->shape_number == 6)
	{
		mlx_string_put(mlx, win, t_o, y += 30, WHITE, "Iterations:");
		mlx_string_put(mlx, win, 210, y, GREEN, ft_itoa(f->barnsley_iter));
	}
	draw_info4(f, &y, t_o, titles_offset2);
	mlx_string_put(mlx, win, 300, 15, BLACK, "X");
	draw_buttons_text(f);
}
