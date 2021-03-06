/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 00:36:12 by tlufulua          #+#    #+#             */
/*   Updated: 2021/12/21 05:48:11 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int argc, char **argv)
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	unsigned int	len;

	stack_a = 0;
	stack_b = 0;
	if (!check(argc, argv, &stack_a))
	{
		stack_b = NULL;
		len = stack_iter(stack_a);
		if (len == 2)
			two_num(&stack_a);
		else if (len == 3)
			three_num(&stack_a);
		else if (len <= 5)
			five_num(&stack_a, &stack_b);
		else
			more_than_five(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	return (0);
}
