/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexamay.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvilla-g <nvilla-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:54:07 by nvilla-g          #+#    #+#             */
/*   Updated: 2022/07/19 19:47:54 by nvilla-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	print_hexamay(unsigned int i, char *base, int *we)
{
	int	tlen;
	int	digit;

	tlen = 0;
	digit = (i % 16);
	i = i / 16;
	if (i != 0)
		tlen += print_hexamay(i, "0123456789ABCDEF", we);
	tlen += ft_write(1, &base[digit], 1, we);
	return (tlen);
}

int	ft_ishexamay(unsigned int i, int *we)
{
	int	tlen;

	tlen = 0;
	tlen += print_hexamay(i, "0123456789ABCDEF", we);
	return (tlen);
}
