/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 02:42:14 by dpiza             #+#    #+#             */
/*   Updated: 2021/11/24 23:12:15 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		merge_sort(stack);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc < 2)
		exit(0);
	stack.a = fill_stack(argc, argv);
	if (check_duplicates(stack.a))
		exit_err("Error\n");
	stack.interval = fill_interval(stack.a);
	stack.b = (char **)ft_calloc((argc + 1), sizeof(char *));
	stack.in = 0;
	stack.op = ft_strdup("");
	push_swap(&stack);
	ft_printf("%s", stack.op);
	free_stack(&stack);
	return (0);
}
