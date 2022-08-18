/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvilla-g <nvilla-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:57:56 by nvilla-g          #+#    #+#             */
/*   Updated: 2022/07/19 19:47:14 by nvilla-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_ischar(int ch, int *we)
{
	ft_write (1, (char *)&ch, 1, we);
	return (1);
}

int	ft_isstring(char *s, int *we)
{
	int	len;

	len = 0;
	if (!s)
	{
		len = ft_write(1, "(null)", 6, we);
		return (len);
	}
	ft_putstr(s, we);
	len = ft_strlen(s);
	return (len);
}

int	print(char c, int *we)
{
	int	n;

	n = ft_write(1, &c, 1, we);
	return (n);
}

int	ft_putnbr(int nb, int *we)
{
	int	n;

	n = 0;
	if (nb == -2147483648)
	{
		n = ft_write (1, "-2147483648", 11, we);
		if (n == -1)
			return (-1);
		return (n);
	}
	else if (nb < 0)
	{
		n += print('-', we);
		nb = -nb;
		n += ft_putnbr(nb, we);
	}
	else if (nb > 9)
	{
		n += ft_putnbr(nb / 10, we);
		n += ft_putnbr(nb % 10, we);
	}
	else
		n += print(nb + 48, we);
	return (n);
}
