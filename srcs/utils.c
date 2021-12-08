/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 01:00:35 by tlufulua          #+#    #+#             */
/*   Updated: 2021/12/08 19:01:24 by tlufulua         ###   ########.fr       */
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
	t_stack	*aux;

	while ((*stack) && (*stack)->num)
	{
		aux = (*stack);
		(*stack) = (*stack)->next;
		free(aux);
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

/*
 * Inicializa la estructura y crea la lista usando los argumentos de entrada 
 * del programa.
 */
int	init_stack(t_stack **stack, char **argv, int len)
{
	t_stack		*aux;
	long int	n;

	aux = 0;
	while (--len)
	{
		n = ft_atoli(argv[len]);
		if (n > 2147483647 || n < -2147483648)
			return (1);
		(*stack) = ft_calloc(sizeof(t_stack), 1);
		(*stack)->num = (int)n;
		(*stack)->pos = 0;
		(*stack)->next = aux;
		aux = (*stack);
	}
	mapper(stack);
	return (0);
}
