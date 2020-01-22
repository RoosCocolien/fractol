/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 12:18:02 by rsteigen       #+#    #+#                */
/*   Updated: 2020/01/22 14:22:54 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int			get_intensity(int start, int end, double percentage)
{
	int			intensity;
	double		start_intensity;
	double		end_intensity;

	start_intensity = (1.0 - percentage) * start;
	end_intensity = percentage * end;
	intensity = (int)(start_intensity + end_intensity);
	return (intensity);
}

int			pick_color(int start_color, int end_color, double percentage)
{
	int			color_red;
	int			color_green;
	int			color_blue;

	color_red = get_intensity((start_color >> 16) & 0xff,\
	(end_color >> 16) & 0xff, percentage);
	color_green = get_intensity((start_color >> 8) & 0xff,\
	(end_color >> 8) & 0xff, percentage);
	color_blue = get_intensity((start_color) & 0xff,\
	(end_color) & 0xff, percentage);
	return ((color_red << 16) | (color_green << 8) | color_blue);
}

int			pick_color_iterations(t_setup *start, int iterations,\
			int max_iter)
{
	t_color		color;
	double		max_iter_quarter;

	max_iter_quarter = max_iter / 4;
	if (iterations < max_iter_quarter)
	{
		color.start = start->point->color_outside;
		color.end = start->point->color_middle;
		color.percentage = ((double)iterations / max_iter_quarter);
	}
	else
	{
		iterations -= max_iter_quarter;
		color.start = start->point->color_middle;
		color.end = start->point->color_inside;
		color.percentage = ((double)iterations / (max_iter * 0.75f));
	}
	color.red = get_intensity((color.start >> 16) & 0xff,\
	(color.end >> 16) & 0xff, color.percentage);
	color.green = get_intensity((color.start >> 8) & 0xff,\
	(color.end >> 8) & 0xff, color.percentage);
	color.blue = get_intensity(color.start & 0xff,\
	color.end & 0xff, color.percentage);
	return ((color.red << 16) | (color.green << 8) | color.blue);
}
