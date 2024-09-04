#include "mini.h"

void		init_vars(t_vars *vars)
{
	vars->head = (t_token *)malloc(sizeof(t_token));
	if(!vars->head)
		return (NULL);
	vars->head->content = NULL;
	vars->head->type = 0;
	vars->head->next = NULL;
}

int	main(void)
{
	char *input = {"< Makefile cat | wc -w > outfile\n"};
	t_vars *vars;

	init_vars(vars);
	parse_input(vars, input);
	/* char *input = {"< Makefile cat | wc -w > outfile\n"};
	parse_input(input);
	t_token	*head;

	head = (t_token *)malloc(sizeof(t_token));

	head->content = NULL;
	head->type = 0;
	head->next = NULL;

	add_token(&head, new_token("<", LESS));
	add_token(&head, new_token(">", GREAT));
	add_token(&head, new_token("<<", DGREAT));

	print_token_list(head);

	free_token(head); */
}
