/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:03:09 by sgouifer          #+#    #+#             */
/*   Updated: 2019/08/14 19:03:09 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"

void	more_hooks(int keycode, t_fractol *fractol)
{
	if (keycode == MAIN_PAD_ESC)
		x_hook(fractol);
	if (keycode == N_PLUS || keycode == N_MINUS)
		zoom(keycode, fractol);
	if (keycode == KEY_L || keycode == KEY_I)
		iterate(keycode, fractol);
	if (keycode == ARROW_UP || keycode == ARROW_DOWN ||
		keycode == ARROW_LEFT || keycode == ARROW_RIGHT)
		position(keycode, fractol);
	if (keycode == MAIN_PAD_SPACE)
		reset(keycode, fractol);
	if (keycode == KEY_J || keycode == KEY_K)
		julia_change(keycode, fractol);
	if (keycode == KEY_S || keycode == KEY_D)
		sierpinski_iters(keycode, fractol);
	if (keycode == KEY_P)
		to_draw_plane(keycode, fractol);
	if (keycode == KEY_Y || keycode == KEY_U)
		multi_fractal(keycode, fractol);
}

int		keys_hook(int keycode, void *param)
{
	t_fractol *fractol;

	fractol = (t_fractol *)param;
	more_hooks(keycode, fractol);
	if (keycode == KEY_R || keycode == KEY_T || keycode == KEY_G ||
		keycode == KEY_H || keycode == KEY_B || keycode == KEY_N ||
		keycode == KEY_C)
		color(keycode, fractol);
	if (keycode == LEFT_BRACKET || keycode == RIGHT_BRACKET)
		change_fractol(keycode, fractol);
	if (keycode == KEY_E)
		change_easter(keycode, fractol);
	if (keycode == KEY_SEMI)
		lock_shape(keycode, fractol);
	if (keycode == KEY_Q || keycode == KEY_A || keycode == KEY_Z ||
		keycode == KEY_X || keycode == KEY_F || keycode == KEY_V)
		change_tree(keycode, fractol);
	if (keycode == KEY_M)
		show_menu(keycode, fractol);
	if (keycode == KEY_W)
		show_info(keycode, fractol);
	return (0);
}
