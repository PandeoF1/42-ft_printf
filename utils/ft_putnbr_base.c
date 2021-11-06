/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:10:41 by tnard             #+#    #+#             */
/*   Updated: 2021/11/05 17:24:25 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_check_base(char *base, char c)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (base[n])
		if (base[n++] == c)
			i++;
	if (i >= 2)
		return (0);
	return (1);
}

static int	ft_strprint(unsigned int n, char *base, unsigned int size)
{
	int	t;

	t = 0;
	if (n > size - 1)
	{
		t += ft_strprint(n / size, base, size);
		n %= size;
	}
	ft_putchar(base[n]);
	t++;
	return (t);
}

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	int	n;
	int	t;

	t = 0;
	n = 0;
	while (base[n])
	{
		if ((base[n] == '-' || base[n] == '+' || !ft_check_base(base, base[n])))
			return (t);
		n++;
	}
	if (n < 2)
		return (t);
	if (nbr < 0)
	{
		ft_putchar('-');
		t += ft_strprint(-nbr, base, n);
	}
	else
	{
		t += ft_strprint(nbr, base, n);
	}
	return (t);
}
