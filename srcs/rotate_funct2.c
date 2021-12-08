/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_funct2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 02:58:49 by tlufulua          #+#    #+#             */
/*   Updated: 2021/11/20 18:57:06 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
 * RRA: Pone el último nodo de la lista "a" al principio de la lista "a".
 */
void	rra(t_stack **stack_a)
{
	t_stack	*aux;
	t_stack	*aux2;

	aux = (*stack_a);
	while (aux->next)
	{
		aux2 = aux;
		aux = aux->next;
	}
	aux->next = (*stack_a);
	(*stack_a) = aux;
	aux2->next = 0;
	write(1, "rra\n", 4);
}

/*
 * RRB: Pone el último nodo de la lista "b" al principio de la lista "b".
 */
void	rrb(t_stack **stack_b)
{
	t_stack	*aux;
	t_stack	*aux2;

	aux = (*stack_b);
	while (aux->next)
	{
		aux2 = aux;
		aux = aux->next;
	}
	aux->next = (*stack_b);
	(*stack_b) = aux;
	aux2->next = 0;
	write(1, "rrb\n", 4);
}

/*
 * RRA y RRB al mismo tiempo
 */
void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	int		len;
	int		len2;
	t_stack	*aux;

	len = stack_iter((*stack_a)) - 1;
	len2 = len;
	aux = (*stack_a);
	while (aux->next)
		aux = aux->next;
	aux->next = (*stack_a);
	(*stack_a) = aux;
	aux = (*stack_a);
	while (len--)
		aux = aux->next;
	aux->next = 0;
	aux = (*stack_b);
	while (aux->next)
		aux = aux->next;
	aux->next = (*stack_b);
	(*stack_b) = aux;
	aux = (*stack_b);
	while (len2--)
		aux = aux->next;
	aux->next = 0;
	write(1, "rrr\n", 4);
}
