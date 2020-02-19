/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clequenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 19:03:25 by clequenn          #+#    #+#             */
/*   Updated: 2019/08/06 19:41:01 by clequenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_blocks(t_file *files, int size[6])
{
	int	len;
	int	blocks;

	blocks = 0;
	size[4] = 3;
	size[5] = 3;
	while (files)
	{
		size[0] = ft_max(ft_intlen(files->st_nlink), size[0]);
		size[1] = ft_max(ft_pwuidlen(files->st_uid), size[1]);
		size[2] = ft_max(ft_grgidlen(files->st_gid), size[2]);
		if (!S_ISCHR(files->mode))
			len = ft_intlen(files->size);
		else
		{
			size[4] = ft_max(ft_intlen(major(files->st_rdev)), size[4]);
			size[4] = ft_max(ft_intlen(minor(files->st_rdev)), size[5]);
			len = size[4] + size[5] + 2;
		}
		size[3] = ft_max(len, size[3]);
		blocks += files->st_blocks;
		files = files->next;
	}
	size[4] = ft_max(size[3] - size[5] - 1, size[4]);
	ft_putnbr(blocks);
}

void		ft_print_files_long(t_file *files)
{
	int	size[6];

	ft_bzero(size, sizeof(size));
	ft_putstr("total ");
	ft_blocks(files, size);
	ft_putchar('\n');
	while (files)
	{
		ft_print_type(files->mode);
		ft_print_chmod(files->mode, files->full_path);
		ft_putnbr_right((int)files->st_nlink, size[0] + 1);
		ft_putchar(' ');
		ft_putpwuid((files->st_uid), size[1] + 2);
		ft_putgrgid((files->st_gid), size[2] + 2);
		ft_print_size(files->mode, files->size, files->st_rdev, size);
		ft_print_time(files->time);
		if (S_ISLNK(files->mode))
			ft_print_link(files->filename, files->full_path);
		else
			ft_putstr(files->filename);
		ft_putchar('\n');
		files = files->next;
	}
}

void		ft_print_files(t_file **files, int options)
{
	t_file	*tmp;

	ft_sort(files, options);
	if (options & OPT_L)
		ft_print_files_long(*files);
	else
	{
		tmp = *files;
		while (tmp)
		{
			ft_putendl(tmp->filename);
			tmp = tmp->next;
		}
	}
}

static void	ft_print_path(char *full_path, int *first)
{
	(*first) == 2 ? *first = 1 : ft_putchar('\n');
	ft_putstr(full_path);
	ft_putendl(":");
}

void		ft_print(int ac, t_file *files, int options, int rec)
{
	t_file	*tmp;

	ft_sort(&files, options);
	tmp = files;
	if (!(options & OPT_REC) && !rec)
		return ;
	while (tmp)
	{
		if (S_ISDIR(tmp->mode) && (rec || (ft_strcmp(tmp->filename, ".") &&
						ft_strcmp(tmp->filename, ".."))))
		{
			files = ft_read(tmp->filename, tmp->full_path, options);
			if (ac != 0 && ac != 1)
				ft_print_path(tmp->full_path, &rec);
			if (files)
			{
				ft_print_files(&files, options);
				ft_print(-1, files, options, 0);
				ft_free(&files);
			}
		}
		tmp = tmp->next;
	}
}
