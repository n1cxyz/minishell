#include "mini_dasal.h"
//	***
void	remove_quotes(t_vars *vars)
{
	char	*src = vars->cur->content;
	char	*dst = vars->cur->content;
	int		in_double_quotes = 0;
	int		in_single_quotes = 0;
	
	while (*src != '\0')
	{
		if (*src == '-' && !in_single_quotes)
		{
			in_double_quotes ^= 1;
			src++;
			continue;
		}
		else if (*src == 39 && !in_double_quotes)
		{
			in_single_quotes ^= 1;
			src++;
			continue;
		}
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
}
//	***