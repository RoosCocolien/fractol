/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 09:58:25 by rsteigen       #+#    #+#                */
/*   Updated: 2020/01/16 13:56:16 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

//loop through all actual pixels
//define imaginary pixel
//put imaginary pixel through iteration
//if it stays within bound, color actual pixel a certain color
//if it goes out bound, color actual pixel another color

void	draw_mandelbrot(t_setup *start)
{
	int		x_pixel;
	int		y_pixel;
	double	x_imaginary;
	double	y_imaginary;
	double	x_iter;
	double	y_iter;
	int		iterations;
//	int		max_iter;
//	double	x_new;
	int		color;
	double	position_size_x;
	double	position_size_y;
	double	z_real_sqr;
	double	z_ima_sqr;

	position_size_x = 4.0 / WIN_WIDTH * start->fractal->zoom;
	position_size_y = 4.0 / WIN_HEIGHT * start->fractal->zoom;
	y_pixel = 0;
//	max_iter = 100;
	while (y_pixel <= WIN_HEIGHT)
	{
		x_pixel = 0;
		while (x_pixel <= WIN_WIDTH)
		{
			x_imaginary = (x_pixel - WIN_WIDTH_HALF) * (position_size_x) + start->point->move_x;
			y_imaginary = (y_pixel - WIN_HEIGHT_HALF) * (position_size_y)  + start->point->move_y;
			x_iter = 0;
			y_iter = 0;
			z_real_sqr = 0;
			z_ima_sqr = 0;
			// z_real_sqr = x_iter * x_iter;
			// z_ima_sqr = y_iter * y_iter;
			iterations = 0;
			while (z_real_sqr + z_ima_sqr <= 4 && iterations < start->fractal->max_iter)
			{
				y_iter = x_iter * y_iter;
				y_iter += y_iter;
				y_iter += y_imaginary;
				x_iter = z_real_sqr - z_ima_sqr + x_imaginary;
				z_real_sqr = x_iter * x_iter;
				z_ima_sqr = y_iter * y_iter;
				// x_new = x_iter * x_iter - y_iter * y_iter + x_imaginary;
				// y_iter = 2.0 * x_iter * y_iter + y_imaginary;
				// x_iter = x_new;
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
