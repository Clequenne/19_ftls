/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clequenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 19:15:07 by clequenn          #+#    #+#             */
/*   Updated: 2019/08/05 19:15:45 by clequenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_undir(int ac, t_file *files, int options)
{
	t_file	*undir;
	int		i;

	i = 0;
	undir = NULL;
	while (files)
	{
		if (!(S_ISDIR(files->mode)))
		{
			ft_files(files->filename, &undir, "");
			i++;
		}
		files = files->next;
	}
	if (undir)
	{
		ft_print_files(&undir, options);
		if (ac - 1 != i)
			ft_putchar('\n');
	}
}
