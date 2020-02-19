/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clequenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 17:56:06 by clequenn          #+#    #+#             */
/*   Updated: 2019/08/05 17:57:23 by clequenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_max(int n1, int n2)
{
	return ((n1 > n2) ? (n1) : (n2));
}

int		ft_intlen(int n)
{
	int	size;

	size = 1;
	while (n / 10)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

void	ft_putstr_left(char *str, int size)
{
	int	len;

	len = ft_strlen(str);
	ft_putstr(str);
	while (len < size)
	{
		ft_putchar(' ');
		len++;
	}
}

void	ft_putnbr_right(int nb, int size)
{
	int	len;

	len = ft_intlen(nb);
	while (len < size)
	{
		ft_putchar(' ');
		len++;
	}
	ft_putnbr(nb);
}

void	ft_free(t_file **files)
{
	while (*files)
	{
		free((*files)->filename);
		free(*files);
		*files = (*files)->next;
	}
}
