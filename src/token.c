/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:04:16 by dasal             #+#    #+#             */
/*   Updated: 2024/09/05 09:04:18 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"
//		creates a new token
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

void	print_token(t_token *token)
{
	printf("content: %s\n", token->content);
	if ((token->type == '\n'))
		printf("type: NEWLINE\n");
	else if ((token->type == '<'))
		printf("type: LESS\n");
	else if ((token->type == '>'))
		printf("type: GREAT\n");
	else if ((token->type == '|'))
		printf("type: PIPE\n");
	else if ((token->type == 39))
		printf("type: SQUOTE\n");
	else if ((token->type == 34))
		printf("type: DQUOTE\n");
	else if ((token->type == 256))
		printf("type: DLESS\n");
	else if ((token->type == 257))
		printf("type: DGREAT\n");
	else if ((token->type == 258))
		printf("type: GENERAL\n");
	else if ((token->type == 259))
		printf("type: SPACE\n");
	else if ((token->type == 260))
		printf("type: WORD\n");
	else if ((token->type == 261))
		printf("type: NAME\n");
	else if ((token->type == 262))
		printf("type: EMPTY\n");
	else if ((token->type == 263))
		printf("type: FILENAME\n");
	else
		printf("type: %c\n", token->type);
	if (!(token->next))
		printf("next: <null>\n");
	else
	{
		if ((token->next->type == '\n'))
			printf("next: NEWLINE\n");
		else if ((token->next->type == '<'))
			printf("next: LESS\n");
		else if ((token->next->type == '>'))
			printf("next: GREAT\n");
		else if ((token->next->type == '|'))
			printf("next: PIPE\n");
		else if ((token->next->type == 39))
			printf("next: SQUOTE\n");
		else if ((token->next->type == 34))
			printf("next: DQUOTE\n");
		else if ((token->next->type == 256))
			printf("next: DLESS\n");
		else if ((token->next->type == 257))
			printf("next: DGREAT\n");
		else if ((token->next->type == 258))
			printf("next: GENERAL\n");
		else if ((token->next->type == 259))
			printf("next: SPACE\n");
		else if ((token->next->type == 260))
			printf("next: WORD\n");
		else if ((token->next->type == 261))
			printf("next: NAME\n");
		else if ((token->next->type == 262))
			printf("next: EMPTY\n");
		else if ((token->next->type == 263))
			printf("type: FILENAME\n");
		else
			printf("next: %d\n", token->next->type);
	}	
	printf("\n");
}

void	print_token_list(t_token *head)
{
	while (head)
	{
		print_token(head);
		head = head->next;
	}
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
