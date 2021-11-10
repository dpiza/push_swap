/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:39:49 by dpiza             #+#    #+#             */
/*   Updated: 2021/11/09 19:37:37 by dpiza            ###   ########.fr       */
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

void	push_a(t_stack *stack)
{
	if (!stack->b[0])
		return ;
	top_add(stack->a, stack->b[0]);
	top_rmv(stack->b);
	stack->in++;
	add_op(&stack->op, "pa\n");
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

void	top_add(char **stack, char *member)
{
	int		len;
	char	*t_old;
	char	*t_new;
	int		i;

	len = ft_stacklen(stack);
	i = 0;
	t_new = member;
	while (i <= len)
	{
		t_old = stack[i];
		stack[i] = t_new;
		t_new = t_old;
		i++;
	}
}

void	top_rmv(char **stack)
{
	int		len;
	int		i;

	len = ft_stacklen(stack);
	i = 0;
	while (i < len - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[len - 1] = NULL;
}

int	ft_stacklen(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}