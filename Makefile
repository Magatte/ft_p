# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pba <pba@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/09 11:34:20 by pba               #+#    #+#              #
#    Updated: 2016/05/22 12:13:35 by pba              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: mkdir_obj, mkdir_obj_server, mkdir_obj_client, clean fclean

.SUFFIXES:

CFLAGS			= -Wall -Werror -Wextra
SERVER			= server
CLIENT			= client
HPATH_FTP		= includes/
HPATH_LIBFT 	= libft/includes/
SPATH_SERVER	= src_server/
SPATH_CLIENT	= src_client/
OPATH_SERVER	= obj_server/
OPATH_CLIENT	= obj_client/

SRC_SERVER		= server.c \
				  parser.c \
				  init_env.c \
				  create_server.c \
				  request.c \
				  get_pwd.c \
				  get_path.c \
				  check_path.c \
				  args.c \
				  open_dir.c \
				  exec_cmd.c \
				  builtins.c \
				  binary.c \
				  path_binary.c \
				  put_file_serv.c \
				  status.c \
				  notify_send.c

SRC_CLIENT		= client.c \
				  create_client.c \
				  put_file.c

OBJ_SERVER		= $(SRC_SERVER:%.c=$(OPATH_SERVER)%.o)
OBJ_CLIENT		= $(SRC_CLIENT:%.c=$(OPATH_CLIENT)%.o)

INCLUDE			= ./includes/ft_p.h

all: mkdir_obj server client

$(SERVER): $(OBJ_SERVER)
	@echo "\033[32;01mserver object files created.\033[0m"
	@echo "\033[36;01mcompiling libft...\033[0m"
	@make re -C libft
	@echo "\033[32;01mlibft.a created.\033[0m"
	@gcc -o $(SERVER) $(OBJ_SERVER) -L./libft/ -lft
	@echo "\033[32;01mLink done.\033[0m"
	@echo "\033[32;01mServer created.\033[0m\n"
	@echo "\033[31;01mSERVER READY FOR USE !\033[0m\n"

$(CLIENT): $(OBJ_CLIENT)
	@echo "\033[32;01mclient object files created.\033[0m"
	@echo "\033[36;01mcompiling libft...\033[0m"
	@make re -C libft
	@echo "\033[32;01mlibft.a created.\033[0m"
	@gcc -o $(CLIENT) $(OBJ_CLIENT) -L./libft/ -lft
	@echo "\033[32;01mLink done.\033[0m"
	@echo "\033[32;01mClient created.\033[0m\n"
	@echo "\033[31;01mCLIENT READY FOR USE !\033[0m\n"

$(OPATH_SERVER)%.o: $(SPATH_SERVER)%.c ${INCLUDE}
	@gcc $(CFLAGS) -c $< -I $(HPATH_FTP) -I $(HPATH_LIBFT) -o $@

$(OPATH_CLIENT)%.o: $(SPATH_CLIENT)%.c 
	@gcc $(CFLAGS) -c $< -I $(HPATH_FTP) -I $(HPATH_LIBFT) -o $@

$(OPATH)%.o: $(OPATH_SERVER)%.o $(OPATH_CLIENT)%.o

mkdir_obj:
	@mkdir -p $(OPATH_SERVER) $(OPATH_CLIENT)
	@echo "\033[32;01mobj_server/ and obj_client/ folders created.\033[0m"

mkdir_obj_server:
	@mkdir -p $(OPATH_SERVER)
	@echo "\033[32;01mobj_server/ folder created.\033[0m"

mkdir_obj_client:
	@mkdir -p $(OPATH_CLIENT)
	@echo "\033[32;01mobj_client/ folder created.\033[0m"

clean_server:
	@rm -rf $(OBJ_SERVER)
	@echo "Server object files deleted."

clean_client:
	@rm -rf $(OBJ_CLIENT)
	@echo "Client object filess deleted."

clean: clean_server clean_client

fclean_server: clean_server
	@rm -rf $(SERVER)
	@echo "$(SERVER) deleted."

fclean_client: clean_client
	@rm -rf $(CLIENT)
	@echo "$(CLIENT) deleted."

fclean: fclean_server fclean_client

re_server: fclean_server mkdir_obj_server $(SERVER)

re_client: fclean_client mkdir_obj_client $(CLIENT)

re: fclean all
