/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:09:40 by hponcin           #+#    #+#             */
/*   Updated: 2018/11/09 00:36:13 by hponcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int	i;

	if (s1 && s2)
	{
		i = 0;
		while (s1[i] != 0)
		{
			i++;
			if (s1[i] != s2[i])
				return (0);
		}
		return (1);
	}
	return (0);
}
