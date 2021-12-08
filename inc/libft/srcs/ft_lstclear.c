/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:10:33 by tlufulua          #+#    #+#             */
/*   Updated: 2021/02/25 17:15:39 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*toclear;

	if (!lst)
		return ;
	while (*lst)
	{
		toclear = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = toclear;
	}
}
