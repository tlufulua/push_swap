/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 23:36:19 by tlufulua          #+#    #+#             */
/*   Updated: 2021/12/21 04:40:15 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
 * Comprueba que no haya número repetidos. Si los hay, devuelve 1.
 */
int	check_rep(t_stack *stack)
{
	t_stack	*aux;

	while (stack)
	{
		aux = stack->next;
		while (aux)
		{
			if (stack->num == aux->num)
				return (1);
			aux = aux->next;
		}
		stack = stack->next;
	}
	return (0);
}

/*
 * Comprueba que el stack esté ordenado. Si lo está, devuelve 0.
 */
int	check_order(t_stack *stack)
{
	t_stack	*aux;

	aux = stack->next;
	while (aux)
	{
		if (stack->pos != (aux->pos - 1))
			return (1);
		aux = aux->next;
		stack = stack->next;
	}
	return (0);
}

/*
 * Comprueba que los argumentos sean dígitos válidos. Si hay algún argumento
 * inválido devuelve 1.
 */
int	check_digit(char **argv, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		if (!argv[i][j + 1] || !ft_isdiff(argv[i], ' '))
			return (1);
		while (argv[i][++j])
		{
			while (argv[i][j] == ' ')
				j++;
			if ((argv[i][j] == '-' || argv[i][j] == '+') 
					&& ft_isdigit(argv[i][j + 1]))
				j++;
			if (!argv[i][j])
				return (0);
			if (!ft_isdigit(argv[i][j]))
				return (1);
		}
	}
	return (0);
}

int	check(int argc, char **argv, t_stack **stack)
{
	if (argc <= 1 || !argv[1])
		return (1);
	if (check_digit(argv, argc))
		return (write(2, "Error\n", 6));
	if (init_stack(&(*stack), argv, argc - 1))
		return (write(2, "Error\n", 6));
	if (check_rep((*stack)))
		return (write(2, "Error\n", 6));
	if (!check_order((*stack)))
		return (1);
	return (0);
}
