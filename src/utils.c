/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:19:23 by dasal             #+#    #+#             */
/*   Updated: 2024/09/05 09:19:24 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mini.h"

int			is_delimiter(char c)
{
	if ((c == ' ') || (c == '\t') || (c == '<') || (c == '>') || (c == '|') 
	|| (c == '\n') || (c == '\0'))
		return (1);
	return (0);
}

void		init_vars(t_vars *vars)
{
	vars->quote_status = 0;
	vars->head = (t_token *)malloc(sizeof(t_token));
	if (!vars->head)
	{
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
	vars->head->content = NULL;
	vars->head->type = Empty;
	vars->head->next = NULL;
}

t_token	*new_token(char *content, int type)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
	new->content = content;
	new->type = type;
	new->next = NULL;
	return (new);
}
//		adds a token to a linked list
void	add_token(t_token **head, t_token *new)
{
	t_token	*temp;

	if (!head || !new)
		return ;
	if (!(*head))
	{
		*head = new;
		return ;
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void free_token(t_token *token)
{
	if (token != NULL)
	{
		free_token(token->next);
		free(token->content);
		free(token);
	}
}

void	free_error_exit(t_vars *vars, char *str)
{
	free_token(vars->head);
	perror(str);
    exit(EXIT_FAILURE);
}