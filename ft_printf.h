/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:01:21 by pruenrua          #+#    #+#             */
/*   Updated: 2022/09/09 12:55:25 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_strlen_f(char *str);
int		ft_putchar_f(int c);
int		ft_putstring_f(char *str);
int		ft_nbr_base(long value, char *base);
int		ft_nbr_base_u(unsigned long value, char *base, int mode);
void	ft_put_nbr_base_u(unsigned long value, char *base, unsigned long bc);
int		ft_nbr_len_u(unsigned long value, unsigned long base_count);
int		ft_nbr_len(long value, int base_count);
void	ft_put_nbr_base(long value, char *base, int base_count);

#endif
