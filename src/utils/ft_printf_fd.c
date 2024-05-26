/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 23:55:41 by baptiste          #+#    #+#             */
/*   Updated: 2024/05/27 00:36:25 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/todo.h"
# include <stdarg.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_printf_fd(int fd, const char *format, ...)
{
	int		len;
	int		i;
	va_list	pointer;

	len = 0;
	i = 0;
	va_start(pointer, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
				ft_putstr_fd(fd, va_arg(pointer, char *));
			else if (format[i] == 'd')
				ft_putnbr_fd(va_arg(pointer, int), fd);
			else if (format[i] == 'c')
				ft_putchar_fd(va_arg(pointer, int), 1);
		}
		else
			write(fd, &format[i], 1);
		i++;
	}
	va_end(pointer);
	return (len);
}