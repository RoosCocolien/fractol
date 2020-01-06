/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   close.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 16:48:36 by rsteigen       #+#    #+#                */
/*   Updated: 2020/01/06 12:29:38 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int		close_fractol(t_fractol *start)
{
	printf("ESCAPE\ncolor: %#x\n", start->point->color_end);
	free_fractol_struct(start);
	exit(0);
}
