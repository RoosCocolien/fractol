/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 11:15:20 by rsteigen       #+#    #+#                */
/*   Updated: 2020/01/16 13:33:57 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void		put_pixel(t_setup *start, int x, int y, int color)
{
	int		index;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		index = ((int)y * start->size_line) +\
		((int)x * start->bits_per_pixel / 8);
		start->data_addr[index] = color;
		index++;
		start->data_addr[index] = color >> 8;
		index++;
		start->data_addr[index] = color >> 16;
	}
}

void	put_pixel_to_img(t_setup *start, int x, int y, int color)
{
	if (x > 0 && x < WIN_WIDTH && y > 0 && y < WIN_HEIGHT)
		ft_memcpy(&start->data_addr[(4 * y * WIN_WIDTH) + (4 * x)], &color, 4);
}

void	draw_fractal(t_setup *start)
{
	if (start->events >> MANDELBROT & 1U)
		draw_mandelbrot(start);
	else if (start->events >> JULIA & 1U)
		draw_julia(start);
	else
		draw_ship(start);
}

int		draw(t_setup *start)
{
	ft_bzero(start->data_addr, WIN_WIDTH * WIN_HEIGHT * 4);
	mlx_hook(start->win, 4, 1L << 2, mouse_press, start);
	mlx_hook(start->win, 6, 1L << 6, mouse_movement, start);
	mlx_hook(start->win, 2, 1L << 0, deal_key, start);
	mlx_hook(start->win, 17, 1L << 17, expose, start);
	draw_fractal(start);
	mlx_put_image_to_window(start->mlx, start->win, start->img, 0, 0);
	return (0);
}
