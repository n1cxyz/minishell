/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:45:18 by wlucke            #+#    #+#             */
/*   Updated: 2024/04/29 17:51:00 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last_node = ft_lstlast(*lst);
	last_node->next = new;
}

/*
Function name       ft_lstadd_back
Prototype           void ft_lstadd_back(t_list **lst, t_list *new);
Turn in files       -
Parameters          lst: The address of a pointer to the first link of a list.
                    new: The address of a pointer to the node to be added to 
					the list.
Return value        None
External functs.    None
Description         Adds the node ’new’ at the end of the list.
*/