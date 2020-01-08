/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   close.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 16:48:36 by rsteigen       #+#    #+#                */
/*   Updated: 2020/01/07 17:09:08 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int		close_fractol(t_fractol *start)
{
	free_fractol_struct(start);
	exit(0);
}
