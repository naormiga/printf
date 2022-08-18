/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvilla-g <nvilla-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:13:03 by nvilla-g          #+#    #+#             */
/*   Updated: 2022/07/19 17:55:36 by nvilla-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_isunsigned(unsigned int i, int *we)
{
	int		tlen;
	char	c;

	c = 0;
	tlen = 0;
	if (i >= 10)
	{
		tlen += ft_isunsigned(i / 10, we);
		tlen += ft_isunsigned(i % 10, we);
	}
	else
	{
		c = i + 48;
		tlen += ft_write(1, &c, 1, we);
	}
	return (tlen);
}
