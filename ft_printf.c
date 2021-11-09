/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:43:52 by tnard             #+#    #+#             */
/*   Updated: 2021/11/09 16:26:49 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putvalue(const char *str, va_list ap, int i, int t)
{
	unsigned long long	p;

	if (str[i] == 'p')
		p = va_arg(ap, unsigned long long);
	if (str[i] == 'd' || str[i] == 'i')
		t += ft_putnbr(va_arg(ap, int));
	else if (str[i] == 's')
		t += ft_putstr(va_arg(ap, char *));
	else if (str[i] == 'c')
		t += ft_putchar(va_arg(ap, int));
	else if (str[i] == 'p' && !p)
		t += ft_putstr("(nil)");
	else if (str[i] == 'p')
	{
		t += ft_putmemory(&p, "0123456789abcdef");
	}
	else if (str[i] == 'u')
		t += ft_putnbr_u(va_arg(ap, unsigned int));
	else if (str[i] == 'x')
		t += ft_putnbr_base(va_arg(ap, int), "0123456789abcdef");
	else if (str[i] == 'X')
		t += ft_putnbr_base(va_arg(ap, int), "0123456789ABCDEF");
	else if (str[i] == '%')
		t += ft_putchar('%');
	return (t);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		t;

	t = 0;
	va_start(ap, str);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			i++;
			t += ft_putvalue(str, ap, i, 0);
		}
		else
			t += ft_putchar(str[i]);
	}
	va_end(ap);
	return (t);
}
/*
int	main()
{
	ft_printf("ft   : %u %u\n", -1, -9);
	printf("real : %u %u\n", -1, -9);
	return 0;
}
*/