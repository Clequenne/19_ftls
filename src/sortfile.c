/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clequenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 19:17:52 by clequenn          #+#    #+#             */
/*   Updated: 2019/08/05 19:19:39 by clequenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_file	*ft_swap(t_file *file1, t_file *file2)
{
	file1->next = file2->next;
	file2->next = file1;
	return (file2);
}

static t_file	*ft_sort_reverse(t_file *files)
{
	t_file	*prev;
	t_file	*curr;
	t_file	*next;

	prev = NULL;
	curr = files;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return (prev);
}

static t_file	*ft_sort_time(t_file *files)
{
	if (!files)
		return (NULL);
	if (files->next && (files->time < files->next->time))
		files = ft_swap(files, files->next);
	else if (files->next && files->time == files->next->time)
		if (files->next && (files->ntime < files->next->ntime))
			files = ft_swap(files, files->next);
	files->next = ft_sort_time(files->next);
	if (files->next && (files->time < files->next->time))
	{
		files = ft_swap(files, files->next);
		files->next = ft_sort_time(files->next);
	}
	else if (files->next && files->time == files->next->time)
	{
		if (files->next && (files->ntime < files->next->ntime))
		{
			files = ft_swap(files, files->next);
			files->next = ft_sort_time(files->next);
		}
	}
	return (files);
}

static t_file	*ft_sort_ascii(t_file *files)
{
	if (!files)
		return (NULL);
	if (files->next && ft_strcmp(files->filename, files->next->filename) > 0)
		files = ft_swap(files, files->next);
	files->next = ft_sort_ascii(files->next);
	if (files->next && ft_strcmp(files->filename, files->next->filename) > 0)
	{
		files = ft_swap(files, files->next);
		files->next = ft_sort_ascii(files->next);
	}
	return (files);
}

void			ft_sort(t_file **files, int options)
{
	*files = ft_sort_ascii(*files);
	if (options & OPT_T)
		*files = ft_sort_time(*files);
	if (options & OPT_REV)
		*files = ft_sort_reverse(*files);
}
