#include "mini.h"

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
	else if ((token->type == 264))
		printf("type: END\n");
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
		else if ((token->next->type == 264))
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

void	print_token_list(t_token *head)
{
	while (head)
	{
		print_token(head);
		head = head->next;
	}
}