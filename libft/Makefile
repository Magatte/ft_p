# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pba <pba@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/09 11:34:20 by pba               #+#    #+#              #
#    Updated: 2016/05/07 01:13:53 by pba              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: mkdir_obj, clean, fclean, re

.SUFFIXES:

NAME		= libft.a
CFLAGS		= -Wall -Wextra -Werror
SPATH		= src/
HPATH		= includes/
OPATH		= obj/

SRC			= ft_atoi.c \
			  ft_atoi_long.c \
			  ft_bzero.c \
			  ft_isalnum.c \
			  ft_isalpha.c \
			  ft_isascii.c \
			  ft_isdigit.c \
			  ft_isint.c \
			  ft_isprint.c \
			  ft_itoa.c \
			  ft_memalloc.c \
			  ft_memccpy.c \
			  ft_memchr.c \
			  ft_memcmp.c \
			  ft_memcpy.c \
			  ft_memdel.c \
			  ft_memmove.c \
			  ft_memset.c \
			  ft_putchar.c \
			  ft_putchar_fd.c \
			  ft_putchar_blue_fd.c \
			  ft_putendl.c \
			  ft_putendl_fd.c \
			  ft_putnbr.c \
			  ft_putnbr_fd.c \
			  ft_putnbr_blue_fd.c \
			  ft_putstr.c \
			  ft_putstr_green_fd.c \
			  ft_putstr_red_fd.c \
			  ft_putstr_blue_fd.c \
			  ft_putstr_fd.c \
			  ft_realloc.c \
			  ft_strcat.c \
			  ft_strchr.c \
			  ft_strclr.c \
			  ft_strcmp.c \
			  ft_strcpy.c \
			  ft_strdel.c \
			  ft_strdup.c \
			  ft_strequ.c \
			  ft_striter.c \
			  ft_striteri.c \
			  ft_strjoin.c \
			  ft_strlcat.c \
			  ft_strlcpy.c \
			  ft_strlen.c \
			  ft_strmap.c \
			  ft_strmapi.c \
			  ft_strncat.c \
			  ft_strncmp.c \
			  ft_strncpy.c \
			  ft_strnequ.c \
			  ft_charchr.c \
			  ft_countchar.c \
			  ft_strnew.c \
			  ft_strnstr.c \
			  ft_strrchr.c \
			  ft_strsplit.c \
			  ft_strstr.c \
			  ft_strsub.c \
			  ft_strtrim.c \
			  ft_swap.c \
			  ft_sqrt.c \
			  ft_tolower.c \
			  ft_toupper.c \
			  inter.c \
			  ft_lstadd.c \
			  ft_lstdel.c \
			  ft_lstdelone.c \
			  ft_lstiter.c \
			  ft_lstmap.c \
			  ft_lstnew.c \
			  ft_lstfree.c \
			  get_next_line.c \
			  epur_str.c \
			  display_map.c \
			  make_map.c \
			  free_map.c \
			  tab_new.c \
			  count_words.c \
			  push_lines.c

OBJ			= $(SRC:%.c=$(OPATH)%.o)

.SILENT: $(NAME) $(OPATH) mkdir_obj fclean re clean

all: mkdir_obj $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OPATH)%.o: %.c
	@gcc $(CFLAGS) -o $@ -c $< -I $(HPATH)

mkdir_obj:
	mkdir -p $(OPATH)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
