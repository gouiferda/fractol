/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_functions5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:03:09 by sgouifer          #+#    #+#             */
/*   Updated: 2019/08/14 19:03:09 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"

void	switch_shape_btn(int x, int y, t_fractol *f)
{
	if ((x >= f->screen_w - BTNS_X && x <= f->screen_w - BTNS_X + BTN_W) &&
		(y >= f->screen_h - NEXT_BTN_Y
			&& y <= f->screen_h - (NEXT_BTN_Y - BTN_H)))
		change_fractol(RIGHT_BRACKET, f);
	if ((x >= f->screen_w - BTNS_X && x <= f->screen_w - BTNS_X + BTN_W) &&
		(y >= f->screen_h - PREV_BTN_Y
			&& y <= f->screen_h - (PREV_BTN_Y - BTN_H)))
		change_fractol(LEFT_BRACKET, f);
}

void	plane_btn(int x, int y, t_fractol *f)
{
	if ((x >= f->screen_w - BTNS_X && x <= f->screen_w - BTNS_X + BTN_W) &&
		(y >= PLANE_BTN_Y && y <= PLANE_BTN_Y + BTN_H))
		to_draw_plane(KEY_P, f);
}

void	reset_btn(int x, int y, t_fractol *f)
{
	if ((x >= f->screen_w - BTNS_X && x <= f->screen_w - BTNS_X + BTN_W) &&
		(y >= RESET_BTN_Y && y <= RESET_BTN_Y + BTN_H))
		reset(MAIN_PAD_SPACE, f);
}

void	easter_btn(int x, int y, t_fractol *f)
{
	if ((x >= f->screen_w - BTNS_X && x <= f->screen_w - BTNS_X + BTN_W) &&
		(y >= EASTER_BTN_Y && y <= EASTER_BTN_Y + BTN_H))
		change_easter(KEY_E, f);
}

void	mouse_left_click(int button, t_fractol *f, int x, int y)
{
	if (button == MOUSE_LEFT_BUTTON)
	{
		if ((x >= 290 && x <= 290 + BTN_W) && (y >= 10 && y <= 10 + BTN_H))
		{
			f->to_draw_controls = 0;
			f->to_draw_info = 0;
			draw_fractol(f);
		}
		if ((x >= f->screen_w - BTNS_X && x <= f->screen_w - BTNS_X + BTN_W) &&
			(y >= CONSTROLS_BTN_Y && y <= CONSTROLS_BTN_Y + BTN_H))
			show_menu(KEY_M, f);
		if ((x >= f->screen_w - BTNS_X && x <= f->screen_w - BTNS_X + BTN_W) &&
			(y >= INFORMATION_BTN_Y && y <= INFORMATION_BTN_Y + BTN_H))
			show_info(KEY_W, f);
		plane_btn(x, y, f);
		easter_btn(x, y, f);
		reset_btn(x, y, f);
		switch_shape_btn(x, y, f);
	}
}
