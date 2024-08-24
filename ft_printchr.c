/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 00:12:17 by pruenrua          #+#    #+#             */
/*   Updated: 2022/09/09 11:56:05 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen_f(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

int	ft_putchar_f(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstring_f(char *str)
{
	int	op_count;

	op_count = 0;
	if (str == NULL)
	{
		op_count += write(1, "(null)", 6);
		return (op_count);
	}
	while (*str)
	{
		op_count += ft_putchar_f(*str);
		str++;
	}
	return (op_count);
}
