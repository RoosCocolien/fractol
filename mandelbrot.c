/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 09:58:25 by rsteigen       #+#    #+#                */
/*   Updated: 2020/01/22 15:46:34 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

static void		pick_color_scheme(t_setup *start)
{
	int color;

	if (start->events >> BLACK_AND_WHITE & 1U)
		draw_fractal_black_white(start, start->point->iterations,\
		start->point->x, start->point->y);
	else if (start->events >> RAINBOW & 1U)
		draw_fractal_rainbow(start, start->point->iterations,\
		start->point->x, start->point->y);
	else
	{
		if (start->point->iterations < start->fractal->max_iter)
		{
			color = pick_color_iterations(start, start->point->iterations,\
			start->fractal->max_iter);
			put_pixel_to_img(start, start->point->x, start->point->y, color);
		}
		else
		{
			put_pixel_to_img(start, start->point->x, start->point->y, BLACK);
		}
	}
}

static void		iterate_differentiation(t_setup *start)
{
	double		x_iter;
	double		y_iter;
	double		sqr_c_real;
	double		sqr_c_ima;

	x_iter = 0;
	y_iter = 0;
	start->point->iterations = 0;
	start->point->c_real = (start->point->x - WIN_WIDTH_HALF) *\
	(start->point->position_x) + start->point->move_x;
	start->point->c_imaginary = (start->point->y - WIN_HEIGHT_HALF) *\
	(start->point->position_y) + start->point->move_y;
	sqr_c_real = x_iter * x_iter;
	sqr_c_ima = y_iter * y_iter;
	while (sqr_c_real + sqr_c_ima <= 4\
	&& start->point->iterations < start->fractal->max_iter)
	{
		y_iter = x_iter * y_iter;
		y_iter += y_iter;
		y_iter += start->point->c_imaginary;
		x_iter = sqr_c_real - sqr_c_ima + start->point->c_real;
		sqr_c_real = x_iter * x_iter;
		sqr_c_ima = y_iter * y_iter;
		start->point->iterations++;
	}
}

void			draw_mandelbrot(t_setup *start)
{
	// start->point->position_x = 4.0 / WIN_WIDTH * start->fractal->zoom;
	// start->point->position_y = 4.0 / WIN_HEIGHT * start->fractal->zoom;
	start->point->y = 0;
	while (start->point->y <= WIN_HEIGHT)
	{
		start->point->x = 0;
		while (start->point->x <= WIN_WIDTH)
		{
			iterate_differentiation(start);
			pick_color_scheme(start);
			start->point->x++;
		}
		start->point->y++;
	}
}
