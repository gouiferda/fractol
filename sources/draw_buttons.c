/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_buttons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:03:09 by sgouifer          #+#    #+#             */
/*   Updated: 2019/08/14 19:03:09 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_buttons_text(t_fractol *fractol)
{
	int		y;
	void	*mlx;
	void	*win;

	mlx = fractol->mlx;
	win = fractol->win;
	mlx_string_put(mlx, win, fractol->screen_w - BTNS_X + 5,
		CONSTROLS_BTN_Y + 5, BLACK, "CONTROLS");
	mlx_string_put(mlx, win, fractol->screen_w - BTNS_X + 22,
		INFORMATION_BTN_Y + 5, BLACK, "INFO");
	mlx_string_put(mlx, win, fractol->screen_w - BTNS_X + 18, PLANE_BTN_Y + 5,
		BLACK, "PLANE");
	if (fractol->shape_number == 3)
		mlx_string_put(mlx, win, fractol->screen_w - BTNS_X + 14,
			EASTER_BTN_Y + 5, BLACK, "EASTER");
	mlx_string_put(mlx, win, fractol->screen_w - BTNS_X + 18, RESET_BTN_Y + 5,
		BLACK, "RESET");
	if (fractol->shape_number < SHAPES_COUNT)
		mlx_string_put(mlx, win, fractol->screen_w - BTNS_X + 18,
			fractol->screen_h - NEXT_BTN_Y + 5, BLACK, "NEXT >");
	if (fractol->shape_number != 1)
		mlx_string_put(mlx, win, fractol->screen_w - BTNS_X + 10,
			fractol->screen_h - PREV_BTN_Y + 5, BLACK, "< PREV");
}

void	draw_square_button(t_fractol *f, int x_start, int y_start)
{
	int x;
	int y;
	int color;

	color = GREEN;
	x = x_start;
	y = y_start;
	while (x < x_start + BTN_W)
	{
		y = y_start;
		while (y < y_start + BTN_H)
		{
			add_px(f, x, y, color);
			y++;
		}
		x++;
	}
}

void	draw_buttons(t_fractol *fractol)
{
	int size;
	int x;
	int y;

	x = fractol->screen_w - 50;
	y = 10;
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img_ptr, 0, 0);
	draw_square_button(fractol, fractol->screen_w - BTNS_X,
		CONSTROLS_BTN_Y);
	draw_square_button(fractol, fractol->screen_w - BTNS_X, INFORMATION_BTN_Y);
	draw_square_button(fractol, fractol->screen_w - BTNS_X, PLANE_BTN_Y);
	if (fractol->shape_number == 3)
		draw_square_button(fractol, fractol->screen_w - BTNS_X, EASTER_BTN_Y);
	draw_square_button(fractol, fractol->screen_w - BTNS_X, RESET_BTN_Y);
	if (fractol->shape_number < SHAPES_COUNT)
		draw_square_button(fractol, fractol->screen_w - BTNS_X,
			fractol->screen_h - NEXT_BTN_Y);
	if (fractol->shape_number != 1)
		draw_square_button(fractol, fractol->screen_w - BTNS_X,
			fractol->screen_h - PREV_BTN_Y);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img_ptr, 0, 0);
	draw_buttons_text(fractol);
}
