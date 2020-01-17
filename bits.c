/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bits.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 11:33:43 by rsteigen       #+#    #+#                */
/*   Updated: 2020/01/16 11:46:15 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"
#include <stdio.h>

void	set_bit(unsigned int *number, int position)
{
	*number |= 1U << position;
}

/*
**	1U stands for an empty unsigned int
**	[00000000 00000000 00000000 00000000]
**	Go to the right position
*/

void	clear_bit(unsigned int *number, int position)
{
	*number &= ~(1U << position);
}

//if it's on it will go off and if it's off it will go on
void	toggle_bit(unsigned int *number, int position)
{
	*number ^= 1U << position;
}

int		check_bit(unsigned int number, int position)
{
	int 			value_bit;

	value_bit = (number >> position) & 1U;
	return (value_bit);
}

void	print_bits(unsigned int nb, int bytes)
{
	unsigned int	i;
	int 			count;

	count = 0;
	i = 1 << (8 * bytes - 1);
	while (i > 0)
	{
		if (count == 8)
		{
			ft_putchar(' ');
			count = 0;
		}
		(nb & i) ? ft_putchar('1') : ft_putchar('0');
		i = i / 2;
		count++;
	}
	ft_putchar('\n');
}
