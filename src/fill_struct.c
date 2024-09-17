#include "mini_dasal.h"

void	fill_struct(t_vars *vars, t_pipex *data)
{
	vars->cur = vars->head;
	next_token(vars);
	while (vars->cur->type != NEWLINE)
	{
		count_operators(vars, vars->cur->type);
		next_token(vars);
	}
	data->cmd_count = vars->cmd_count;
	init_struct(data, vars);
	vars->cur = vars->head;
	next_token(vars);
	while (vars->cur->type != NEWLINE)
	{
		if (is_redirect(vars))
		{
			handle_operators(vars, data);
			//next_token(vars);
		}
		else if (vars->cur->type == WORD)
			handle_words(vars, data);
		if (vars->cur->type == NEWLINE)
			break;
		next_token(vars);
	}
}

void	handle_words(t_vars *vars, t_pipex *data)
{
	static int	i;
	int	j;

	j = 0;
	if (vars->cur->type == WORD)
	{
		data->cmd[i] = ft_strdup(vars->cur->content);
		data->cmd_argv[i][j] = ft_strdup(vars->cur->content);
		next_token(vars);
	}
	while (vars->cur->type != PIPE && vars->cur->type != NEWLINE)
	{
		if (is_redirect(vars))
		{
			handle_operators(vars, data);
			//next_token(vars);
			if (vars->cur->next->type == PIPE || vars->cur->next->type == NEWLINE)
				break;
		}
		else if (vars->cur->type == WORD)
		{
			j++;
			data->cmd_argv[i][j] = ft_strdup(vars->cur->content);
		}
		next_token(vars);
	}
	j++;
	data->cmd_argv[i][j] = NULL;
	i++;
}
//< Makefile cat | wc -w > outfile

void	handle_operators(t_vars *vars, t_pipex *data)
{
	if (vars->cur->type == DLESS)
		handle_input(vars, data);
	else if (vars->cur->type == LESS)
		handle_input(vars, data);
	else if (vars->cur->type == GREAT)
		handle_output(vars, data);
	else if (vars->cur->type == DGREAT)
		handle_output_append(vars, data);
}

void	handle_input(t_vars *vars, t_pipex *data)
{
	if (vars->cur->type == DLESS)
	{
		next_token(vars);
		data->here_doc = true;
		data->limiter = ft_strdup(vars->cur->content);
		data->file_in = NULL;
	}
	else if (vars->cur->type == LESS)
	{
		next_token(vars);
		if (vars->infile_count > 1)
		{
			if (access(vars->cur->content, F_OK) != 0)
				no_such_file(vars);
			else
			{
				if (access(vars->cur->content, R_OK) != 0)
					permission_denied(vars);
			}
			vars->infile_count--;
		}
		else 
			data->file_in = ft_strdup(vars->cur->content);
	}
}

void	handle_output(t_vars *vars, t_pipex *data)
{
	int	fd;

	if (vars->cur->type == GREAT)
	{
		next_token(vars);
		if (vars->outfile_count > 1)
		{
			if (access(vars->cur->content, F_OK) != 0)
			{
				fd = open(vars->cur->content, O_WRONLY | O_CREAT | O_TRUNC, 00777);
				if (fd < 0)
					ft_putstr_fd("error opening file\n", STDOUT_FILENO);
				close(fd);
			}
			if (access(vars->cur->content, R_OK) != 0)
				permission_denied(vars);
			vars->outfile_count--;
		}
		else 
			data->file_out = ft_strdup(vars->cur->content);
	}
}

void	handle_output_append(t_vars *vars, t_pipex *data)
{
	int	fd;

	if (vars->cur->type == DGREAT)
	{
		next_token(vars);
		if (vars->outfile_count > 1)
		{
			if (access(vars->cur->content, F_OK) != 0)
			{
				fd = open(vars->cur->content, O_WRONLY | O_CREAT | O_TRUNC, 00777);
				if (fd < 0)
					ft_putstr_fd("error opening file\n", STDOUT_FILENO);
				close(fd);
			}
			if (access(vars->cur->content, R_OK) != 0)
				permission_denied(vars);
			vars->outfile_count--;
		}
		else
		{
			data->append = true;
			data->file_out = ft_strdup(vars->cur->content);
		}
	}
}

void	count_operators(t_vars *vars, int type)
{
	if (type == LESS)
		vars->infile_count++;
	else if (type == GREAT)
		vars->outfile_count++;
	else if (type == DLESS)
		vars->infile_count++;
	else if (type == DGREAT)
		vars->outfile_count++;
	else if (type == PIPE)
		vars->cmd_count++; //	vars is being counted not data
	else if (type == WORD)
		vars->arg_count++;
}

void	init_struct(t_pipex *data, t_vars *vars)
{
	(void)vars;
	data->here_doc = false;
	data->limiter = NULL;
	data->file_in = NULL;
	//data->cmd_count = 0;
	data->cmd = (char **)malloc(sizeof(char *) * data->cmd_count);
	for (int i = 0; i < data->cmd_count; i++)
		data->cmd[i] = NULL;
	
	data->cmd_argv = (char ***)malloc(sizeof(char **) * data->cmd_count);
	for (int i = 0; i < data->cmd_count; i++)
	{
		data->cmd_argv[i] = (char **)malloc(sizeof(char *) * (vars->arg_count + 1));
		for (int j = 0; j < vars->arg_count; j++)
			data->cmd_argv[i][j] = NULL;
	}
	data->append = false;
	data->file_out = NULL;
	data->env = NULL;
	data->fd_in = -1;
	data->fd_out = -1;
	data->exit_code = 0;
}
