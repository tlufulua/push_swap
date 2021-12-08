/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:36:42 by tlufulua          #+#    #+#             */
/*   Updated: 2021/04/04 17:16:25 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newlist;

	newlist = (t_list *)malloc(sizeof(t_list));
	if (!newlist)
		return (0);
	newlist->content = content;
	newlist->next = 0;
	return (newlist);
}
