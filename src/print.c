/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:16:53 by dpiza             #+#    #+#             */
/*   Updated: 2021/11/14 20:18:58 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stacks(t_stack *stack)
{
	int	i;

	i = -1;
	ft_printf("Stack A (%d):\tStack B (%d):\t\n",
		ft_stacklen(stack->a), ft_stacklen(stack->b));
	while (stack->a[++i] || stack->b[i])
	{
		if (stack->a[i])
			ft_printf("%s", stack->a[i]);
		if (stack->b[i])
			ft_printf("\t\t%s\n", stack->b[i]);
		else
			ft_printf("\n");
	}
	if (is_sorted(stack->a))
		ft_printf("Stack A is sorted with a total of %d instructions\n",
			stack->in);
	else
		ft_printf("Stack A is NOT sorted with a total of %d instructions\n",
			stack->in);
}

void	print_interval(t_stack *stack)
{
	int	i;

	i = -1;
	if (ft_stacklen(stack->a) > MIN_QSORT)
	{
		ft_printf("Intervals:\n");
		while (stack->interval[++i])
			ft_printf("%s\n", stack->interval[i]);
	}
}
