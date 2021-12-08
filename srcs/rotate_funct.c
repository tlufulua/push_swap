/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_funct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 02:58:49 by tlufulua          #+#    #+#             */
/*   Updated: 2021/12/08 19:39:41 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
 * RA: Pone el primer nodo de la lista "a" al final de la lista "a".
 */
void	ra(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*last;

	first = (*stack_a);
	last = (*stack_a);
	while (last->next)
		last = last->next;
	(*stack_a) = (*stack_a)->next;
	last->next = first;
	first->next = 0;
	write(1, "ra\n", 3);
}

/*
 * RB: Pone el primer nodo de la lista "b" al final de la lista "b".
 */
void	rb(t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*last;

	first = (*stack_b);
	last = (*stack_b);
	while (last->next)
		last = last->next;
	(*stack_b) = (*stack_b)->next;
	last->next = first;
	first->next = 0;
	write(1, "rb\n", 3);
}

/*
 * Ejecuta RA y RB al mismo tiempo
 */
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*last;

	first = (*stack_a);
	last = (*stack_a);
	while (last->next)
		last = last->next;
	(*stack_a) = (*stack_a)->next;
	last->next = first;
	first->next = 0;
	first = (*stack_b);
	last = (*stack_b);
	while (last->next)
		last = last->next;
	(*stack_b) = (*stack_b)->next;
	last->next = first;
	first->next = 0;
	write(1, "rr\n", 3);
}
