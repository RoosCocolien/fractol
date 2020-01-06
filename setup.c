/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setup.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/03 14:35:03 by rsteigen       #+#    #+#                */
/*   Updated: 2020/01/06 17:50:36 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int		setup(int picked_color)
{
	t_fractol	*start;
	t_point		cord;
	t_events	event;

	start = (t_fractol*)ft_memalloc(sizeof(t_fractol));
	start->point = &cord;
	start->events = &event;
	set_fractol_to_zero(start);
	start->mlx = mlx_init();
	start->win = mlx_new_window(start->mlx, WIN_WIDTH, WIN_HEIGHT, "FRACTOL");
	start->img = mlx_new_image(start->mlx, WIN_WIDTH, WIN_HEIGHT);
	start->point->color_end = picked_color;
	start->data_addr = mlx_get_data_addr(start->img, &start->bits_per_pixel,\
	&start->size_line, &start->endian);
	mlx_hook(start->win, 4, 1L << 2, mouse_press, start);
	mlx_hook(start->win, 2, 1L << 0, deal_key, start);
	mlx_hook(start->win, 17, 1L << 17, expose, start);
	// printf("demo\tmouse_click_left: %d\n", start->events->mouse_click_left);	
	printf("space: %d\n", start->events->space);
	if (start->events->space == 1)
	{
		int x2 = 160;
		int y2 = 160;
		while (x2 < WIN_WIDTH && y2 < WIN_HEIGHT)
		{
			put_pixel_to_img(start, x2, y2, 0xff0000);
			x2++;
			y2++;
		}
	}
	draw(start);
	printf("SETUP\ttest\n");
	mlx_loop(start->mlx);
	return (0);
}
