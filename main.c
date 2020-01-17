/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/03 14:27:23 by rsteigen       #+#    #+#                */
/*   Updated: 2020/01/15 10:43:12 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_strcmp(argv[1], "Mandelbrot") == 0)
			setup(argv[1]);
		else if (ft_strcmp(argv[1], "Julia") == 0)
			setup(argv[1]);
		else if (ft_strcmp(argv[1], "Burning Ship") == 0)
			setup(argv[1]);
		else
			ft_putstr("Choose: \"Mandelbrot\", \"Julia\" or \"Burning Ship\"\n");
	}
	else
	{
		ft_putstr("usage: ./fractol [name fractal]\n");
		ft_putstr(" fractals:\n --> Mandelbrot\n");
	}
	return (0);
}
