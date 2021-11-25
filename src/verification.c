/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:13:09 by dpiza             #+#    #+#             */
/*   Updated: 2021/11/14 20:15:19 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_duplicates(char **stack)
{
	int	i;
	int	j;

	i = 0;
	if (!stack[i])
		return (0);
	while (stack[i])
	{
		j = i + 1;
		while (stack[j])
		{
			if (ft_atoi(stack[j]) == ft_atoi(stack[i]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_sorted(char **stack)
{
	int	i;
	int	j;

	i = 0;
	if (!stack[i])
		return (1);
	while (stack[i])
	{
		j = i + 1;
		while (stack[j])
		{
			if (ft_atoi(stack[j]) < ft_atoi(stack[i]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_sorted_b(char **stack)
{
	int	i;
	int	j;

	i = 0;
	if (!stack[i])
		return (1);
	while (stack[i])
	{
		j = i + 1;
		while (stack[j])
		{
			if (ft_atoi(stack[j]) > ft_atoi(stack[i]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

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
