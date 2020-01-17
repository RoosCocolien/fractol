/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 14:54:01 by rsteigen       #+#    #+#                */
/*   Updated: 2020/01/15 19:44:33 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	free_fractol_struct(t_setup *start)
{
	free(start->mlx);
	free(start->win);
	free(start->img);
	free(start);
}
