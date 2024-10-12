/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:05:24 by dasal             #+#    #+#             */
/*   Updated: 2024/10/10 14:05:25 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini.h"

int	main(void)
{
	char	cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		ft_printf("%s\n", cwd);
	}
	else
	{
		perror("getcwd");
		return (2);
	}
	return (0);
}
