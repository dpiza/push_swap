/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 21:13:28 by dpiza             #+#    #+#             */
/*   Updated: 2021/11/21 09:55:02 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	merge_sort(t_stack *stack)
{
	int	min;
	int	i;

	i = 0;
	min = INT_MIN;
	while (!(is_sorted(stack->a)))
	{
		while (ft_stacklen(stack->a))
		{
			select_push(stack, min, ft_atoi(stack->interval[i]));
			min = ft_atoi(stack->interval[i]);
			i++;
		}
		while (ft_stacklen(stack->b))
		{
			select_sort(stack);
			push_a(stack);
		}
	}
}

void	select_sort(t_stack *stack)
{
	int	max;
	int	max_pos;
	int	i;

	i = -1;
	max = ft_atoi(stack->b[0]);
	max_pos = 0;
	while (stack->b[++i])
	{
		if (ft_atoi(stack->b[i]) > max)
		{
			max = ft_atoi(stack->b[i]);
			max_pos = i;
		}
	}
	if (max_pos < (ft_stacklen(stack->b) / 2))
	{
		while (max_pos-- > 0)
			rotate_b(stack);
	}
	else
	{
		while (max_pos++ < ft_stacklen(stack->b))
			reverse_b(stack);
	}
}

void	lesser_swap(t_stack *stack)
{
	int	lesser_a;
	int	greater_b;
	int	len;

	len = ft_stacklen(stack->a);
	lesser_a = 1;
	while (lesser_a)
	{
		lesser_a = lesser_check(stack->a);
		greater_b = greater_check(stack->b);
		if (lesser_a == 1)
		{
			if (ft_atoi(stack->a[0]) > ft_atoi(stack->a[len - 1]))
				rotate_a(stack);
			else if (greater_b == 1)
				swap_ab(stack);
			else
				swap_a(stack);
		}
		if (ft_atoi(stack->a[0]) > ft_atoi(stack->a[1]))
			swap_a(stack);
		if (lesser_a == 2)
			reverse_a(stack);
	}
}

void	small_sort(t_stack *stack)
{
	int	len;
	int	lesser_a;

	len = ft_stacklen(stack->a);
	while (!is_sorted(stack->a))
	{
		lesser_a = lesser_check(stack->a);
		if (lesser_a == 1)
		{
			if (ft_atoi(stack->a[0]) > ft_atoi(stack->a[len - 1]))
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
			swap_a(stack);
	}
}

void	bubble_sort(char **arr)
{
	int		i;
	char	*tmp;

	while (!(is_sorted(arr)))
	{
		i = 0;
		while (i < ft_stacklen(arr) - 1)
		{
			if (ft_atoi(arr[i]) > ft_atoi(arr[i + 1]))
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
			i++;
		}
	}
}
