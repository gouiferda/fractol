/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:03:09 by sgouifer          #+#    #+#             */
/*   Updated: 2019/08/14 19:03:09 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		adjust_plane_cords(t_fractol *fractol)
{
	fractol->x_start = fractol->offset_x + (fractol->zoom * -2);
	fractol->y_start = fractol->offset_y + (fractol->zoom * -2);
	fractol->x_finish = fractol->offset_x + (fractol->zoom * 2);
	fractol->y_finish = fractol->offset_y + (fractol->zoom * 2);
}

void		df(t_fractol *f, int (*it)(t_fractol *, double, double))
{
	double	x;
	double	y;
	int		iterations;

	adjust_plane_cords(f);
	x = f->x_start;
	y = f->y_start;
	while (x <= f->x_finish)
	{
		y = f->y_start;
		while (y <= f->y_finish)
		{
			iterations = (*it)(f, x, y);
			add_px(f, x, y, get_color_by_iter(f, iterations));
			y++;
		}
		x++;
	}
	if (f->to_draw_plane)
		draw_plane(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img_ptr, 0, 0);
}

void		draw_menu_bg(t_fractol *fractol)
{
	int i;
	int *img;

	img = (int *)(fractol->img_data);
	i = 0;
	while (i < fractol->screen_h * fractol->screen_w)
	{
		if ((i % fractol->screen_w < MENU_WIDTH))
			img[i] = MENU_BACKGROUND;
		i++;
	}
}

void		draw_controls(t_fractol *fractol)
{
	int		y;
	void	*mlx;
	void	*win;
	int		titles_offset;
	int		titles_offset2;

	titles_offset = 20;
	titles_offset2 = 40;
	y = 0;
	mlx = fractol->mlx;
	win = fractol->win;
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img_ptr, 0, 0);
	draw_controls1(fractol, &y, titles_offset, 250);
	draw_controls2(fractol, &y, titles_offset, 250);
	draw_controls3(fractol, &y, titles_offset, 250);
	draw_controls4(fractol, &y, titles_offset, 250);
	draw_controls5(fractol, &y, titles_offset, 250);
	mlx_string_put(mlx, win, 300, 15, BLACK, "X");
	draw_buttons_text(fractol);
}

void		draw_fractol(t_fractol *fractol)
{
	init_draw(fractol);
	if (fractol->shape_number == MANDELBROT)
		df(fractol, get_iters_mandel);
	else if (fractol->shape_number == JULIA)
		df(fractol, get_iters_julia);
	else if (fractol->shape_number == BURNING)
		df(fractol, get_iters_burning);
	else if (fractol->shape_number == TRICON)
		df(fractol, get_iters_tricon);
	else if (fractol->shape_number == SIERPINSKI)
		draw_sierpinski_f(fractol);
	else if (fractol->shape_number == TREE)
		draw_tree_f(fractol);
	else if (fractol->shape_number == BARNSLEY)
		draw_barnsley_f(fractol);
	draw_buttons(fractol);
	if (fractol->to_draw_controls || fractol->to_draw_info)
	{
		draw_menu_bg(fractol);
		draw_square_button(fractol, 290, 10);
	}
	if (fractol->to_draw_controls)
		draw_controls(fractol);
	if (fractol->to_draw_info)
		draw_info(fractol);
}
