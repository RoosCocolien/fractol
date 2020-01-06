/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/03 14:27:23 by rsteigen       #+#    #+#                */
/*   Updated: 2020/01/06 13:54:06 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("test0\n");
		if (ft_strcmp(argv[1], "RED") == 0)
			setup(0xff0000);
		else if (ft_strcmp(argv[1], "GREEN") == 0)
			setup(0x00ff00);
		else if (ft_strcmp(argv[1], "BLUE") == 0)
			setup(0x0000ff);
		else
			ft_putstr("Choose: RED, GREEN or BLUE as parameter\n");
	}
	else
	{
		ft_putstr("usage: ./fractol [name fractal]\n");
		ft_putstr(" fractals:\n --> Mandelbrot\n");
	}
	return (0);
}
