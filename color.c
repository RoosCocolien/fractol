/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 12:18:02 by rsteigen       #+#    #+#                */
/*   Updated: 2020/01/07 17:10:05 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

/*
** you need to find the delta, but in this case, x is delta and y is already
** delta because the starting point, or current point is 0,0
** first step: linear, focus on width
*/

double	get_percentage(int start, int end, int current)
{
	double		difference;
	double		distance;

	difference = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	else
		return (difference / distance);
}

int		get_intensity(int start, int end, double percentage)
{
	int		intensity;
	double	start_intensity;
	double	end_intensity;

	start_intensity = (1 - percentage) * start;
	end_intensity = percentage * end;
	intensity = (int)(start_intensity + end_intensity);
	return (intensity);
}

void		create_color_for_pixel(t_fractol *start)
{
	t_color		color;

	color.percentage = get_percentage(0, WIN_WIDTH, start->point->x);
	color.start = 0xffffff;
	color.end = start->point->color_end;
	color.red = get_intensity((color.start >> 16) & 0xff, (color.end >> 16) & 0xff, color.percentage);
	color.green = get_intensity((color.start >> 8) & 0xff, (color.end >> 8) & 0xff, color.percentage);
	color.blue = get_intensity(color.start & 0xff, color.end & 0xff, color.percentage);
	start->point->color = (color.red << 16) | (color.green << 8) | (color.blue);
}
