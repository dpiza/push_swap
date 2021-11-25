/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_common.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:39:49 by dpiza             #+#    #+#             */
/*   Updated: 2021/11/24 23:17:50 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	select_push(t_stack *stack, int min, int max)
{
	int	i;
	int	count;

	i = ft_stacklen(stack->a);
	count = 0;
	while (i > 0)
	{
		if (ft_atoi(stack->a[0]) <= max && ft_atoi(stack->a[0]) > min)
		{
			push_b(stack);
			count++;
		}
		else
			rotate_a(stack);
		i--;
	}
	return (count);
}

void	push_all(t_stack *stack)
{
	while (ft_stacklen(stack->b))
		push_a(stack);
}

void	push_n_b(t_stack *stack, int n)
{
	while (n--)
		push_b(stack);
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
