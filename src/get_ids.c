/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ids.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clequenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 17:50:52 by clequenn          #+#    #+#             */
/*   Updated: 2019/08/05 17:53:19 by clequenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_putnbr_left(int nb, int size)
{
	int		len;

	len = ft_intlen(nb);
	ft_putnbr(nb);
	while (len < size)
	{
		ft_putchar(' ');
		len++;
	}
}

int		ft_pwuidlen(uid_t uid)
{
	struct passwd	*pwuid;

	pwuid = getpwuid(uid);
	if (pwuid && pwuid->pw_name)
		return (ft_strlen(pwuid->pw_name));
	return (ft_intlen((int)uid));
}

int		ft_grgidlen(gid_t gid)
{
	struct group	*grgid;

	grgid = getgrgid(gid);
	if (grgid && grgid->gr_name)
		return (ft_strlen(grgid->gr_name));
	return (ft_intlen((int)gid));
}

void	ft_putpwuid(uid_t uid, int len)
{
	struct passwd	*pwuid;
	char			*str;

	pwuid = getpwuid(uid);
	if (!(pwuid && pwuid->pw_name))
		ft_putnbr_left(uid, len);
	else
		ft_putstr_left((pwuid->pw_name), len);
}

void	ft_putgrgid(gid_t gid, int len)
{
	struct group	*grgid;

	grgid = getgrgid(gid);
	if (!(grgid && grgid->gr_name))
		ft_putnbr_left(gid, len);
	else
		ft_putstr_left((grgid->gr_name), len);
}
