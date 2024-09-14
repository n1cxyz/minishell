/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:38:26 by dasal             #+#    #+#             */
/*   Updated: 2024/09/06 11:38:27 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"
/* 
enum tokentype {
	NEWLINE = '\n',
	LESS = '<',
	GREAT = '>',
	PIPE = '|',
	SQUOTE = 39,
	DQUOTE = 34,
	DLESS = 256,
	DGREAT = 257,
	GENERAL, 
	SPACE,
	WORD,
	NAME,
	Empty,
	FILENAME,
	END
}; */


void	print_token(t_token *token)
{
	if (token->type == SPACE)
		printf("content: <space>\n");
	else
			printf("content: %s\n", token->content);
	if (token->type == '\n')
		printf("type: NEWLINE\n");
	else if (token->type == LESS)
		printf("type: LESS\n");
	else if (token->type == GREAT)
		printf("type: GREAT\n");
	else if (token->type == PIPE)
		printf("type: PIPE\n");
	else if (token->type == SQUOTE)
		printf("type: SQUOTE\n");
	else if (token->type == DQUOTE)
		printf("type: DQUOTE\n");
	else if (token->type == DLESS)
		printf("type: DLESS\n");
	else if (token->type == DGREAT)
		printf("type: DGREAT\n");
	else if (token->type == GENERAL)
		printf("type: GENERAL\n");
	else if (token->type == SPACE)
		printf("type: SPACE\n");
	else if (token->type == WORD)
		printf("type: WORD\n");
	else if (token->type == NAME)
		printf("type: NAME\n");
	else if (token->type == EMPTY)
		printf("type: EMPTY\n");
	else if (token->type == FILENAME)
		printf("type: FILENAME\n");
	else if (token->type == END)
		printf("type: END\n");
	else
		printf("type: %c\n", token->type);
	if (!(token->next))
		printf("next: <null>\n");
	else
	{
		if (token->next->type == '\n')
			printf("next: NEWLINE\n");
		else if (token->next->type == LESS)
			printf("next: LESS\n");
		else if (token->next->type == GREAT)
			printf("next: GREAT\n");
		else if (token->next->type == PIPE)
			printf("next: PIPE\n");
		else if (token->next->type == SQUOTE)
			printf("next: SQUOTE\n");
		else if (token->next->type == DQUOTE)
			printf("next: DQUOTE\n");
		else if (token->next->type == DLESS)
			printf("next: DLESS\n");
		else if (token->next->type == DGREAT)
			printf("next: DGREAT\n");
		else if (token->next->type == GENERAL)
			printf("next: GENERAL\n");
		else if (token->next->type == SPACE)
			printf("next: SPACE\n");
		else if (token->next->type == WORD)
			printf("next: WORD\n");
		else if (token->next->type == NAME)
			printf("next: NAME\n");
		else if (token->next->type == EMPTY)
			printf("next: EMPTY\n");
		else if (token->next->type == FILENAME)
			printf("type: FILENAME\n");
		else if (token->next->type == END)
			printf("type: END\n");
		else
			printf("next: %d\n", token->next->type);
	}	
	printf("\n");
}

void	check_invalid_syntax(t_vars *vars, char c)
{
	if ((c >= 1 && c <= 8) || (c >= 11 && c <= 31) || (c == '!') || (c == '#'))
	{
		ft_putstr_fd("invalid syntax: '", STDERR_FILENO);
		ft_putchar_fd(c, STDERR_FILENO);
		ft_putchar_fd('\'', STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
		free_token(vars->head);
        exit(EXIT_FAILURE);
	}
	if ((c >= 37 && c <= 38) || (c >= 40 && c <= 44) || (c >= 46 && c <= 47))
	{
		ft_putstr_fd("invalid syntax: '", STDERR_FILENO);
		ft_putchar_fd(c, STDERR_FILENO);
		ft_putchar_fd('\'', STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
		free_token(vars->head);
        exit(EXIT_FAILURE);
	}
	if ((c >= 58 && c <= 59) || (c == '=') || (c == '@') || (c >= 91 && c <= 96))
	{
		ft_putstr_fd("invalid syntax: '", STDERR_FILENO);
		ft_putchar_fd(c, STDERR_FILENO);
		ft_putchar_fd('\'', STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
		free_token(vars->head);
        exit(EXIT_FAILURE);
	}
	if ((c >= 125 && c <= 126) || (c == '{'))
	{
		ft_putstr_fd("invalid syntax: '", STDERR_FILENO);
		ft_putchar_fd(c, STDERR_FILENO);
		ft_putchar_fd('\'', STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
		free_token(vars->head);
        exit(EXIT_FAILURE);
	}
}

//		!! leaks memory
void	print_token_list(t_token *head)
{
	while (head)
	{
		print_token(head);
		head = head->next;
	}
}

void	print_struct(t_pipex *data)
{
	if (data->here_doc)
		printf("here_doc: true\n");
	else
		printf("here_doc: false\n");
	if (data->limiter)
		printf("limiter: %s\n", data->limiter);
	else
		printf("limiter: null\n");
	if (data->file_in)
		printf("file_in: %s\n", data->file_in);
	else
		printf("file_in: null\n");
	printf("cmd_count: %d\n", data->cmd_count);
	/*
	*/
	if (data->append)
		printf("append: true\n");
	else
		printf("append: false\n");
	if (data->file_out)
		printf("file_out: %s\n", data->file_out);
	else
		printf("file_out: null\n");
	//printf("%d\n", data->exit_code);	
}

void	init_struct(t_pipex *data)
{
	data->here_doc = false;
	data->limiter = NULL;
	data->file_in = NULL;
	data->cmd_count = 0;
	data->append = false;
	data->file_out = NULL;
	data->exit_code = 0;
}
