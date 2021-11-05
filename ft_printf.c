/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:43:52 by tnard             #+#    #+#             */
/*   Updated: 2021/11/05 16:58:15 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	int			i;
	int			t;

	t = 0;
	va_start(ap, str);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			/* 
				TODO : 
					• %p L’argument de pointeur void * est imprimé en hexadécimal.
			*/
			i++; 
			if (str[i] == 'd' || str[i] == 'i')
				t += ft_putnbr(va_arg(ap, int));
			else if (str[i] == 's')
				t += ft_putstr(va_arg(ap, char *));
			else if (str[i] == 'c')
				t += ft_putchar(va_arg(ap, int));
			else if (str[i] == 'p')
			{
				unsigned long long test = va_arg(ap, unsigned long long);
				t += ft_putmemory(&test, "0123456789abcdef");//ft_putnbr_base((int)va_arg(ap, void *), 1);//hexa ici
			}
			else if (str[i] == 'u')
				t += ft_putnbr(va_arg(ap, unsigned int));
			else if (str[i] == 'x')
				t += ft_putnbr_base(va_arg(ap, int), "0123456789abcdef");
			else if (str[i] == '%')
				t += ft_putchar('%');
		}
		else
			t += ft_putchar(str[i]);
	}
	va_end(ap);
	return (t);
}

int main()
{
	void *test;
	ft_printf("%p\n", &test);
	printf("%p", &test);
}
