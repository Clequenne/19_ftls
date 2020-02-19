/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clequenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 17:46:56 by clequenn          #+#    #+#             */
/*   Updated: 2019/08/06 19:40:36 by clequenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_usage(void)
{
	ft_putstr_fd("usage: ./ft_l	s [-Raltr] [file ...]\n", 2);
}

void	ft_options_error(int c)
{
	ft_putstr_fd("./ft_ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\n', 2);
	ft_usage();
	exit(EXIT_FAILURE);
}

void	ft_notfound_error(char *filename)
{
	ft_putstr_fd("./ft_ls: ", 2);
	ft_putstr_fd(filename, 2);
	ft_putendl_fd(": No such file or directory", 2);
}

void	ft_mem_error(void)
{
	ft_putstr_fd("Error on memory\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_perm_error(char *filename)
{
	int		i;

	i = ft_strlen(filename) - 1;
	ft_putstr_fd("ft_ls: ", 2);
	if (filename[i] != '/')
	{
		while (filename[i] != '/' && i >= 0)
			i--;
		i++;
		while (filename[i] && filename[i] != '/')
		{
			ft_putchar_fd(filename[i], 2);
			i++;
		}
	}
	ft_putendl_fd(": Permission denied", 2);
}
