/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 01:00:35 by tlufulua          #+#    #+#             */
/*   Updated: 2021/12/17 20:21:56 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
 * Modifica la variable pos de cada nodo de la lista, dándole como valor su el
 * número de veces que ese número es mayor que los demás, marcando así su
 * posición en la lista.
 */
void	mapper(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*aux2;

	aux = (*stack);
	aux2 = aux;
	while (aux)
	{
		while (aux2)
		{
			if (aux->num >= aux2->num)
				aux->pos++;
			aux2 = aux2->next;
		}
		aux2 = (*stack);
		aux = aux->next;
	}
}

/*
 * Libera el stack.
 */
void	free_stack(t_stack **stack)
{
	t_stack			*aux;

	while ((*stack))
	{
		aux = (*stack)->next;
		free((*stack));
		(*stack) = aux;
	}
}

/*
 * Encuentra el último nodo de la lista y devuelve un puntero a ese último nodo.
 */

t_stack	*last_node(t_stack *stack)
{
	t_stack	*last;

	last = stack->next;
	while (last->next)
		last = last->next;
	return (last);
}

/*
 * Cuenta el número de nodos de una lista.
 */
unsigned int	stack_iter(t_stack *stack)
{
	unsigned int	i;

	i = 0;
	while (stack->next)
	{
		stack = stack->next;
		i++;
	}
	return (++i);
}
