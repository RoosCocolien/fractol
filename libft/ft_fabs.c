/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fabs.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 11:24:29 by rsteigen       #+#    #+#                */
/*   Updated: 2020/01/15 11:32:29 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	ft_fabs(long double nb)
{
	t_float	float_nb;

	float_nb.floatnb = nb;
	if (float_nb.float_short[4] >> 15 & 1)
		nb = -nb;
	return (nb);
}
