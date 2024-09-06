#include "mini.h"

void	pipeline(t_vars *vars);

void	simple_command(t_vars *vars);

void	cmd_suffix(t_vars *vars);

void	redirect_list(t_vars *vars)
{
	io_redirect(vars);
	redirect_list(vars);
}

void	io_redirect(t_vars *vars)
{
	if (vars->cur->type == LESS || vars->cur->type == GREAT ||
	vars->cur->type == DLESS || vars->cur->type == DGREAT)
	{
		next_token(vars);
		expect(vars, FILENAME);
	}
}