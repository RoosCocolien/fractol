/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setup.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/03 14:35:03 by rsteigen       #+#    #+#                */
/*   Updated: 2020/01/15 16:54:07 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	check_start_fractal(t_setup *start, char *fractal)
{
	if (ft_strcmp(fractal, "Mandelbrot") == 0)
	{
		set_bit(&start->events, MANDELBROT);
	}
	else if (ft_strcmp(fractal, "Julia") == 0)
	{
		set_bit(&start->events, JULIA);
	}
	else
	{
		set_bit(&start->events, SHIP);
	}
}

int		setup(char *fractal_name)
{
	t_setup		*start;
	t_point		cord;
	t_fractal	fractal_info;

	start = (t_setup*)ft_memalloc(sizeof(t_setup));
	start->point = &cord;
	start->fractal = &fractal_info;
	set_setup_to_zero(start);
	start->mlx = mlx_init();
	start->win = mlx_new_window(start->mlx, WIN_WIDTH + 400,\
	WIN_HEIGHT, "FRACTOL");
	start->img = mlx_new_image(start->mlx, WIN_WIDTH, WIN_HEIGHT);
	start->point->color_middle = RED;
	start->point->color_end = YELLOW;
	start->data_addr = mlx_get_data_addr(start->img, &start->bits_per_pixel,\
	&start->size_line, &start->endian);
	check_start_fractal(start, fractal_name);
	mlx_loop_hook(start->mlx, draw, start);
	mlx_loop(start->mlx);
	return (0);
}
