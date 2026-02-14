/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <yhachimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:42:07 by yhachimi          #+#    #+#             */
/*   Updated: 2026/02/10 16:08:50 by yhachimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libs/so_long_bonus.h"

static size_t	count_nb(long nb)
{
	size_t	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

static char	*to_ascii(char *p, size_t len, size_t neg, long n)
{
	p[len] = '\0';
	while (len-- > neg)
	{
		p[len] = n % 10 + '0';
		n /= 10;
	}
	if (neg)
		p[0] = '-';
	return (p);
}

char	*ft_itoa(int n)
{
	char	*p;
	size_t	len;
	size_t	neg;
	long	nb;

	neg = 0;
	nb = n;
	len = count_nb(nb);
	if (n < 0)
	{
		neg = 1;
		len += 1;
		nb = -nb;
	}
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	p = to_ascii(p, len, neg, nb);
	return (p);
}
