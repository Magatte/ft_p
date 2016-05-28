/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 02:16:36 by pba               #+#    #+#             */
/*   Updated: 2016/05/28 08:51:54 by pba              ###   ########.fr       */
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
# include <sys/stat.h>
# include <sys/time.h>
# include "libft.h"
# define BUF_SIZE (0x400)
# define CODESIZE (0xff)
# define CODEITEM (-1)
# define CODE_INIT(x, y, z) x = y; ft_bzero((void *)&y, z);
# define INTERVAL (500)

typedef struct		s_result
{
	int				code_return;
	int				client;
	char			command[256];
}					t_result;
typedef struct		s_transfer
{
	int				transfer;
	int				size;
	char			f_name[256];
	char			msg[14];
}					t_transfer;
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
	t_result		result;
	t_transfer		transf;
}					t_env;
typedef struct		s_func
{
	char			*cmd;
	void			(*func)(t_env *);
}					t_func;
extern t_env		*g_env;
extern int			g_sock;
void				parser(t_env *serv_env, char *line);
void				ftp_signal();
void				ftp_ping(void);
t_env				*init_env(char **env);
int					create_server(int port);
int					create_client(char *addr, int port);
char				*get_pwd(t_env *serv_env);
char				**get_path(char **env);
int					check_path(char **env);
void				request(t_env *serv_env, int sock, char *buf);
int					builtins(t_env *serv_env);
int					binary(t_env *serv_env);
void				path_binary(t_env *serv_env);
int					open_dir(int args, t_env *serv_env);
int					put_file(int sock, char **cmd);
int					put_file_serv(t_env *serv);
int					args(char **cmd);
void				exec_cmd(char *line, t_env *serv_env);
void				status(t_env *serv_env, int fd, int mode);
void				notify_send(int socket, t_result *result);

#endif
