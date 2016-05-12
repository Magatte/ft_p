/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 02:16:36 by pba               #+#    #+#             */
/*   Updated: 2016/05/10 03:51:11 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_H

# define FT_P_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <netdb.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include "libft.h"

typedef struct		s_env
{
	int				cs;
	char			**env;
	char 			*home;
	char			*pwd;
	char			*old_pwd;
	size_t			home_len;
	char			**path;
	char			**cmd;
}					t_env;
void				parser(t_env *serv_env, char *line);
t_env				*init_env(char **env);
int					create_server(int port);
int					create_client(char *addr, int port);
void				get_pwd(t_env *serv_env);
char				**get_path(char **env);
int					check_path(char **env);
void				request(t_env *serv_env, int sock, char *buf);
int					ft_builtins(t_env *serv_env);
int					ft_binary(t_env *serv_env);
void				path_binary(t_env *serv_env);
int					open_dir(int args, t_env *serv_env);
int					args(char **cmd);
void				ft_exec_cmd(char *line, t_env *serv_env);

#endif
