/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/03 14:10:26 by rsteigen       #+#    #+#                */
/*   Updated: 2020/01/08 17:59:16 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"

/*
** include "../minilibx_macos/mlx_new_window.h"
** include "../minilibx_macos/mlx_int.h"
*/

# define WIN_WIDTH 2000
# define WIN_HEIGHT 1200

/*
** events (toggles)
** flag positions
*/
# define MOUSE_CLICKED_LEFT 31
# define SPACEBAR 30

/*
**	keys
*/
# define MOUSE_BUTTON_L 1
# define RETURN 36
# define SPACE 49
# define ESCAPE 53
# define ENTER 76
# define RED_BUTTON 12
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

typedef struct		s_color
{
	int				red;
	int				green;
	int				blue;
	int				start;
	int				end;
	double			percentage;
}					t_color;

typedef struct		s_point
{
	int				color;
	int				color_end;
	int				x;
	int				y;
}					t_point;

typedef struct		s_fractol
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	unsigned int	events;
	t_point			*point;
}					t_fractol;

/*
**	start
*/
int				setup(int parameter);

/*
**	events
*/
int				mouse_press(int button, int x, int y, t_fractol *start);
int				deal_key(int keycode, t_fractol *start);
int				expose(t_fractol *start);
int				mouse_movement(int x, int y, t_fractol *start);
int				mouse_release(int button, int x, int y, t_fractol *start);

/*
**	draw
*/
void			put_pixel_to_img(t_fractol *start, int x, int y, int color);
int				draw(t_fractol *start);
void			put_pixel(t_fractol *start, int x, int y, int color);

/*
**	color
*/
double			get_percentage(int start, int end, int current);
int				get_intensity(int start, int end, double percentage);
void			create_color_for_pixel(t_fractol *start);

/*
**	free && close
*/
void			free_fractol_struct(t_fractol *start);
int				close_fractol(t_fractol *start);

/*
**	settings
*/
void			set_fractol_to_zero(t_fractol *start);

/*
**	bits
*/
void			set_bit(unsigned int *number, int position);
void			clear_bit(unsigned int *number, int position);
void			toggle_bit(unsigned int *number, int position);
int				check_bit(unsigned int number, int position);
void			print_bits(unsigned int nb, int bytes);

#endif
