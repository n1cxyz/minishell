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
	if ((token->type == 35))
		printf("type: WORD\n");
	else if ((token->type == 36))
		printf("type: NAME\n");
	else if ((token->type == 37))
		printf("type: EMPTY\n");
	else if ((token->type == 256))
		printf("type: <<\n");
	else if ((token->type == 257))
		printf("type: >>\n");
	else if ((token->type == 39))
		printf("type: \'\n");
	else if ((token->type == 34))
		printf("type: \"\n");
	else if ((token->type == 0))
		printf("type: 0\n");
	else
		printf("type: %c\n", token->type);
	if (!(token->next))
		printf("next: <null>\n");
	else
		printf("next: %s\n", token->next->content);	
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
		free(token);
	}
}
