/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 11:15:20 by rsteigen       #+#    #+#                */
/*   Updated: 2020/01/11 12:45:01 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void		put_pixel(t_fractol *start, int x, int y, int color)
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

void	put_pixel_to_img(t_fractol *start, int x, int y, int color)
{
	if (x > 0 && x < WIN_WIDTH && y > 0 && y < WIN_HEIGHT)
	{
		ft_memcpy(&start->data_addr[(4 * y * WIN_WIDTH) + (4 * x)], &color, 4);
	}
}

//loop through all actual pixels
//define imaginary pixel
//put imaginary pixel through iteration
//if it stays within bound, color actual pixel a certain color
//if it goes out bound, color actual pixel another color
void	draw_mandelbrot(t_fractol *start)
{
	int x_pixel;
	int y_pixel;
	double x_imaginary;
	double y_imaginary;

	x_pixel = 0;
	y_pixel = 0;
	while (x_pixel <= WIN_WIDTH && y_pixel <= WIN_HEIGHT)
	{
		x_imaginary = x_pixel - WIN_WIDTH * (6 / WIN_WIDTH);
		y_imaginary = y_pixel - WIN_HEIGHT * (4 /WIN_HEIGHT);
		x_pixel++;
		y_pixel++;
	}
}

int		draw(t_fractol *start)
{
	mlx_hook(start->win, 4, 1L << 2, mouse_press, start);
	mlx_hook(start->win, 5, 1L << 2, mouse_release, start);
	mlx_hook(start->win, 6, 1L << 6, mouse_movement, start);
	mlx_hook(start->win, 2, 1L << 0, deal_key, start);
	mlx_hook(start->win, 17, 1L << 17, expose, start);
	draw_mandelbrot(start);
	mlx_put_image_to_window(start->mlx, start->win, start->img, 0, 0);
	return (0);
}
