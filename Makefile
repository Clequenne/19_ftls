# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clequenn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/05 19:31:31 by clequenn          #+#    #+#              #
#    Updated: 2019/08/05 19:41:36 by clequenn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CFLAGS = -Wall -Werror -Wextra

LDIR = libft/
INCL = -I ./includes/ -I ./$(LDIR)

SDIR = src/
SFIL = main.c display.c display_1.c display_l.c display_error.c \
	   extra_functions.c get_ids.c main_functions.c read_dir.c sortfile.c
SRCS = $(addprefix $(SDIR), $(SFIL))

ODIR = obj/
OBJS = $(addprefix $(ODIR), $(SFIL:.c=.o))

.PHONY: all, clean, fclean; re

all: $(NAME)

$(NAME): $(OBJS)
		@make -C $(LDIR)
		@gcc $(FLAGS) $(OBJS) $(INCL) -L $(LDIR) -lft -o $(NAME)

$(ODIR)%.o: $(SDIR)%.c
		@mkdir -p obj
		@gcc -c $(FLAGS) $(INCL) $< -o $@

clean:
		@make -C $(LDIR) clean
		@/bin/rm -rf $(ODIR)

fclean: clean
		@make -C $(LDIR) fclean
		@/bin/rm -rf $(NAME)

re: fclean all
