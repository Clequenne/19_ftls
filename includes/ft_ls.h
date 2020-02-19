/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clequenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 19:24:22 by clequenn          #+#    #+#             */
/*   Updated: 2019/08/06 19:39:07 by clequenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/includes/libft.h"

# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <time.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <limits.h>

# define OPT_REC	1
# define OPT_A		2
# define OPT_L		4
# define OPT_REV	8
# define OPT_T		16

typedef struct stat	t_stat;

typedef struct		s_file
{
	char			*filename;
	mode_t			mode;
	blkcnt_t		st_blocks;
	nlink_t			st_nlink;
	uid_t			st_uid;
	gid_t			st_gid;
	off_t			size;
	dev_t			st_rdev;
	time_t			time;
	long			ntime;
	char			full_path[PATH_MAX];
	struct s_file	*next;
}					t_file;

void				ft_options(char *str, int *options);
void				ft_files(char *filename, t_file **files,
		char path[PATH_MAX]);
t_file				*ft_files_add(char *filename, t_stat *stat,
		char path[PATH_MAX]);
void				ft_print_undir(int ac, t_file *files, int options);
void				ft_print(int ac, t_file *files, int options, int rec);
void				ft_print_files(t_file **files, int options);
void				ft_print_files_long(t_file *files);
void				ft_blocks(t_file *files, int size[6]);
int					ft_pwuidlen(uid_t uid);
int					ft_grgidlen(gid_t gid);
void				ft_putpwuid(uid_t uid, int len);
void				ft_putgrgid(gid_t gid, int len);
void				ft_print_type(int mode);
void				ft_print_chmod(int mode, char *full_path);
void				ft_print_size(int mode, int size, dev_t rdev, int tab[6]);
void				ft_print_time(time_t time);
void				ft_print_link(char *filename, char *full_path);
void				ft_sort(t_file **files, int options);
t_file				*ft_read(char *filename, char path[PATH_MAX], int options);
int					ft_max(int n1, int n2);
int					ft_intlen(int n);
void				ft_putstr_left(char *str, int size);
void				ft_putnbr_right(int nb, int size);
void				ft_putnbr_left(int nb, int size);
void				ft_free(t_file **files);
void				ft_usage(void);
void				ft_options_error(int c);
void				ft_notfound_error(char *filename);
void				ft_mem_error(void);
void				ft_perm_error(char *filename);

#endif
