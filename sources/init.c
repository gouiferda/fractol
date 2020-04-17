/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:03:09 by sgouifer          #+#    #+#             */
/*   Updated: 2019/08/14 19:03:09 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_shapes_names(char **tab)
{
	tab[0] = ft_strdup(MANDELBROT_NAME);
	tab[1] = ft_strdup(JULIA_NAME);
	tab[2] = ft_strdup(SIERPINSKI_NAME);
	tab[3] = ft_strdup(TREE_NAME);
	tab[4] = ft_strdup(BURNING_NAME);
	tab[5] = ft_strdup(BARNSLEY_NAME);
	tab[6] = ft_strdup(TRICON_NAME);
}

void		init_fractol1(t_fractol *fractol)
{
	fractol->zoom = ZOOM_DEFAULT;
	fractol->offset_x = OFFSET_X_DEFAULT;
	fractol->offset_y = OFFSET_Y_DEFAULT;
	fractol->max_iter = MAX_ITER_DEFAULT;
	fractol->mouse_x = 0;
	fractol->mouse_y = 0;
	fractol->julia_imag = -1.09;
	fractol->julia_real = 0.252;
	fractol->sp_iters = S_LVL_DEFAULT;
	fractol->to_draw_plane = D_PLANE_DEFAULT;
	fractol->r = R_DEFAULT;
	fractol->g = G_DEFAULT;
	fractol->b = B_DEFAULT;
	fractol->easter = D_EASTER_DEFAULT;
	fractol->sp_c = SIERPINSKI_COLOR;
	fractol->tree_angle = T_ANGLE;
	fractol->tree_depth = T_DEPTH;
	fractol->tree_b_angle1 = T_B_ANGLE;
	fractol->tree_b_angle2 = T_B_ANGLE;
	fractol->to_draw_controls = DRAW_CTRLS_DEFAULT;
	fractol->to_draw_info = DRAW_INFO_DEFAULT;
	fractol->power = POWER_DEFAULT;
	init_shapes_names(&fractol->shapes_names);
}

void		run_fractol(t_fractol *fractol)
{
	if (!(fractol->win = mlx_new_window(fractol->mlx, fractol->screen_w,
		fractol->screen_h, "Fract'ol v1.0 - @sgouifer")))
		msg("Initializing new window", ERROR, EXIT);
	if (!(fractol->img_ptr = mlx_new_image(fractol->mlx, fractol->screen_w,
		fractol->screen_h)))
		msg("Initializing new image", ERROR, EXIT);
	fractol->img_data = mlx_get_data_addr(fractol->img_ptr, &(fractol->bpp),
		&(fractol->size_line), &(fractol->endian));
}

t_fractol	*init_fractol(void)
{
	t_fractol *fractol;

	if (!(fractol = (t_fractol *)ft_memalloc(sizeof(t_fractol))))
		msg("Allocating fractol", ERROR, EXIT);
	if (!(fractol->mlx = mlx_init()))
		msg("Initializing mlx", ERROR, EXIT);
	fractol->screen_w = SCREEN_W;
	fractol->screen_h = SCREEN_H;
	fractol->lock_shape = LOCK_SHAPE_DEFAULT;
	fractol->x_start = 0;
	fractol->y_start = 0;
	fractol->x_finish = 0;
	fractol->y_finish = 0;
	fractol->barnsley_iter = BARNSLEY_ITER;
	init_fractol1(fractol);
	return (fractol);
}

void		init_draw(t_fractol *fractol)
{
	int i;
	int *img;

	ft_bzero(fractol->img_data,
		fractol->screen_w * fractol->screen_h * (fractol->bpp / 8));
	img = (int *)(fractol->img_data);
	i = 0;
	while (i < fractol->screen_h * fractol->screen_w)
	{
		img[i] = BACKGROUND;
		i++;
	}
}
