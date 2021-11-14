/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 02:42:14 by dpiza             #+#    #+#             */
/*   Updated: 2021/11/14 02:24:27 by dpiza            ###   ########.fr       */
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
	if (len > 2 && ft_atoi(stack[2]) > max)
	{
		max = ft_atoi(stack[2]);
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
			else
				reverse_a(stack);
		}
		else if (greater_b == 1)
			swap_b(stack);
		else if (greater_b == 2)
		{
			rotate_b(stack);
			swap_b(stack);
			reverse_b(stack);
			swap_b(stack);
		}
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
			swap_a(stack);
			rotate_a(stack);
		}
		lesser_a = lesser_check(stack->a);
	}
}

void	select_sort_b(t_stack *stack)
{
	int max;
	int max_pos;
	int	i;
	
	i = 0;
	max = ft_atoi(stack->b[0]);
	while(stack->b[i])
	{
		if (ft_atoi(stack->b[i]) > max)
		{
			max = ft_atoi(stack->b[i]);
			max_pos = i;
		}
		i++;
	}
	if (max_pos < (ft_stacklen(stack->b) / 2))
	{
		while (max_pos > 0)
		{
			rotate_b(stack);
			max_pos--;
		}
	}
	else
	{
		while (max_pos < ft_stacklen(stack->b))
		{
			reverse_b(stack);
			max_pos++;
		}
	}
	push_a(stack);
}

void	quicker_sort(t_stack *stack)
{
	int	pivot;
	int min;
	int	b_count;
	int	i;
	int	j;

	j = 0;
	min = INT_MIN;
	while (!(is_sorted(stack->a)))
	{
		b_count = 0;
		pivot = ft_atoi(stack->interval[j]);
		i = ft_stacklen(stack->a);
		while(i > 0)
		{
			if(ft_atoi(stack->a[0]) <= pivot && ft_atoi(stack->a[0]) > min)
			{
				push_b(stack);
				b_count++;				
			}
			else
				rotate_a(stack);
			i--;
		}
		i = b_count;
		print_stacks(stack);
		while(i--)
			select_sort_b(stack);
		print_stacks(stack);
		if (!is_sorted(stack->a))
		{
			while (b_count--)
				push_b(stack);
		}
		else
		{
			while(ft_stacklen(stack->b))
				push_a(stack);
		}
		print_stacks(stack);
		min = pivot;
		j++;
	}
}

int	push_swap(t_stack *stack)
{
	if (ft_stacklen(stack->a) <= 3)
		small_sort(stack);
	else if (ft_stacklen(stack->a) <= 5)
	{
		while (!is_sorted(stack->a) )
			lesser_swap(stack);
	}
	else
	{
		quicker_sort(stack);

		// /* selection sort */
		// while(ft_stacklen(stack->a))
		// 	push_b(stack);
		// while(ft_stacklen(stack->b))
		// 		select_sort_b(stack);
		
	}





	// print_stacks(stack);
	return (0);
}