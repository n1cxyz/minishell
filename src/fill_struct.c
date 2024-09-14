#include "mini.h"

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
	vars->cur = vars->head;
	next_token(vars);
	while (vars->cur->type != NEWLINE)
	{
		if (is_redirect(vars))
			handle_operators(vars, data);
		next_token(vars);
	}
}

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
		// data->file_in ?
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
		vars->cmd_count++;
}