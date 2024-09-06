#include "mini.h"

int accept(t_vars *vars, int type)
{
    if (vars->cur->type == type) {
    	next_token(vars);
        return 1;
    }
    return 0;
}

int	expect(t_vars *vars, int type)
{
	if (accept(vars, type))
		return (1);
	error(vars, "expect: syntax error near unexpected token `");
	vars->error_status = 1;
	return (0);
}

void	next_token(t_vars *vars)
{
	if (vars->cur != NULL && vars->cur->next != NULL)
        vars->cur = vars->cur->next;
}