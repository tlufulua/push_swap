/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cases.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:24:46 by tlufulua          #+#    #+#             */
/*   Updated: 2021/12/08 16:01:12 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
 * Ordena una lista de cuatro o cinco números.
 */
void	five_num(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;

	while (stack_iter((*stack_a)) > 3)
	{
		aux = last_node((*stack_a));
		if (aux->pos == 5 || aux->pos == 1)
			rra(stack_a);
		if ((*stack_a)->pos == 5 || (*stack_a)->pos == 1)
			pb(stack_b, stack_a);
		else
			ra(stack_a);
	}
	three_num(stack_a);
	while ((*stack_b))
	{
		pa(stack_a, stack_b);
		aux = (*stack_a)->next;
		if (aux->pos < (*stack_a)->pos)
			ra(stack_a);
	}
}

/*
 * Ordena una lista de tres números.
 */
void	three_num(t_stack **stack)
{
	t_stack	*last;
	t_stack	*snd;

	snd = (*stack)->next;
	last = last_node((*stack));
	if (snd->num > (*stack)->num && snd->num > last->num)
		rra(stack);
	snd = (*stack)->next;
	last = snd->next;
	if ((*stack)->num > snd->num && (*stack)->num > last->num)
		ra(stack);
	snd = (*stack)->next;
	last = snd->next;
	if ((*stack)->num > snd->num)
		sa(stack);
}

/*
 * Ordena dos números en una lista.
 */
void	two_num(t_stack **stack)
{
	t_stack	*last;

	last = (*stack)->next;
	if (last->num < (*stack)->num)
		sa(stack);
}
