/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 12:18:02 by rsteigen       #+#    #+#                */
/*   Updated: 2020/01/06 12:20:29 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

/*
** you need to fine the delta, but in this case, x is delta and y is already
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

int		create_color_for_pixel(t_fractol *start)
{
	t_color		color;

	// printf("color\ttest1\n");
	// printf("color\ttest2\n");
	color.percentage = get_percentage(0, WIN_WIDTH, start->point->x);
	// printf("color\ttest3\n");
	color.start = 0xffffff;
	// printf("color\ttest4\n");
	color.end = start->point->color_end;
	// printf("color\ttest5\n");
	color.red = get_intensity((color.start >> 16) & 0xff, (color.end >> 16) & 0xff, color.percentage);
	// printf("color\ttest6\n");
	color.green = get_intensity((color.start >> 8) & 0xff, (color.end >> 8) & 0xff, color.percentage);
	// printf("color\ttest7\n");
	color.blue = get_intensity(color.start & 0xff, color.end & 0xff, color.percentage);
	// printf("color\ttest8\n");
	start->point->color = (color.red << 16) | (color.green << 8) | (color.blue);
	// printf("color\ttest9\n");
	return (start->point->color);
}
