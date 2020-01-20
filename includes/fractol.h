/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/03 14:10:26 by rsteigen       #+#    #+#                */
/*   Updated: 2020/01/18 13:51:39 by rooscocolie   ########   odam.nl         */
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

# define WIN_WIDTH 600
# define WIN_WIDTH_HALF 300
# define WIN_HEIGHT 600
# define WIN_HEIGHT_HALF 300

/*
** events (toggles)
** flag positions/bit position
*/
# define MOUSE_CLICKED_LEFT 31
# define SPACEBAR 30
# define MANDELBROT 29
# define JULIA 28
# define SHIP 27
# define BLACK_AND_WHITE 26
# define FREEZE 25
# define RAINBOW 24

/*
** colors
*/
# define BLACK 0x0					//dark1
# define DARK_RED 0x1f0000			//dark2
# define DARK_GREEN 0x001f00		//dark3
# define DARK_PURPLE 0x1f001f		//dark4
# define DARK_BLUE 0x00001f			//dark5
# define DIRTY_YELLOW 0x1f1f00		//dark6
# define RED 0xff0000
# define GREEN 0x00ff00
# define BLUE 0x0000ff
# define BLUE_GREEN 0x007f7f
# define OLD_PINK 0xff5ca8
# define SOFT_GREEN 0x98ff5c
# define LIGHT_BLUE 0x00ffff		//light1
# define YELLOW 0xffff00			//light2
# define DIRTY_GREEN 0x80ff00		//light3
# define PINK 0xff0080				//light4
# define ORANGE 0xff8000			//light5
# define WHITE 0xffffff				//light6

/*
**	keys
*/
# define MOUSE_BUTTON_L 1
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define RED_BUTTON 12
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_4 21
# define KEY_5 23
# define KEY_6 22
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_T 17
# define KEY_Y 16
# define KEY_U 32
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_G 5
# define KEY_H 4
# define KEY_B 11
# define KEY_P 35
# define KEY_J 38
# define KEY_PLUS 24
# define KEY_MINUS 27
# define RETURN 36
# define SPACE 49
# define ESCAPE 53
# define ENTER 76
# define KEY1_R 83
# define KEY2_R 84
# define KEY3_R 85
# define KEY4_R 86
# define STAR 67
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define HOME 115

typedef struct		s_fractal
{
	double			x_julia;
	double			y_julia;
	double			zoom;
	int				max_iter;
	int				julia;
}					t_fractal;

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
	int				color_begin;
	int				color_middle;
	int				color_end;
	int				x;
	int				y;
	double			move_x;
	double			move_y;
}					t_point;

typedef struct		s_setup
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
	t_fractal		*fractal;
}					t_setup;

/*
**	start
*/
int				setup(char *fractal_name);

/*
**	events
*/
int				mouse_press(int button, int x, int y, t_setup *start);
int				deal_key(int keycode, t_setup *start);
int				expose(t_setup *start);
int				mouse_movement(int x, int y, t_setup *start);
int				mouse_release(int button, int x, int y, t_setup *start);

/*
**	draw
*/
void			put_pixel_to_img(t_setup *start, int x, int y, int color);
int				draw(t_setup *start);
void			put_pixel(t_setup *start, int x, int y, int color);

/*
**	color
*/
double			get_percentage(int start, int end, int current);
int				get_intensity(int start, int end, double percentage);
void			create_color_for_pixel(t_setup *start);
int				pick_color_iterations(t_setup *start, int iterations,\
				int max_iter);
int				pick_color(int start_color, int end_color, double percentage);
void			draw_fractal_black_white(t_setup *start, int iterations,\
				int x, int y);
void			draw_fractal_rainbow(t_setup *start, int iterations,\
				int x, int y);

/*
**	free && close
*/
void			free_fractol_struct(t_setup *start);
int				close_fractol(t_setup *start);

/*
**	settings
*/
void			set_setup_to_zero(t_setup *start);

/*
**	bits move to library
*/
void			set_bit(unsigned int *number, int position);
void			clear_bit(unsigned int *number, int position);
void			toggle_bit(unsigned int *number, int position);
int				check_bit(unsigned int number, int position);
void			print_bits(unsigned int nb, int bytes);

/*
**	fractals
*/
void			draw_mandelbrot(t_setup *start);
void			draw_ship(t_setup *start);
void			draw_julia(t_setup *start);

/*
**	reset
*/
void			reset_fractal(t_setup *start);

#endif
