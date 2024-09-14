#include "mini.h"

char	*get_name(t_vars *vars, int i)
{
	int	j;
	int	len;

	len = 0;
	j = i;
	while (vars->cur->content[i])
	{
		if ((is_name_delimiter(vars->cur->content[i])) || (get_char_type(vars->cur->content[i]) == DQUOTE))
			break;
		len++;
		i++;
	}
	return (ft_substr(vars->cur->content, j, len));
}

int	get_name_index(t_vars *vars, char *name)
{
	int	i;

	i = 0;
	while (vars->cur->content[i])
	{
		if ((ft_strncmp(vars->cur->content + i, name, ft_strlen(name))) == 0)
			return (i);
		i++;
	}
	return (i);
}

void	remove_quotes(t_vars *vars)
{
	int		i;
	int		j;
	char	buffer[BUFFER_SIZE];
	int		q1;
	int		q2;

	i = 0;
	j = 0;
	q1 = find_q1(vars);
	q2 = find_q2(vars);
	if (q1 != -1)
	{
		while (vars->cur->content[j])
		{
			if (j == q1 || j == q2)
				j++;
			buffer[i++] = vars->cur->content[j++];
		}
		j = ft_strlen(vars->cur->content) - 2;
		free (vars->cur->content);
		vars->cur->content = (char *)malloc(sizeof(char) * (j + 1));
		ft_strlcpy(vars->cur->content, buffer, j + 1);
	}
}

int		find_q1(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->cur->content[i])
	{
		if (((get_char_type(vars->cur->content[i])) == SQUOTE) || 
		(get_char_type(vars->cur->content[i])) == DQUOTE)
			break;
		i++;
	}
	if (vars->cur->content[i] == '\0')
		return (-1);
	return (i);
}

int		find_q2(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->cur->content[i])
		i++;
	i--;
	while (i >= 0)
	{
		if (((get_char_type(vars->cur->content[i])) == SQUOTE) || 
		(get_char_type(vars->cur->content[i])) == DQUOTE)
			break;
		i--;
	}
	return (i);
}