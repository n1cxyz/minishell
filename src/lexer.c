#include "mini.h"

void	parse_input(t_vars *vars, char *input)
{
	//"< Makefile cat | wc -w > outfile\n"
	int	i;
	int	j;
	int	type;
	int	quote_status;
	// to check: '<', '<<', '>', '>>', '|', \', \", $, <space>, 
	quote_status = 0;
	while (input[i] != '\n')
	{
		if (!quote_status)
			check_invalid_syntax(input[i]);
		while (get_char_type(input[i] == SPACE))
			i++;
		if (type == '<' || type == '>' || type == '|')
		{
			if ((handle_redirector(vars, input, i, type)))
				i++;
			else
				add_token(&vars->head, new_token(input[i], type));
		}
	/*  else if (type == '$')
			handle_dollar(vars, input, i, type); */
		// so far: '<', '<<', '>', '>>', '|', '?'.

		// check for beginning of quote
		if (type == DQUOTE || type == SQUOTE)
			quote_status = 1;
	}
}

//void	handle_dollar(t_vars *vars, char *input, int i, int type)

//	checks for '<<' and '>>', returns 1 if found, otherwise 0.
int	handle_redirector(t_vars *vars, char *input, int i, int type)
{
	// check next char for '<<'
	if ((type == '<') && (type == get_char_type(input[i + 1])))
	{
		// handle here_doc
		add_token(&vars->head, new_token(input[i + 1], DLESS));
		return (1);
	}
	// check next char for '>>'
	else if ((type == '>') && (type == get_char_type(input[i + 1])))
	{
		// handle '>>'
		add_token(&vars->head, new_token(input[i + 1], DGREAT));
		return  (1);
	}
	return (0);
}

int	get_char_type(int c)
{
	if (c == DLESS)
		return (DLESS);
	else if (c == DGREAT)
		return (DGREAT);
	else if (c == LESS)
		return (LESS);
	else if (c == GREAT)
		return (GREAT);
	else if (c == PIPE)
		return (PIPE);
	else if (c == SQUOTE)
		return (SQUOTE);
	else if (c == DQUOTE)
		return (DQUOTE);
	else if (c == 32 || c == '\t')
		return (SPACE);
	else 
		return (-1);
}
 
check_invalid_syntax(char c)
{
	if ((c >= 1 && c <= 8) || (c >= 11 && c <= 31) || (c == '!') || (c == '#'))
	{
		ft_putstr_fd("invalid syntax", STDERR_FILENO);
		ft_putchar_fd(c, STDERR_FILENO);
        exit(EXIT_FAILURE);
	}
	if ((c >= 37 && c <= 38) || (c >= 40 && c <= 44) || (c >= 46 && c <= 47))
	{
		ft_putstr_fd("invalid syntax", STDERR_FILENO);
		ft_putchar_fd(c, STDERR_FILENO);
        exit(EXIT_FAILURE);
	}
	if ((c >= 58 && c <= 59) || (c == '=') || (c == '@') || (c >= 91 && c <= 96))
	{
		ft_putstr_fd("invalid syntax", STDERR_FILENO);
		ft_putchar_fd(c, STDERR_FILENO);
        exit(EXIT_FAILURE);
	}
	if ((c >= 125 && c <= 127) || (c == '{'))
	{
		ft_putstr_fd("invalid syntax", STDERR_FILENO);
		ft_putchar_fd(c, STDERR_FILENO);
        exit(EXIT_FAILURE);
	}
}