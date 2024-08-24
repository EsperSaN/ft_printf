/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 00:11:00 by pruenrua          #+#    #+#             */
/*   Updated: 2022/09/09 11:30:48 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	do_percent(char format, va_list argu)
{
	char	*hex;
	char	*b_hex;

	hex = "0123456789abcdef";
	b_hex = "0123456789ABCDEF";
	if (format == 'c')
		return (ft_putchar_f(va_arg(argu, int)));
	else if (format == 's')
		return (ft_putstring_f(va_arg(argu, char *)));
	else if (format == 'p')
		return (ft_nbr_base_u(va_arg(argu, unsigned long), hex, 1));
	else if (format == 'd' || format == 'i')
		return (ft_nbr_base(va_arg(argu, int), "0123456789"));
	else if (format == 'u')
		return (ft_nbr_base_u(va_arg(argu, unsigned int), "0123456789", 0));
	else if (format == 'x')
		return (ft_nbr_base_u(va_arg(argu, unsigned int), hex, 0));
	else if (format == 'X')
		return (ft_nbr_base_u(va_arg(argu, unsigned int), b_hex, 0));
	else if (format == '%')
		return (write(1, "%", 1));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	int			op;
	va_list		argu;

	op = 0;
	i = 0;
	va_start (argu, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			op += do_percent(str[i], argu);
		}
		else
			op += ft_putchar_f(str[i]);
		i++;
	}
	va_end (argu);
	return (op);
}
/*int main()
{
	int i = ft_printf("\n%p\n",16);
	int i2 = printf("\n%p\n",16);
	
	printf("FT = %d and REAL = %d",i,i2);

	printf("\n%d",ft_nbr_base_u(16,"0123456789abcdef",1));
}*/
