/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:36:53 by dpiza             #+#    #+#             */
/*   Updated: 2021/11/14 00:56:41 by dpiza            ###   ########.fr       */
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

char	**fill_interval(char **a)
{
	char	**sorted;
	char	**interval;
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	sorted = malloc((ft_stacklen(a) + 1) * sizeof(char*));
	while (i++ < ft_stacklen(a))
		sorted[i] = a[i];
	while (!(is_sorted(sorted)))
	{
		i = 0;
		while (i < ft_stacklen(sorted) - 1)
		{
			if (ft_atoi(sorted[i]) > ft_atoi(sorted[i + 1]))
			{
				tmp = sorted[i];
				sorted[i] = sorted[i + 1];
				sorted[i + 1] = tmp;
			}
			i++;
		}
	}
	if (ft_stacklen(sorted) > 50)
	{
		interval = malloc((ft_stacklen(sorted) / 20 + 2) * sizeof(char*));
		i = 1;
		j = 0;
		while (i < ft_stacklen(sorted))
		{
			if (i % 20 == 0)
			{
				interval[j] = sorted[i];
				j++;
			}
			i++;
		}
		if (i == ft_stacklen(sorted))
			interval[j] = sorted[i - 1];
	}
	else
		interval = NULL;
	free (sorted);
	return (interval);
}


int	main(int argc, char **argv)
{
	t_stack	stack;

	if(argc < 2)
		exit_err(USAGE);
	stack.a = fill_stack(argc, argv);
	stack.interval = fill_interval(stack.a);
	if (check_duplicates(stack.a))
		exit_err("Error\n");
	stack.b = (char**)ft_calloc((argc + 1), sizeof(char*));
	stack.in = 0;
	stack.op = ft_strdup("Operation List:\n");
	print_stacks(&stack);

	print_interval(&stack);
	push_swap(&stack);


	
	// print_stacks(&stack);
	// ft_printf(stack.op);
	free (stack.a);
	free (stack.b);
	return (0);
}