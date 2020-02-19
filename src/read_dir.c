/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clequenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 19:16:47 by clequenn          #+#    #+#             */
/*   Updated: 2019/08/05 19:45:48 by clequenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*ft_read(char *filename, char path[PATH_MAX], int options)
{
	t_file			*files;
	DIR				*dir;
	struct dirent	*entry;

	files = NULL;
	if (!(dir = opendir(path)))
		ft_perm_error(filename);
	else
	{
		while ((entry = readdir(dir)))
			if (entry->d_name[0] != '.' || (options & OPT_A))
				ft_files(entry->d_name, &files, path);
	}
	if (dir)
		closedir(dir);
	return (files);
}
