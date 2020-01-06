/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 11:15:20 by rsteigen       #+#    #+#                */
/*   Updated: 2020/01/06 14:38:44 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	put_pixel_to_img(t_fractol *start, int x, int y, int color)
{
	if (x > 0 && x < WIN_WIDTH && y > 0 && y < WIN_HEIGHT)
	{
		printf("PUT PIXEL TO IMG\nx: %d\ny: %d\ncolor: %#x\n", x, y, color);
		ft_memcpy(&start->data_addr[(4 * y * WIN_WIDTH) + (4 * x)], &color, 4);
	}
}

void	draw(t_fractol *start)
{
	printf("check\n");
	if (start->events->space == 1)
	{
		printf("CHECK\n");
		int x = 0;
		int y = 0;
		while (x < 150 && y < 150)
		{
			put_pixel_to_img(start, x, y, 0xff0000);
			x++;
			y++;
		}
		start->events->space = 0;
	}
	mlx_put_image_to_window(start->mlx, start->win, start->img, 0, 0);
}
