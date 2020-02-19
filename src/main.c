/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clequenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 19:20:00 by clequenn          #+#    #+#             */
/*   Updated: 2019/08/05 19:21:56 by clequenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_options_index(int c, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (-1);
}

void		ft_options(char *str, int *options)
{
	int	i;
	int index;

	i = 0;
	while (str[++i])
	{
		if ((index = ft_options_index(str[i], "Ralrt")) < 0)
			ft_options_error(str[i]);
		*options |= (1 << index);
	}
}

int			main(int ac, char **av)
{
	int		i;
	int		tp;
	int		options;
	t_file	*files;

	i = 0;
	files = NULL;
	while (++i < ac && av[i][0] == '-' && av[i][1])
		ft_options(av[i], &options);
	tp = i;
	(i == ac) ? ft_files(".", &files, "") : --i;
	while (++i < ac)
		ft_files(av[i], &files, "");
	if (ac - tp > 0)
		ft_print_undir(ac, files, options);
	ft_print(ac - tp, files, options, 2);
	ft_free(&files);
	return (0);
}
