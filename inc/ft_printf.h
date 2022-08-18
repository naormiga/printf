/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvilla-g <nvilla-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:37:26 by nvilla-g          #+#    #+#             */
/*   Updated: 2022/07/19 19:52:22 by nvilla-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(char const *s, ...);
int		ft_type(va_list args, char ch, int *we);
int		ft_ischar(int ch, int *we);
int		ft_isstring(char *s, int *we);
int		ft_putnbr(int n, int *we);
int		ft_putchar(int nb);
int		ft_ishexamin(unsigned int i, int *we);
int		ft_ishexamay(unsigned int i, int *we);
int		ft_ispointer(void *p, int *we);
int		ft_putstr(char *str, int *we);
int		ft_write(int fd, char *c, int nc, int *we);
size_t	ft_strlen(const char *s);
int		ft_isunsigned(unsigned int i, int *we);
#endif
