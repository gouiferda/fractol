/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defaults.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 11:47:06 by sgouifer          #+#    #+#             */
/*   Updated: 2019/07/28 14:54:23 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFAULTS_H
# define DEFAULTS_H

# define SCREEN_W 750
# define SCREEN_H 750
# define OFFSET_Y_DEFAULT 375
# define OFFSET_X_DEFAULT 375
# define ZOOM_DEFAULT 170
# define MAX_ITER_DEFAULT 34
# define ZOOM_STEPS 10
# define MOVE_STEPS 10
# define ERROR 1
# define EXIT 1
# define SHAPES_COUNT 7
# define MANDELBROT 1
# define MANDELBROT_NAME "mandelbrot"
# define JULIA 2
# define JULIA_NAME "julia"
# define SIERPINSKI 3
# define SIERPINSKI_NAME "sierpinski"
# define TREE 4
# define TREE_NAME "tree"
# define BURNING 5
# define BURNING_NAME "burningship"
# define BARNSLEY 6
# define BARNSLEY_NAME "barnsley"
# define TRICON 7
# define TRICON_NAME "tricon"
# define S_LVL_DEFAULT 1
# define D_PLANE_DEFAULT 0
# define USAGE0 "Usage: \n\t./fractol mandelbrot\n\t./fractol julia\n\t"
# define USAGE1 "./fractol sierpinski\n\t./fractol tree\n\t./fractol "
# define USAGE2 "burningship\n\t./fractol barnsley\n\t./fractol tricon"
# define USAGE ft_strjoin(ft_strjoin(USAGE0,USAGE1),USAGE2)
# define R_DEFAULT 9
# define G_DEFAULT 15
# define B_DEFAULT 8.5
# define D_EASTER_DEFAULT 0
# define SIERPINSKI_COLOR GOLDEN
# define DEGTORAD(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)
# define T_DEPTH_MAX 12
# define T_ANGLE -90
# define T_DEPTH 11
# define T_B_ANGLE -10
# define DRAW_CTRLS_DEFAULT 0
# define DRAW_INFO_DEFAULT 0
# define MENU_WIDTH		330
# define TEXT_COLOR     WHITE

# define BTNS_X	100
# define CONSTROLS_BTN_Y	15
# define INFORMATION_BTN_Y	60
# define PLANE_BTN_Y	105
# define EASTER_BTN_Y	150
# define RESET_BTN_Y	195
# define NEXT_BTN_Y	 100
# define PREV_BTN_Y	55

# define BTN_H	35
# define BTN_W	90

# define BACKGROUND			BLACK
# define MENU_BACKGROUND	GREEN2

# define POWER_DEFAULT 2
# define LOCK_SHAPE_DEFAULT 0

# define BARNSLEY_ITER 500000

#endif
