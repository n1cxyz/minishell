/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:40:44 by dasal             #+#    #+#             */
/*   Updated: 2024/09/07 15:40:45 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"
/* <cmd>			::= <pipeline> '&&' <cmd>
					|	<pipeline> '||' <cmd>
					|	<pipeline> 'ε' */
void	cmd(t_vars *vars)
{
	if (accept(vars, PARENTL))
		handle_parentl(vars);
	if (vars->cur->type != NEWLINE)
	{
		pipeline(vars);
		if (vars->cur->type == AND || vars->cur->type == OR)
		{
			next_token(vars);
			if (vars->cur->type == PIPE || vars->cur->type == AND || 
				vars->cur->type == OR || vars->cur->type == PARENTR || 
				vars->cur->type == NEWLINE)
				syntax_error(vars);
			if ((is_redirect(vars)) || (vars->cur->type == WORD) || 
				(vars->cur->type == PARENTL))
				cmd(vars);
		}
		else if (vars->cur->type == PARENTL)
			cmd(vars);
	}
}

/* <pipeline>			::=	<simple_cmd> '|' <pipeline> 
					|	<simple_cmd> 'ε' */
void	pipeline(t_vars *vars)
{
	if (accept(vars, PARENTL))
	{
		if (vars->cur->type == PARENTR)
			syntax_error(vars);
		pipeline(vars);
	}
	if ((is_redirect(vars)) || (vars->cur->type == WORD))
	{
		simple_cmd(vars);
		if (vars->cur->type == PIPE)
		{
			next_token(vars);
			if (vars->cur->type == PIPE || vars->cur->type == AND || 
				vars->cur->type == OR || vars->cur->type == PARENTR)
				syntax_error(vars);
			if ((is_redirect(vars)) || (vars->cur->type == WORD))
				pipeline(vars);
		}
	}
}

/* <simple_cmd>		::=	<redirect_list> <word> <cmd_suffix>
					|	<redirect_list> <word>
					|	<redirect_list>
					|	<word>	  <cmd_suffix>
					|	<word> */
void	simple_cmd(t_vars *vars)
{
	if (accept(vars, PARENTL))
	{
		if (vars->cur->type == PARENTR)
			syntax_error(vars);
		simple_cmd(vars);
	}
	if (is_redirect(vars))
	{
		if (is_parent(vars))
			syntax_error(vars);
		redirect_list(vars);
		if (accept(vars, WORD))
		{
			if ((is_redirect(vars)) || (vars->cur->type == WORD))
				cmd_suffix(vars);
		}
	}
	else if ((is_redirect(vars)) || (vars->cur->type == WORD))
		cmd_suffix(vars);
}

/* <cmd_suffix>		::=	<io_redirect> <cmd_suffix>
					|	<io_redirect> 
					|	<word> <cmd_suffix>
					|	<word>  */
void	cmd_suffix(t_vars *vars)
{
	if (is_redirect(vars))
	{
		io_redirect(vars);
		if ((is_redirect(vars)) || (vars->cur->type == WORD))
			cmd_suffix(vars);
	}
	else if (accept(vars, WORD))
	{
		if (is_parent(vars) && vars->cur->next->type == WORD)
			syntax_error(vars);
		if ((is_redirect(vars)) || (vars->cur->type == WORD))
			cmd_suffix(vars);
	}
}

//<io_redirect>		::= ['<'|'>'|'<<'|'>>'] <filename>
void	io_redirect(t_vars *vars)
{
	if (is_redirect(vars))
	{
		next_token(vars);
		expect(vars, WORD);
		if (vars->cur->type == PARENTL || vars->cur->type == PARENTR)
			syntax_error(vars);
	}
}
