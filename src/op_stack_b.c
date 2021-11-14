/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_stack_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:52:14 by dpiza             #+#    #+#             */
/*   Updated: 2021/11/14 19:57:29 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_b(t_stack *stack)
{
	char	*t;
	int		len;

	len = ft_stacklen(stack->b);
	if (len < 2)
		return ;
	t = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = t;
	stack->in++;
	add_op(&stack->op, "sb\n");
}

void	push_b(t_stack *stack)
{
	if (!stack->a[0])
		return ;
	top_add(stack->b, stack->a[0]);
	top_rmv(stack->a);
	stack->in++;
	add_op(&stack->op, "pb\n");
}

void	rotate_b(t_stack *stack)
{
	char	*t;
	int		len;

	len = ft_stacklen(stack->b);
	if (len < 2)
		return ;
	t = stack->b[0];
	top_rmv(stack->b);
	stack->b[len - 1] = t;
	stack->in++;
	add_op(&stack->op, "rb\n");
}

void	reverse_b(t_stack *stack)
{
	int		bot;

	bot = ft_stacklen(stack->b);
	if (bot < 2)
		return ;
	top_add(stack->b, stack->b[bot - 1]);
	stack->b[bot] = NULL;
	stack->in++;
	add_op(&stack->op, "rrb\n");
}
