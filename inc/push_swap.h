/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 00:35:24 by tlufulua          #+#    #+#             */
/*   Updated: 2021/12/08 19:07:01 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <libft.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_stack
{
	int				num;
	unsigned int	pos;
	void			*next;
}				t_stack;

//ERROR
int		check(int argc, char **argv, t_stack **stack);
int		check_digit(char **argv, int argc);
int		check_order(t_stack *stack);
int		check_rep(t_stack *stack);

//UTILS
unsigned int		stack_iter(t_stack *stack);
int					init_stack(t_stack **stack, char **argv, int len);
void				free_stack(t_stack **stack);
void				mapper(t_stack **stack);
t_stack				*last_node(t_stack *stack);

//PUSH_SWAP_FUNCT
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_b, t_stack **stack_a);

//ROTATE_FUNCT
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

//ROTATE_FUNCT2
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	reverse_rrotate(t_stack **stack_a, t_stack **stack_b);

//SIMPLE_CASES
void	five_num(t_stack **stack_a, t_stack **stack_b);
void	three_num(t_stack **stack);
void	two_num(t_stack **stack);

//HARD_CASES
void			last_ord(t_stack **stack_a, t_stack **stack_b);
void			chunk_ord(t_stack **stack_a, t_stack **stack_b);
void			more_than_five(t_stack **stack_a, t_stack **stack_b);
unsigned int	next_num(t_stack **stack, unsigned int i);

#endif
