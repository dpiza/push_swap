/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 21:13:28 by dpiza             #+#    #+#             */
/*   Updated: 2021/11/14 22:17:14 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
