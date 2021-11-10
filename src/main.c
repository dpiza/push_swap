/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:36:53 by dpiza             #+#    #+#             */
/*   Updated: 2021/11/09 18:53:09 by dpiza            ###   ########.fr       */
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
	while(stack[i])
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
	while(stack[i])
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
	while(stack[i])
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

void	add_op(char	**stack_op, char *op)
{
	char	*tmp;

	tmp = ft_strjoin(*stack_op, op);
	free (*stack_op);
	*stack_op = tmp;
}

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
	if(is_sorted(stack->a))
		ft_printf("Stack A is sorted with a total of %d instructions\n",
			stack->in);
	else
		ft_printf("Stack A is NOT sorted with a total of %d instructions\n",
			stack->in);
}

char	**fill_stack(int argc, char **argv)
{
	char	**a;
	int		i;

	i = -1;
	a = (char**)malloc ((argc + 1) * sizeof(char*));
	while(++i < argc - 1)
	{
		if (!ft_isdigit(*argv[i + 1]) && *argv[i + 1] != '-')
			exit_err("Error\n");
		a[i] = argv[i + 1];
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if(argc < 2)
		exit_err(USAGE);
	stack.a = fill_stack(argc, argv);
	if (check_duplicates(stack.a))
		exit_err("Error\n");
	stack.b = (char**)malloc ((argc + 1) * sizeof(char*));
	stack.in = 0;
	stack.op = ft_strdup("Operation List:\n");
	print_stacks(&stack);
	// swap_a(&stack);
	// push_b(&stack);
	// push_b(&stack);
	// push_b(&stack);
	// print_stacks(&stack);
	// rotate_ab(&stack);
	// reverse_ab(&stack);
	// swap_a(&stack);
	// push_a(&stack);
	// push_a(&stack);
	// push_a(&stack);

	push_swap(&stack);
	// small_sort(&stack);




	
	print_stacks(&stack);
	ft_printf(stack.op);
	free (stack.a);
	free (stack.b);
	return (0);
}