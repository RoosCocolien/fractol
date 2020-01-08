/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setup.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/03 14:35:03 by rsteigen       #+#    #+#                */
/*   Updated: 2020/01/08 18:36:10 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int		setup(int picked_color)
{
	t_fractol	*start;
	t_point		cord;

	start = (t_fractol*)ft_memalloc(sizeof(t_fractol));
	start->point = &cord;
	set_fractol_to_zero(start);
	start->mlx = mlx_init();
	start->win = mlx_new_window(start->mlx, WIN_WIDTH, WIN_HEIGHT, "FRACTOL");
	start->img = mlx_new_image(start->mlx, WIN_WIDTH, WIN_HEIGHT);
	start->point->color_end = picked_color;
	start->data_addr = mlx_get_data_addr(start->img, &start->bits_per_pixel,\
	&start->size_line, &start->endian);
	mlx_loop_hook(start->mlx, draw, start);
	mlx_loop(start->mlx);
	return (0);
}
