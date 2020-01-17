/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_scheme.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 13:44:18 by rsteigen       #+#    #+#                */
/*   Updated: 2020/01/16 15:10:51 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	draw_fractal_black_white(t_setup *start, int iterations, int x, int y)
{
	if (iterations % 2 == 0)
		put_pixel(start, x, y, BLACK);
	else
		put_pixel(start, x, y, WHITE);
}

static double	calculate_percentage(int x, int y)
{
	int		x_dif;
	int		y_dif;
	double	percentage;

	x_dif = WIN_WIDTH_HALF - x;
	y_dif = WIN_HEIGHT_HALF - y;
	ft_fabs(percentage = (double)(x_dif + y_dif) / WIN_WIDTH);
	return (percentage);
}

void	draw_fractal_rainbow(t_setup *start, int iterations, int x, int y)
{
	int		part_iter;
	double	percentage;
	int		color;

	part_iter = iterations % 10;
	percentage = calculate_percentage(x, y);
//	printf("%f\n", percentage);
	if (part_iter == 1)
	{
		color = pick_color(RED, ORANGE, percentage);
		put_pixel(start, x, y, color);
	}
	else if (part_iter == 2)
	{
		color = pick_color(ORANGE, YELLOW, percentage);
		put_pixel(start, x, y, color);
	}
	else if (part_iter == 3)
	{
		color = pick_color(YELLOW, BLUE_GREEN, percentage);
		put_pixel(start, x, y, color);
	}
	else if (part_iter == 4)
	{
		color = pick_color(BLUE_GREEN, LIGHT_BLUE, percentage);
		put_pixel(start, x, y, color);
	}
	else if (part_iter == 5)
	{
		color = pick_color(LIGHT_BLUE, OLD_PINK, percentage);
		put_pixel(start, x, y, color);
	}
	else if (part_iter == 6)
	{
		color = pick_color(OLD_PINK, RED, percentage);
		put_pixel(start, x, y, color);
	}
	else if (part_iter == 7)
	{
		color = pick_color(RED, ORANGE, percentage);
		put_pixel(start, x, y, color);
	}
	else if (part_iter == 8)
	{
		color = pick_color(ORANGE, YELLOW, percentage);
		put_pixel(start, x, y, color);
	}
	else if (part_iter == 9)
	{
		color = pick_color(YELLOW, BLUE_GREEN, percentage);
		put_pixel(start, x, y, color);
	}
	else
	{
		color = pick_color(BLUE_GREEN, DARK_PURPLE, percentage);
		put_pixel(start, x, y, color);
	}
}

