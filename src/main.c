/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:36:53 by dpiza             #+#    #+#             */
/*   Updated: 2021/11/14 21:51:43 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;

	if(argc < 2)
		exit_err(USAGE);
	stack.a = fill_stack(argc, argv);
	if (check_duplicates(stack.a))
		exit_err("Error\n");
	stack.interval = fill_interval(stack.a);
	stack.b = (char**)ft_calloc((argc + 1), sizeof(char*));
	stack.in = 0;
	stack.op = ft_strdup("Operation List:\n");
	
	print_stacks(&stack);		/*   print before  */
	print_interval(&stack);		/*  print interval */
	push_swap(&stack);			/*    push_swap    */
	print_stacks(&stack);		/*   print after   */
	free_stack(&stack);			/* free everything */
	return (0);
}