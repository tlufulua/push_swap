/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_funct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 02:37:03 by tlufulua          #+#    #+#             */
/*   Updated: 2021/12/05 20:27:34 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
 * Mueve el primer número de la lista "b" al principio de la lista "a".
 */
void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;

	aux = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	aux->next = (*stack_a);
	(*stack_a) = aux;
	write(1, "pa\n", 3);
}

/*
 * Mueve el primer número de la lista "a" al principio de la lista "b".
 */
void	pb(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*aux;

	aux = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	aux->next = (*stack_b);
	(*stack_b) = aux;
	write(1, "pb\n", 3);
}

/*
 * Intercambia los dos primeros nodos de la lista "a".
 */
void	sa(t_stack **stack_a)
{
	t_stack	*aux;
	t_stack	*aux2;

	aux = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	aux2 = (*stack_a)->next;
	(*stack_a)->next = aux;
	aux->next = aux2;
	write(1, "sa\n", 3);
}

/*
 * Intercambia los dos primeros nodos de la lista "b".
 */
void	sb(t_stack **stack_b)
{
	t_stack	*aux;
	t_stack	*aux2;

	aux = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	aux2 = (*stack_b)->next;
	(*stack_b)->next = aux;
	aux->next = aux2;
	write(1, "sb\n", 3);
}

/*
 * SA y SB al mismo tiempo.
 */
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}
