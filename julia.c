/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 14:08:57 by rsteigen       #+#    #+#                */
/*   Updated: 2020/01/22 12:38:27 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	draw_julia(t_setup *start)
{
	int		x_pixel;
	int		y_pixel;
	double	x_imaginary;
	double	y_imaginary;
	double	x_iter;
	double	y_iter;
	int		iterations;
//	int		max_iter;
	double	x_new;
	int		color;
//	double	zoom;
//	double	julia_x;
//	double	julia_y;

//	zoom = 1;
	y_pixel = 0;
//	max_iter = 256;
//	julia_x = -0.7; //added
//	julia_y = 0.27015; //added
	//for julia, we need to set c to a certain value
	while (y_pixel <= WIN_HEIGHT)
	{
		x_pixel = 0;
		while (x_pixel <= WIN_WIDTH)
		{
			x_imaginary = (x_pixel - (WIN_WIDTH / 2.0)) * (4.0 / WIN_WIDTH * start->fractal->zoom) + start->point->move_x;
			y_imaginary = (y_pixel - (WIN_HEIGHT / 2.0)) * (4.0 / WIN_HEIGHT * start->fractal->zoom) + start->point->move_y;
			// x_iter = 0;
			// y_iter = 0;
			x_iter = x_imaginary;
			y_iter = y_imaginary;
			iterations = 0;
			while (x_iter * x_iter + y_iter * y_iter <= 4 && iterations < start->fractal->max_iter)
			{
				// x_new = x_iter * x_iter - y_iter * y_iter + x_imaginary;
				x_new = x_iter * x_iter - y_iter * y_iter + start->fractal->x_julia;
				// y_iter = 2.0 * x_iter * y_iter + y_imaginary;
				y_iter = 2.0 * x_iter * y_iter + start->fractal->y_julia;
				x_iter = x_new;
				iterations++;
			}
			if (start->events >> BLACK_AND_WHITE & 1U)
				draw_fractal_black_white(start, iterations, x_pixel, y_pixel);
			else if (start->events >> RAINBOW & 1U)
				draw_fractal_rainbow(start, iterations, x_pixel, y_pixel);
			else
			{
				if (iterations < start->fractal->max_iter)
				{
					color = pick_color_iterations(start, iterations, start->fractal->max_iter);
					put_pixel_to_img(start, x_pixel, y_pixel, color);
				}
				else
				{
					put_pixel_to_img(start, x_pixel, y_pixel, BLACK);
				}	
			}
			x_pixel++;
		}
		y_pixel++;
	}
}
