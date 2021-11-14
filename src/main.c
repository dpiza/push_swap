/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:36:53 by dpiza             #+#    #+#             */
/*   Updated: 2021/11/15 00:52:44 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc < 2)
		exit_err("Error\n");
	stack.a = fill_stack(argc, argv);
	if (check_duplicates(stack.a))
		exit_err("Error\n");
	stack.interval = fill_interval(stack.a);
	stack.b = (char **)ft_calloc((argc + 1), sizeof(char *));
	stack.in = 0;
	stack.op = ft_strdup("");
	// print_stacks(&stack);
	// print_interval(&stack);
	push_swap(&stack);
	// print_stacks(&stack);
	ft_printf("%s", stack.op);
	free_stack(&stack);
	return (0);
}
