/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlucke <wlucke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:45:47 by wlucke            #+#    #+#             */
/*   Updated: 2024/04/29 18:22:39 by wlucke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

/*
Function name       ft_lstnew
Prototype           t_list *ft_lstnew(void *content);
Turn in files       -
Parameters          content: The content to create the node with.
Return value        The new node
External functs.    malloc
Description         Allocates (with malloc(3)) and returns a new node.
                    The member variable ’content’ is initialized with
                    the value of the parameter ’content’. The variable
                    ’next’ is initialized to NULL.
*/
