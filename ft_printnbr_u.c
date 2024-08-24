/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 10:55:21 by pruenrua          #+#    #+#             */
/*   Updated: 2022/09/09 12:54:19 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbr_len_u(unsigned long value, unsigned long base_count)
{
	int	len;

	len = 0;
	while (value)
	{
		value = value / base_count;
		len++;
	}
	return (len);
}

void	ft_put_nbr_base_u(unsigned long value, char *base, unsigned long bc)
{
	if (value >= bc)
	{
		ft_put_nbr_base_u((value / bc), base, bc);
		value = value % bc;
	}
	if (value < bc)
		ft_putchar_f(base[value]);
}

int	ft_nbr_base_u(unsigned long value, char *base, int mode)
{
	unsigned long	base_count;
	int				add;

	add = 0;
	if (mode == 1)
		add += write(1, "0x", 2);
	if (value == 0)
		return (write(1, "0", 1) + add);
	base_count = ft_strlen_f(base);
	ft_put_nbr_base_u(value, base, base_count);
	return (ft_nbr_len_u(value, base_count) + add);
}
