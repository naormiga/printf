/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvilla-g <nvilla-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:04:34 by nvilla-g          #+#    #+#             */
/*   Updated: 2022/07/19 19:48:18 by nvilla-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	print_hexa_pointer(unsigned long long i, char *base, int *we)
{
	int	total_lenght;
	int	digit;

	digit = 0;
	total_lenght = 0;
	if (i == 0)
		total_lenght += ft_write(1, "0", 1, we);
	digit = (i % 16);
	i = i / 16;
	if (i != 0)
		total_lenght += print_hexa_pointer(i, "0123456789abcdef", we);
	total_lenght += ft_write(1, &base[digit], 1, we);
	return (total_lenght);
}

int	ft_ispointer(void *p, int *we)
{
	int	tl;

	if (p == NULL)
	{
		tl = ft_write(1, "0x0", 3, we);
		return (tl);
	}
	tl = 0;
	tl = ft_write(1, "0x", 2, we);
	tl += print_hexa_pointer((unsigned long long)p, "0123456789abcdef", we);
	return (tl);
}
