/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   settings.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 13:56:11 by rsteigen       #+#    #+#                */
/*   Updated: 2020/01/22 15:29:35 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"


//SET EVERYTHING YOU USE TO ZERO
void	set_setup_to_zero(t_setup *start)
{
	start->point->x = 0;
	start->point->y = 0;
	start->point->color = 0;
	start->point->color_outside = 0;
	start->point->color_middle = 0;
	start->point->color_inside = 0;
	start->point->move_x = 0;
	start->point->move_y = 0;
	start->fractal->x_julia = -0.7;
	start->fractal->y_julia = 0.27015;
	start->fractal->zoom = 1;
	start->fractal->max_iter = 30;
	start->fractal->julia = 0;
}
