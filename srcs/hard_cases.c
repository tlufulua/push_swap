/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:16:46 by tlufulua          #+#    #+#             */
/*   Updated: 2021/12/08 19:38:23 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
 * Devuelve el número de posiciones de distancia desde el inicio de la lista 
 * hasta i.
 */
unsigned int	next_num(t_stack **stack, unsigned int i)
{
	unsigned int	n;
	t_stack			*aux;

	aux = (*stack);
	n = 0;
	while (aux->pos != i)
	{
		n++;
		aux = aux->next;
	}
	return (n);
}

/*
 * Agrupa los números dentro de un rango n pasándolos de la lista 'A' a la
 * lista 'B'.
 */
void	chunk_ord(t_stack **stack_a, t_stack **stack_b)
{
	unsigned int	i;
	unsigned int	n;

	n = stack_iter((*stack_a)) / 10;
	if (n < 3)
		n = 3;
	i = n;
	while ((*stack_a))
	{
		if (!check_order((*stack_a)))
			return ;
		if ((*stack_b) && stack_iter((*stack_b)) == i)
			i += n;
		else if ((*stack_a)->pos <= i)
		{
			while (last_node((*stack_a))->pos < (*stack_a)->pos)
				rra(stack_a);
			pb(stack_b, stack_a);
			if ((*stack_b)->next && (*stack_b)->pos < (i / 2))
				rb(stack_b);
		}
		else
			ra(stack_a);
	}
}

/*
 * Va pasando los números de la lista 'B' a la lista 'A' para que queden en
 * orden ascendente una vez quede la lista 'B' vacía.
 */
void	last_ord(t_stack **stack_a, t_stack **stack_b)
{
	unsigned int	i;
	unsigned int	n;
	t_stack			*aux;

	i = stack_iter((*stack_b));
	n = i / 10;
	if (n < 3)
		n = 3;
	while ((*stack_b))
	{
		while ((*stack_b)->pos != i)
		{
			aux = (*stack_b)->next;
			if (aux->pos == i)
				sb(stack_b);
			else if (next_num(stack_b, i) > (stack_iter((*stack_b)) / 2))
				rrb(stack_b);
			else if ((*stack_b)->pos != i)
				rb(stack_b);
		}
		pa(stack_a, stack_b);
		i--;
	}
}

/*
 * Ordena listas de más de cinco números.
 */
void	more_than_five(t_stack **stack_a, t_stack **stack_b)
{
	chunk_ord(stack_a, stack_b);
	if ((*stack_b))
		last_ord(stack_a, stack_b);
}
