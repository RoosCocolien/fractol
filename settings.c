/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   settings.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 13:56:11 by rsteigen       #+#    #+#                */
/*   Updated: 2020/01/08 17:59:04 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	set_fractol_to_zero(t_fractol *start)
{
	start->point->x = 0;
	start->point->y = 0;
	start->point->color = 0;
	start->point->color_end = 0;
}
