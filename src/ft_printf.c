/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvilla-g <nvilla-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:35:58 by nvilla-g          #+#    #+#             */
/*   Updated: 2022/07/19 19:46:33 by nvilla-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_type(va_list args, char ch, int *we)
{
	int	len;

	len = 0;
	if (ch == 'c')
		len = ft_ischar(va_arg(args, int), we);
	if (ch == 's')
		len = ft_isstring(va_arg(args, char *), we);
	if (ch == 'p')
		len = ft_ispointer(va_arg(args, void *), we);
	if (ch == 'i' || ch == 'd')
		len = ft_putnbr(va_arg(args, int), we);
	if (ch == 'u')
		len = ft_isunsigned(va_arg(args, unsigned int), we);
	if (ch == 'x')
		len = ft_ishexamin(va_arg(args, unsigned int), we);
	if (ch == 'X')
		len = ft_ishexamay(va_arg(args, unsigned int), we);
	if (ch == '%')
	{
		len = ft_write(1, "%", 1, we);
	}
	return (len);
}

int	ft_write(int fd, char *c, int nc, int *we)
{
	int	tl;

	tl = 0;
	if (*we == 0)
	{
		tl = write(fd, c, nc);
		if (tl == -1)
		{
			*we = 1;
			return (-1);
		}
	}
	return (tl);
}

int	ft_iter(int *we, char const *s, va_list args)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			total += ft_type(args, s[i + 1], we);
			if (*we == 1)
				return (-1);
			i++;
		}
		else
			total += ft_write (1, (char *)&s[i], 1, we);
		i++;
	}
	return (total);
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		total;
	int		we;

	va_start(args, s);
	total = 0;
	we = 0;
	total = ft_iter(&we, s, args);
	if (we == 1)
		return (-1);
	va_end(args);
	return (total);
}
