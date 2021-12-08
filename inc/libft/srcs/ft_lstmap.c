/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 03:12:30 by tlufulua          #+#    #+#             */
/*   Updated: 2021/04/04 17:16:56 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*temp;

	newlst = NULL;
	while (lst)
	{
		temp = ft_lstnew((*f)(lst->content));
		if (!temp)
		{
			ft_lstclear(&newlst, del);
			return (0);
		}
		ft_lstadd_back(&newlst, temp);
		lst = lst->next;
	}
	return (newlst);
}
