/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 11:18:47 by rsteigen       #+#    #+#                */
/*   Updated: 2020/01/06 14:29:40 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int			deal_key(int keycode, t_fractol *start)
{
	if (keycode == ESCAPE)
		close_fractol(start);
	if (keycode == SPACE)
		start->events->space = 1;
	return (0);
}

int			mouse_press(int button, int x, int y, t_fractol *start)
{
	// printf("mouse_press\ttest1\n");
	start->point->x = x;
	start->point->y = y;
	// printf("events\nx: %d\ny: %d\n", x, y);
	// printf("mouse_press\ttest2\n");
	create_color_for_pixel(start);
	// printf("mouse_press\ttest3\n");
	printf("color\tcolor: %#x\n", start->point->color);
	printf("x: %d\ny: %d\n", x, y);
	if (x > 0 && x < WIN_WIDTH && y > 0 && y < WIN_HEIGHT)
	{
		// printf("mouse_press\ttest4\n");
		if (button == MOUSE_CLICK_LEFT)
		{
			printf("mouse_press\ttest5\n");
			put_pixel_to_img(start, x, y, start->point->color);
			// start->events->mouse_click_left = 1;
		}
		printf("1mouse_press\tmouse_click_left: %d\n", start->events->mouse_click_left);
	}
	printf("2mouse_press\tmouse_click_left: %d\n", start->events->mouse_click_left);
	return (0);
}

int		expose(t_fractol *start)
{
	close_fractol(start);
	return (0);
}
