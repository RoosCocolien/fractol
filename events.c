/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 11:18:47 by rsteigen       #+#    #+#                */
/*   Updated: 2020/01/16 14:02:32 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int			deal_key(int keycode, t_setup *start)
{
	if (keycode == ESCAPE)
		close_fractol(start);
	if (keycode == SPACE)
	{
		printf("start->events->zoom: %f\n", start->fractal->zoom);
		printf("max_iter: %d\n", start->fractal->max_iter);
		printf("start->fractal->x_julia: %f\n", start->fractal->x_julia);
		printf("start->fractal->y_julia: %f\n", start->fractal->y_julia);
	}
	if (keycode == KEY_Q)
		start->point->color_begin = BLACK;
	if (keycode == KEY_W)
		start->point->color_begin = DARK_RED;
	if (keycode == KEY_E)
		start->point->color_begin = DARK_GREEN;
	if (keycode == KEY_R)
		start->point->color_begin = DARK_BLUE;
	if (keycode == KEY_T)
		start->point->color_begin = DIRTY_YELLOW;
	if (keycode == KEY_Y)
		start->point->color_begin = DARK_PURPLE;
	if (keycode == KEY_U)
		start->point->color_begin = WHITE;
	if (keycode == KEY_1)
		start->point->color_middle = RED;
	if (keycode == KEY_2)
		start->point->color_middle = GREEN;
	if (keycode == KEY_3)
		start->point->color_middle = BLUE;
	if (keycode == KEY_4)
		start->point->color_middle = BLUE_GREEN;
	if (keycode == KEY_5)
		start->point->color_middle = OLD_PINK;
	if (keycode == KEY_6)
		start->point->color_middle = SOFT_GREEN;
	if (keycode == KEY_A)
		start->point->color_end = LIGHT_BLUE;
	if (keycode == KEY_S)
		start->point->color_end = YELLOW;
	if (keycode == KEY_D)
		start->point->color_end = DIRTY_GREEN;
	if (keycode == KEY_F)
		start->point->color_end = PINK;
	if (keycode == KEY_G)
		start->point->color_end = ORANGE;
	if (keycode == KEY_H)
		start->point->color_end = WHITE;
	if (keycode == KEY1_R)
	{
		reset_fractal(start);
		set_bit(&start->events, MANDELBROT);
		clear_bit(&start->events, JULIA);
		clear_bit(&start->events, SHIP);
	}
	if (keycode == KEY2_R)
	{
		reset_fractal(start);
		set_bit(&start->events, JULIA);
		clear_bit(&start->events, MANDELBROT);
		clear_bit(&start->events, SHIP);
	}
	if (keycode == KEY3_R)
	{
		reset_fractal(start);
		set_bit(&start->events, SHIP);
		clear_bit(&start->events, JULIA);
		clear_bit(&start->events, MANDELBROT);
	}
	if (keycode == KEY_LEFT)
	{
		start->point->move_x += (0.1 * start->fractal->zoom);
	}
	if (keycode == KEY_RIGHT)
	{
		start->point->move_x -= (0.1 * start->fractal->zoom);
	}
	if (keycode == KEY_UP)
	{
		start->point->move_y += (0.1 * start->fractal->zoom);
	}
	if (keycode == KEY_DOWN)
	{
		start->point->move_y -= (0.1 * start->fractal->zoom);
	}
	if (keycode == KEY_J)
	{
		if (start->fractal->julia == 0)
		{
			start->fractal->julia++;
			start->fractal->x_julia = 0.407;
			start->fractal->y_julia = -0.178;
		}
		else if (start->fractal->julia == 1)
		{
			start->fractal->julia++;
			start->fractal->x_julia = -1.0;
			start->fractal->y_julia = 0.0;
		}
		else if (start->fractal->julia == 2)
		{
			start->fractal->julia++;
			start->fractal->x_julia = 0.387;
			start->fractal->y_julia = -0.189;
		}
		else if (start->fractal->julia == 3)
		{
			start->fractal->julia++;
			start->fractal->x_julia = 0.377;
			start->fractal->y_julia = -0.208;
		}
		else if (start->fractal->julia == 4)
		{
			start->fractal->julia++;
			start->fractal->x_julia = -0.69;
			start->fractal->y_julia = 0.31;
		}
		else
		{
			start->fractal->julia = 0;
			start->fractal->x_julia = -0.7;
			start->fractal->y_julia = 0.27015;
		}
	}
	if (keycode == KEY_PLUS)
	{
		start->fractal->max_iter++;
	}
	if (keycode == KEY_MINUS)
	{
		start->fractal->max_iter--;
	}
	if (keycode == HOME)
	{
		reset_fractal(start);
	}
	if (keycode == KEY_B)
	{
		clear_bit(&start->events, RAINBOW);
		toggle_bit(&start->events, BLACK_AND_WHITE);
	}
	if (keycode == KEY_P)
	{
		toggle_bit(&start->events, FREEZE);
	}
	if (keycode == STAR)
	{
		clear_bit(&start->events, BLACK_AND_WHITE);
		toggle_bit(&start->events, RAINBOW);
	}
	return (0);
}

int			mouse_press(int button, int x, int y, t_setup *start)
{
	if (x > 0 && y < WIN_WIDTH && y > 0 && y < WIN_HEIGHT)
	{
		if (button == 4)
		{
			start->fractal->zoom *= 1.10;
		}
		if (button == 5)
		{
			start->fractal->zoom *= 0.90;
		}
	}
	return (0);
}

int			mouse_movement(int x, int y, t_setup *start)
{
	if (start->events >> JULIA & 1U && (start->events >> FREEZE & 1U) == 0)
	{
		if (x < WIN_WIDTH && y < WIN_HEIGHT && x > 0 && y > 0)
		{
			start->fractal->x_julia = (x - WIN_WIDTH_HALF) *\
			(4.0 / WIN_WIDTH * start->fractal->zoom) + start->point->move_x;
			start->fractal->y_julia = (y - WIN_WIDTH_HALF) *\
			(4.0 / WIN_WIDTH * start->fractal->zoom) + start->point->move_x;
		}
	}
	return (0);
}

int			expose(t_setup *start)
{
	close_fractol(start);
	return (0);
}
