/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clequenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 19:11:42 by clequenn          #+#    #+#             */
/*   Updated: 2019/08/05 19:23:51 by clequenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_type(int mode)
{
	mode = (mode & S_IFMT);
	if (S_ISREG(mode))
		ft_putchar('-');
	else if (S_ISDIR(mode))
		ft_putchar('d');
	else if (S_ISLNK(mode))
		ft_putchar('l');
	else if (S_ISBLK(mode))
		ft_putchar('b');
	else if (S_ISCHR(mode))
		ft_putchar('c');
	else if (S_ISSOCK(mode))
		ft_putchar('s');
	else if (S_ISFIFO(mode))
		ft_putchar('p');
	else
		ft_putchar('-');
}

void	ft_print_chmod(int mode, char *full_path)
{
	char	chmod[11];
	char	buf[101];

	chmod[0] = (S_IRUSR & mode) ? 'r' : '-';
	chmod[1] = (S_IWUSR & mode) ? 'w' : '-';
	chmod[2] = (S_IXUSR & mode) ? 'x' : '-';
	chmod[3] = (S_IRGRP & mode) ? 'r' : '-';
	chmod[4] = (S_IWGRP & mode) ? 'w' : '-';
	chmod[5] = (S_IXGRP & mode) ? 'x' : '-';
	chmod[6] = (S_IROTH & mode) ? 'r' : '-';
	chmod[7] = (S_IWOTH & mode) ? 'w' : '-';
	chmod[8] = (S_IXOTH & mode) ? 'x' : '-';
	chmod[9] = (listxattr(full_path, buf, sizeof(buf), XATTR_NOFOLLOW) > 0)
		? '@' : ' ';
	chmod[10] = '\0';
	if (S_ISUID & mode)
		chmod[3] = chmod[3] == '-' ? 'S' : 's';
	if (S_ISGID & mode)
		chmod[6] = chmod[6] == '-' ? 'S' : 's';
	if (S_ISVTX & mode)
		chmod[9] = chmod[9] == '-' ? 'T' : 't';
	ft_putstr(chmod);
}

void	ft_print_size(int mode, int size, dev_t rdev, int tab[6])
{
	if (!(S_ISBLK(mode) && S_ISCHR(mode)))
		ft_putnbr_right(size, tab[3]);
	else
	{
		ft_putnbr_right(major(rdev), tab[4]);
		ft_putchar(',');
		ft_putnbr_right(minor(rdev), tab[5]);
	}
}

void	ft_print_time(time_t mtime)
{
	time_t	today;
	char	*str;
	int		len;
	int		i;

	i = 0;
	time(&today);
	str = ctime(&(mtime)) + 4;
	len = ft_strlen(str);
	ft_putchar(' ');
	while (str[i])
	{
		if (i < 7)
			ft_putchar(str[i]);
		else if (str[19] == '9' && i < 12)
			ft_putchar(str[i]);
		else if (str[19] != '9' && i > 14 && i < 20)
			ft_putchar(str[i]);
		i++;
	}
	ft_putchar(' ');
}

void	ft_print_link(char *filename, char *full_path)
{
	char	buf[NAME_MAX + 1];

	ft_bzero(buf, NAME_MAX + 1);
	readlink(full_path, buf, NAME_MAX);
	ft_putstr(filename);
	ft_putstr(" -> ");
	ft_putstr(buf);
}
