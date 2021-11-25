/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 08:52:45 by dpiza             #+#    #+#             */
/*   Updated: 2021/11/24 23:06:05 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	apply_op(t_stack *stack, char *op)
{
	if (ft_strncmp(op, "sa\n", 3) == 0)
		swap_a(stack);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		swap_b(stack);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		swap_ab(stack);
	else if (ft_strncmp(op, "pa\n", 3) == 0)
		push_a(stack);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		push_b(stack);
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		rotate_a(stack);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		rotate_b(stack);
	else if (ft_strncmp(op, "rr\n", 3) == 0)
		rotate_ab(stack);
	else if (ft_strncmp(op, "rra\n", 3) == 0)
		reverse_a(stack);
	else if (ft_strncmp(op, "rrb\n", 3) == 0)
		reverse_b(stack);
	else if (ft_strncmp(op, "rrr\n", 3) == 0)
		reverse_ab(stack);
	else
		exit_err("Error\n");
}

void	checker(t_stack *stack)
{
	char	*op;

	while (TRUE)
	{
		op = get_next_line(STDIN);
		if (!op)
			return ;
		apply_op(stack, op);
		free (op);
	}
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
	checker(&stack);
	print_checker(&stack);
	free_stack(&stack);
	return (0);
}
