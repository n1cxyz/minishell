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
/* <pipeline>			::=	<simple_cmd> '|' <pipeline> 
					|	<simple_cmd> 'ε' */
void	pipeline(t_vars *vars)
{
	if ((is_redirect(vars)) || (vars->cur->type == WORD))
	{
		simple_cmd(vars);
		if (vars->cur->type == PIPE)
		{
			next_token(vars);
			if (vars->cur->type == PIPE)
			{
				vars->error_status++;
				if (vars->error_status == 1)
					syntax_error(vars);
			}
			if ((is_redirect(vars)) || (vars->cur->type == WORD))
				pipeline(vars);
		}
	}
	/* else if ((is_redirect(vars)) || (vars->cur->type == WORD))
		simple_cmd(vars); */
}
/* <simple_cmd>		::=	<redirect_list> <word> <cmd_suffix>
					|	<redirect_list> <word>
					|	<redirect_list>
					|	<word>	  <cmd_suffix>
					|	<word> */
void	simple_cmd(t_vars *vars)
{
	if (is_redirect(vars))
	{
		redirect_list(vars);
		if (accept(vars, WORD))
		{
			
			if ((is_redirect(vars)) || (vars->cur->type == WORD))
				cmd_suffix(vars);
			/* else
				{;} */
		}
		/* else
			{;} */
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
		if ((is_redirect(vars)) || (vars->cur->type == WORD)) // all words filename?
			cmd_suffix(vars);
	}
	/* else if (is_redirect(vars))
		io_redirect(vars); */
	else if (accept(vars, WORD))
	{
		if ((is_redirect(vars)) || (vars->cur->type == WORD)) // all words filename?
			cmd_suffix(vars);
	}
	/* else if (accept(vars, WORD))
		{;} */
}
/* <redirect_list>		::=	<io_redirect> <redirect_list>
					|	<io_redirect> */
void	redirect_list(t_vars *vars)
{
	io_redirect(vars);
	if (is_redirect(vars))
		redirect_list(vars);
}
//<io_redirect>		::= ['<'|'>'|'<<'|'>>'] <filename>
void	io_redirect(t_vars *vars)
{
	if (is_redirect(vars))
	{
		next_token(vars);
		expect(vars, WORD);
	}
}
