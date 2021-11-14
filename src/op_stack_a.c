/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_stack_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:52:08 by dpiza             #+#    #+#             */
/*   Updated: 2021/11/14 19:57:27 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_stack *stack)
{
	char	*t;
	int		len;

	len = ft_stacklen(stack->a);
	if (len < 2)
		return ;
	t = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = t;
	stack->in++;
	add_op(&stack->op, "sa\n");
}

void	push_a(t_stack *stack)
{
	if (!stack->b[0])
		return ;
	top_add(stack->a, stack->b[0]);
	top_rmv(stack->b);
	stack->in++;
	add_op(&stack->op, "pa\n");
}

void	rotate_a(t_stack *stack)
{
	char	*t;
	int		len;

	len = ft_stacklen(stack->a);
	if (len < 2)
		return ;
	t = stack->a[0];
	top_rmv(stack->a);
	stack->a[len - 1] = t;
	stack->in++;
	add_op(&stack->op, "ra\n");
}

void	reverse_a(t_stack *stack)
{
	int		bot;

	bot = ft_stacklen(stack->a);
	if (bot < 2)
		return ;
	top_add(stack->a, stack->a[bot - 1]);
	stack->a[bot] = NULL;
	stack->in++;
	add_op(&stack->op, "rra\n");
}
