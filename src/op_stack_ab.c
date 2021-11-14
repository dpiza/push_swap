/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_stack_ab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:52:11 by dpiza             #+#    #+#             */
/*   Updated: 2021/11/14 19:57:14 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_ab(t_stack *stack)
{
	char	*t;
	int		len;

	len = ft_stacklen(stack->a);
	if (len < 2)
		return ;
	t = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = t;
	len = ft_stacklen(stack->b);
	if (len < 2)
		return ;
	t = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = t;
	stack->in++;
	add_op(&stack->op, "ss\n");
}

void	rotate_ab(t_stack *stack)
{
	char	*t;
	int		len;

	len = ft_stacklen(stack->a);
	if (len < 2)
		return ;
	t = stack->a[0];
	top_rmv(stack->a);
	stack->a[len - 1] = t;
	len = ft_stacklen(stack->b);
	if (len < 2)
		return ;
	t = stack->b[0];
	top_rmv(stack->b);
	stack->b[len - 1] = t;
	stack->in++;
	add_op(&stack->op, "rr\n");
}

void	reverse_ab(t_stack *stack)
{
	int		bot;

	bot = ft_stacklen(stack->a);
	if (bot < 2)
		return ;
	top_add(stack->a, stack->a[bot - 1]);
	stack->a[bot] = NULL;
	bot = ft_stacklen(stack->b);
	if (bot < 2)
		return ;
	top_add(stack->b, stack->b[bot - 1]);
	stack->b[bot] = NULL;
	stack->in++;
	add_op(&stack->op, "rrr\n");
}
