/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevo <sevo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:44:23 by wlucke            #+#    #+#             */
/*   Updated: 2024/10/03 13:37:21 by sevo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../../libft/base/libft.h"
# include "../../libft/gnl/get_next_line.h"
# include "../../libft/printf/ft_printf.h"
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>

# include <readline/readline.h>
# include <readline/history.h>

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_pipex
{
	t_bool	here_doc;
	char	*limiter;	
	char	*file_in;
	int		cmd_count;
	char	**cmd;
	char	***cmd_argv;
	t_bool	append;
	char	*file_out;	
	char	**env;
	int		fd_in;
	int		fd_out;
	int		exit_code;
}	t_pipex;

typedef struct s_expand
{
	int				i;
	int				j;
	int				dq;
	int				sq;
	unsigned int	len;
	char			result[1024];
}	t_expand;

# define CHUNK_SIZE 65536

//main
void	init_data(t_pipex *data);
void	load_data(t_pipex *data, int argc, char **argv, char **envp);
void	exec_data(t_pipex *data);
void	cleanup_data(t_pipex *data);

//load
t_bool	get_here_doc(char **argv);
char	*get_limiter(char **argv);
t_bool	get_append(int argc, char **argv);
char	*get_infile(char **argv);
char	*get_outfile(int argc, char **argv);
void	get_commands(t_pipex *data, char **argv);

//read
void	read_input(t_pipex *data);
void	read_infile(t_pipex *data);
void	read_heredoc(t_pipex *data);

//expand
void	init_exp_p(t_expand *exp);
char	*expand_line_p(t_pipex *data, t_expand *exp, char *line);
int		is_single_p(t_expand *exp, char *line);
void	alloc_name_p(t_expand *exp, t_pipex *data, char *line);
char	*ft_getenv_p(t_pipex *data, char *name);
char	*alloc_result_p(t_expand *exp, char *line);

//prepare
void	parse_cmds(t_pipex *data);
char	*add_path(char *cmd, char **envp);

//exec
void	exec_data(t_pipex *data);
void	exec_pipe(t_pipex *data);
void	exec_cmd(t_pipex *data, int i);
void	exec_multiple_cmds(t_pipex *data, int *last_pid);
void	pipe_wait(t_pipex *data, int last_pid);
void	setup_child(t_pipex *data, int i, int *fd, int output_fd);
void	exec_child(t_pipex *data, int i, int *fd);
int		get_exit_code(int status);
int		open_output(t_pipex *data);
// void	exec_single_cmd(t_pipex *data);
int		open_input(t_pipex *data);

//exec: utils
void	redirect_fd(int old_fd, int new_fd);
// void	handle_parent(t_pipex *data, int *fd, int i);
void	create_pipe(t_pipex *data, int *fd);
pid_t	fork_process(t_pipex *data);
void	write_error(const char *cmd, int error);

//cleanup
void	cleanup_data(t_pipex *data);
void	free_data(t_pipex *data);
void	free_array_2d(char **array);
void	free_array_3d(char ***array);
//error
void	exit_error(t_pipex *data, char *error_message, int exit_code);
// utils
char	*first_word(char *str);
// void	print_data(t_pipex *data);
void	seven_to_space(char *str);
void	seven_to_nul(char *str);

#endif
