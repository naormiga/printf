/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexamin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvilla-g <nvilla-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:52:56 by nvilla-g          #+#    #+#             */
/*   Updated: 2022/07/19 19:47:39 by nvilla-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	print_hexamin(unsigned int i, char *base, int *we)
{
	int				tlen;
	unsigned int	digit;

	tlen = 0;
	digit = (i % 16);
	i = i / 16;
	if (i != 0)
		tlen += print_hexamin(i, "0123456789abcdef", we);
	tlen += ft_write(1, &base[digit], 1, we);
	return (tlen);
}

int	ft_ishexamin(unsigned int i, int *we)
{
	int	tlen;

	tlen = 0;
	tlen += print_hexamin(i, "0123456789abcdef", we);
	return (tlen);
}
