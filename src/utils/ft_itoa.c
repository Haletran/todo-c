/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 23:49:54 by baptiste          #+#    #+#             */
/*   Updated: 2024/05/26 23:52:16 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/todo.h"

static int	negative(int nbr)
{
	if (nbr < 0)
	{
		return (-nbr);
	}
	return (nbr);
}

static int	int_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
	{
		len++;
	}
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	int		tmp;

	len = int_len(n);
	tmp = len;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	if (n < 0)
	{
		result[0] = '-';
	}
	else if (n == 0)
	{
		result[0] = '0';
	}
	while (n != 0)
	{
		--len;
		result[len] = negative(n % 10) + '0';
		n = n / 10;
	}
	result[tmp] = '\0';
	return (result);
}