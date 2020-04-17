/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 20:46:51 by sgouifer          #+#    #+#             */
/*   Updated: 2019/07/28 20:46:51 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "colors.h"
# include "defaults.h"

typedef	struct		s_complex
{
	double			real;
	double			imag;
}					t_complex;

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
	int				color;
}					t_point;

typedef struct		s_fractol
{
	void			*mlx;
	void			*win;
	double			zoom;
	double			offset_x;
	double			offset_y;
	int				screen_w;
	int				screen_h;
	void			*img_ptr;
	char			*img_data;
	int				size_line;
	int				bpp;
	int				endian;
	int				max_iter;
	int				mouse_x;
	int				mouse_y;
	int				shape_number;
	double			julia_imag;
	double			julia_real;
	int				sp_iters;
	int				to_draw_plane;
	double			r;
	double			g;
	double			b;
	double			easter;
	double			sp_c;
	double			tree_angle;
	int				tree_depth;
	double			tree_b_angle1;
	double			tree_b_angle2;
	char			*shapes_names[SHAPES_COUNT];
	int				to_draw_controls;
	int				to_draw_info;
	double			x_start;
	double			y_start;
	double			x_finish;
	double			y_finish;
	int				power;
	int				lock_shape;
	int				barnsley_iter;
}					t_fractol;

typedef struct		s_draw
{
	double			x_start;
	double			y_start;
	double			x_finish;
	double			y_finish;
	int				color;
	t_fractol		*fractol;
}					t_draw;

/*
** validation_functions.c
*/

void				valid_shape_name(char *shape_name, char **tab);
void				select_shape(char *shape_name, int *shape_number);
void				msg(char *msg, int is_error, int to_exit);

/*
** init.c
*/

void				init_shapes_names(char **tab);
void				init_fractol1(t_fractol *fractol);
void				run_fractol(t_fractol *fractol);
t_fractol			*init_fractol(void);
void				init_draw(t_fractol *fractol);

/*
** draw_pixel.c
*/

t_point				pr_pt(t_fractol *fractol, t_point p);
void				add_px(t_fractol *fractol, double x, double y, int color);
void				set_point(t_point *point, double x, double y);

/*
** draw_line.c
*/

void				draw_line(t_point p1, t_point p2, t_fractol *f, int c);

/*
** draw_bonus.c
*/

void				draw_axis(t_fractol *fractol);
void				draw_plane(t_fractol *fractol);
void				draw_pupil(t_fractol *f, double offset_x, double offset_y);
void				draw_rainbow(t_fractol *fractol);
void				draw_eye(t_fractol *fractol);

/*
** draw_easter.c
*/

void				draw_easter_master(t_fractol *fractol);

/*
** draw_buttons.c
*/

void				draw_buttons_text(t_fractol *fractol);
void				draw_square_button(t_fractol *f, int x_start, int y_start);
void				draw_buttons(t_fractol *fractol);

/*
** draw_f_mandelbrot.c
*/

int					get_iters_mandel(t_fractol *fractol, double x, double y);

/*
** draw_f_julia.c
*/

int					get_iters_julia(t_fractol *fractol, double x, double y);

/*
** draw_f_sierpinski.c
*/

void				draw_tr(t_point p1, t_point p2, t_point p3, t_fractol *f);
void				draw_trs(int iters, t_point p, int size, t_fractol *f);
void				draw_sierpinski_f(t_fractol *fractol);

/*
** draw_f_tree.c
*/

void				draw_tree(t_point p1, double ang, int depth, t_fractol *f);
void				draw_tree_f(t_fractol *fractol);

/*
** draw_f_burning_ship.c
*/

int					get_iters_burning(t_fractol *fractol, double x, double y);

/*
** draw_f_barnsley.c
*/

void				barnsley_aff(double x, double y, double *xt, double *yt);
void				draw_barnsley_pixels(t_fractol *f, double x, double y);
void				draw_barnsley_f(t_fractol *fractol);

