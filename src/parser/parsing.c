#include "mini.h"

void	pipeline(t_vars *vars);

void	simple_command(t_vars *vars);

void	cmd_suffix(t_vars *vars)
{
	if (io_redirect(vars))
		cmd_suffix(vars);
	else if (io_redirect(vars))
		{;}
	else if (accept(vars, WORD) || accept(vars, NAME))
		cmd_suffix(vars);
}

void	redirect_list(t_vars *vars)
{
	if (io_redirect(vars))
		redirect_list(vars);	
}

int	io_redirect(t_vars *vars)
{
	if (vars->cur->type == LESS || vars->cur->type == GREAT ||
	vars->cur->type == DGREAT || vars->cur->type == DLESS)
	{
		next_token(vars);
		expect(vars, FILENAME);
		return (1);
	}
	return (0);
}