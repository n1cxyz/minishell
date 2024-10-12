/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:46:00 by wlucke            #+#    #+#             */
/*   Updated: 2024/04/29 18:22:17 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*i_node;
	int		i;

	i_node = lst;
	i = 0;
	while (i_node != NULL)
	{
		i++;
		i_node = i_node->next;
	}
	return (i);
}

/*
Function name       ft_lstsize
Prototype           int ft_lstsize(t_list *lst);
Turn in files       -
Parameters          lst: The beginning of the list.
Return value        The length of the list
External functs.    None
Description         Counts the number of nodes in a list.
*/