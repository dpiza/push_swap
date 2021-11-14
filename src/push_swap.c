/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 02:42:14 by dpiza             #+#    #+#             */
/*   Updated: 2021/11/14 23:47:25 by dpiza            ###   ########.fr       */
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

void	quicker_sort(t_stack *stack)
{
	int	min;
	int	b_count;
	int	i;
	int	j;

	j = 0;
	min = INT_MIN;
	while (!(is_sorted(stack->a)))
	{
		b_count = select_push(stack, min, ft_atoi(stack->interval[j]));
		i = b_count;
		while (i--)
		{
			select_sort(stack);
			push_a(stack);
		}
		if (!is_sorted(stack->a))
			push_n_b(stack, b_count);
		else
			push_all(stack);
		min = ft_atoi(stack->interval[j]);
		j++;
	}
}

int	push_swap(t_stack *stack)
{
	if (ft_stacklen(stack->a) <= 3)
		small_sort(stack);
	else if (ft_stacklen(stack->a) <= 50)
	{
		while (!(is_sorted(stack->a)))
		{
			lesser_swap(stack);
			push_b(stack);
		}
		while (ft_stacklen(stack->b) > 0)
		{
			select_sort(stack);
			push_a(stack);
		}
	}
	else
		quicker_sort(stack);
	return (0);
}
