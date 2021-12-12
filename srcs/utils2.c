/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 01:00:35 by tlufulua          #+#    #+#             */
/*   Updated: 2021/12/12 20:02:54 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	make_list(t_stack **stack, char *argv)
{
	long int			n;
	char				**aux2;
	unsigned int		len2;
	static t_stack		*aux;

	if (!aux)
		aux = 0;
	len2 = 0;
	aux2 = ft_split(argv, ' ');
	while (aux2[len2])
		len2++;
	while (len2 > 0)
	{
		n = ft_atoli(aux2[len2 - 1]);
		if (n > 2147483647 || n < -2147483648)
			return (1);
		(*stack) = ft_calloc(sizeof(t_stack), 1);
		(*stack)->num = (int)n;
		(*stack)->pos = 0;
		(*stack)->next = aux;
		aux = (*stack);
		len2--;
	}
	return (0);
}

/*
 * Inicializa la estructura y crea la lista usando los argumentos de entrada 
 * del programa. Además comprueba que el argumento recibido no sea más grande de
 * un int.
 */
int	init_stack(t_stack **stack, char **argv, int len)
{
	while (len > 0)
	{
		if (make_list(stack, argv[len]))
			return (1);
		len--;
	}
	mapper(stack);
	return (0);
}
