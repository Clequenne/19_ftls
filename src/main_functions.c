/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clequenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 17:48:34 by clequenn          #+#    #+#             */
/*   Updated: 2019/08/06 19:42:01 by clequenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_path(char *filename, char path[PATH_MAX],
			char full_path[PATH_MAX])
{
	int		i;

	i = -1;
	while (path[++i])
		full_path[i] = path[i];
	if (i && i < PATH_MAX)
		if (!(path[0] == '/' && path[1] == '\0'))
			full_path[i++] = '/';
	while (*filename && i < PATH_MAX)
		full_path[i++] = *filename++;
	full_path[i] = '\0';
	if (i == PATH_MAX)
		return (-1);
	return (1);
}

t_file		*ft_files_add(char *filename, t_stat *stat, char path[PATH_MAX])
{
	t_file	*files;

	if (!(files = (t_file *)ft_memalloc(sizeof(t_file)))
			|| (!(files->filename = ft_strdup(filename))))
		ft_mem_error();
	files->mode = stat->st_mode;
	files->st_nlink = stat->st_nlink;
	files->st_uid = stat->st_uid;
	files->st_gid = stat->st_gid;
	files->size = stat->st_size;
	files->st_rdev = stat->st_rdev;
	files->time = stat->st_mtimespec.tv_sec;
	files->ntime = stat->st_mtimespec.tv_nsec;
	files->st_blocks = stat->st_blocks;
	ft_path(filename, path, files->full_path);
	files->next = NULL;
	return (files);
}

void		ft_files(char *filename, t_file **files, char path[PATH_MAX])
{
	t_stat	stat;
	char	full_path[PATH_MAX];

	if (!(ft_path(filename, path, full_path)))
		return (ft_notfound_error(filename));
	if (lstat(full_path, &stat))
		return (ft_notfound_error(filename));
	if (!(*files))
		*files = ft_files_add(filename, &stat, path);
	else
	{
		while ((*files)->next)
			files = &((*files)->next);
		(*files)->next = ft_files_add(filename, &stat, path);
	}
}
