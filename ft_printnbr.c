/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 00:11:59 by pruenrua          #+#    #+#             */
/*   Updated: 2022/09/09 12:52:03 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_nbr_base(long value, char *base, int base_count)
{
	if (value < 0)
	{
		value = (value * -1);
		ft_putchar_f('-');
	}
	if (value >= base_count)
	{
		ft_put_nbr_base(value / base_count, base, base_count);
		value = value % base_count;
	}
	if (value < base_count)
		ft_putchar_f(base[(value)]);
}

int	ft_nbr_len(long value, int base_count)
{
	int	len;

	len = 0;
	if (value < 0)
	{
		value = (value * -1);
		len++;
	}
	while (value)
	{
		value = value / base_count;
		len++;
	}
	return (len);
}

int	ft_nbr_base(long value, char *base)
{
	int	base_count;

	if (value == 0)
		return (write(1, "0", 1));
	base_count = ft_strlen_f(base);
	ft_put_nbr_base(value, base, base_count);
	return (ft_nbr_len(value, base_count));
}
