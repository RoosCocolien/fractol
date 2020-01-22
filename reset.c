/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reset.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 19:34:53 by rsteigen       #+#    #+#                */
/*   Updated: 2020/01/22 11:20:05 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	reset_fractal(t_setup *start)
{
	start->fractal->max_iter = 30;
	start->fractal->zoom = 1;
	start->point->move_x = 0;
	start->point->move_y = 0;
	clear_bit(&start->events, BLACK_AND_WHITE);
	clear_bit(&start->events, RAINBOW);
	start->fractal->x_julia = -0.7;
	start->fractal->y_julia = 0.27015;
	start->point->color_outside = BLACK;
	start->point->color_middle = OLD_PINK;
	start->point->color_inside = LIGHT_BLUE;
}