/*
** draw_f_tricon.c
*/

int					get_iters_tricon(t_fractol *fractol, double x, double y);

/*
** draw_fractol_controls.c
*/

void				draw_controls1(t_fractol *f, int *y_p, int t_o, int b_o);
void				draw_controls2(t_fractol *f, int *y_p, int t_o, int b_o);
void				draw_controls3(t_fractol *f, int *y_p, int t_o, int b_o);
void				draw_controls4(t_fractol *f, int *y_p, int t_o, int b_o);
void				draw_controls5(t_fractol *f, int *y_p, int t_o, int b_o);

/*
** draw_fractol_info.c
*/

void				draw_info1(t_fractol *f, int *y_p, int t_o);
void				draw_info2(t_fractol *f, int *y_p, int t_o);
void				draw_info3(t_fractol *f, int *y_p, int t_o);
void				draw_info4(t_fractol *f, int *y_p, int t_o, int t_o2);
void				draw_info(t_fractol *fractol);

/*
** draw_fractol.c
*/

void				adjust_plane_cords(t_fractol *fractol);
void				df(t_fractol *f, int (*it)(t_fractol *, double, double));
void				draw_menu_bg(t_fractol *fractol);
void				draw_controls(t_fractol *fractol);
void				draw_fractol(t_fractol *fractol);

/*
** events_functions1.c
*/

void				mouse_move_julia(t_fractol *fractol);
void				position(int keycode, t_fractol *fractol);
void				zoom(int keycode, t_fractol *fractol);
void				iterate(int keycode, t_fractol *fractol);
void				color(int keycode, t_fractol *fractol);

/*
** events_functions2.c
*/

void				to_draw_plane(int keycode, t_fractol *fractol);
void				reset(int keycode, t_fractol *fractol);
void				julia_change(int keycode, t_fractol *fractol);
void				sierpinski_iters(int keycode, t_fractol *fractol);
void				multi_fractal(int keycode, t_fractol *fractol);

/*
** events_functions3.c
*/

void				change_fractol(int keycode, t_fractol *fractol);
void				show_menu(int keycode, t_fractol *fractol);
void				show_info(int keycode, t_fractol *fractol);
void				change_easter(int keycode, t_fractol *fractol);
void				lock_shape(int keycode, t_fractol *fractol);

/*
** events_functions4.c
*/

void				change_tree(int keycode, t_fractol *f);
void				mouse_move_tree(t_fractol *fractol);

/*
** events_functions5.c
*/

void				switch_shape_btn(int x, int y, t_fractol *f);
void				plane_btn(int x, int y, t_fractol *f);
void				reset_btn(int x, int y, t_fractol *f);
void				easter_btn(int x, int y, t_fractol *f);
void				mouse_left_click(int button, t_fractol *f, int x, int y);

/*
** hooks_keys.c
*/

void				more_hooks(int keycode, t_fractol *fractol);
int					keys_hook(int keycode, void *param);

/*
** hooks_mouse.c
*/

int					x_hook(void *param);
int					mouse_hook_keys(int button, int x, int y, void *param);
int					mouse_hook_move(int x, int y, void *param);

/*
** utils_functions1.c
*/

t_complex			add_t_complex(t_complex n1, t_complex n2);
t_complex			multiply_t_complex(t_complex n1, t_complex n2);
t_complex			power_t_complex(t_complex n1, int power);

/*
** utils_functions2.c
*/

void				affect_int(int *x, int val);
void				affect_double(double *x, double val);
void				affect_double2(double *x, double val);
void				affect_double3(double *x, double *y, double val);

/*
** utils_functions3.c
*/

void				reverse(char *str, int len);
int					int_to_str(int x, char str[], int d);
void				ftoa(float n, char *res, int afterpoint);

/*
** colors_functions.c
*/

int					get_color_by_iter(t_fractol *fractol, int iterations);
int					get_color_by_level(t_fractol *fractol, int level);
int					get_color_by_depth(t_fractol *fractol, int depth);

#endif
