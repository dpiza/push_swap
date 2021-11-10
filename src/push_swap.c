/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 02:42:14 by dpiza             #+#    #+#             */
/*   Updated: 2021/11/09 16:35:08 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	lesser_check(char **stack)
{
	int	len;
	int	i;
	int	min;

	len = ft_stacklen(stack);
	if (len <= 1)
		return (0);
	min = ft_atoi(stack[0]);
	i = 0;
	if (ft_atoi(stack[1]) < min)
	{
		min = ft_atoi(stack[1]);
		i = 1;
	}
	if (ft_atoi(stack[len - 1]) < min && len > 1)
	{
		min = ft_atoi(stack[len - 1]);
		i = 2;
	}
	return (i);
}

int	greater_check(char **stack)
{
	int	len;
	int	i;
	int	max;

	len = ft_stacklen(stack);
	if (len <= 1)
		return (0);
	max = ft_atoi(stack[0]);
	i = 0;
	if (ft_atoi(stack[1]) > max)
	{
		max = ft_atoi(stack[1]);
		i = 1;
	}
	if (ft_atoi(stack[len - 1]) > max && len > 1)
	{
		max = ft_atoi(stack[len - 1]);
		i = 2;
	}
	return (i);
}

void	lesser_swap(t_stack *stack)
{
	int	lesser_a;
	int	greater_b;
	
	lesser_a = lesser_check(stack->a);
	greater_b = greater_check(stack->b);
	while (lesser_a || greater_b)
	{
		if (lesser_a == 1)
		{
			if (ft_atoi(stack->a[0]) > ft_atoi(stack->a[ft_stacklen(stack->a) - 1]))
				rotate_a(stack);
			else if (greater_b == 1)
				swap_ab(stack);
			else
				swap_a(stack);
		}
		else if (lesser_a == 2)
		{
			if (ft_atoi(stack->a[0]) > ft_atoi(stack->a[1]))
			{
				swap_a(stack);
				reverse_a(stack);
			}
			else if (greater_b == 2)
				reverse_ab(stack);
			else
				reverse_a(stack);
		}
		else if (greater_b == 1)
			swap_b(stack);
		else if (greater_b == 2)
			reverse_b(stack);
		lesser_a = lesser_check(stack->a);
		greater_b = greater_check(stack->b);
	}
}

void	small_sort(t_stack *stack)
{
	int	len;
	int	lesser_a;

	len = ft_stacklen(stack->a);
	if (len <= 1)
		return ;
	lesser_a = lesser_check(stack->a);
	while (!is_sorted(stack->a))
	{
		if (lesser_a == 1)
		{
			if (ft_atoi(stack->a[0]) > ft_atoi(stack->a[ft_stacklen(stack->a) - 1]))
				rotate_a(stack);
			else
				swap_a(stack);
		}
		else if (lesser_a == 2)
		{
			if (ft_atoi(stack->a[0]) > ft_atoi(stack->a[1]))
				swap_a(stack);
			reverse_a(stack);
		}
		else
		{
			rotate_a(stack);
			swap_a(stack);
		}
		lesser_a = lesser_check(stack->a);
	}
}

int	push_swap(t_stack *stack)
{
	int	len;
	len = ft_stacklen(stack->a);
	while(!(is_sorted(stack->a) && len == ft_stacklen(stack->a)))
	{
		lesser_swap(stack);
		while(!(is_sorted(stack->a)))
		{
			push_b(stack);
			lesser_swap(stack);
			// print_stacks(stack);
		}
		while(ft_stacklen(stack->b) > 0)
		{
			lesser_swap(stack);
			push_a(stack);
			// print_stacks(stack);
		}
	}
	return (0);
}