/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:16:53 by dpiza             #+#    #+#             */
/*   Updated: 2021/11/25 18:46:12 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_stacklen(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	add_op(char	**stack_op, char *op)
{
	char	*tmp;

	tmp = ft_strjoin(*stack_op, op);
	free (*stack_op);
	*stack_op = tmp;
}

void	print_checker(t_stack *stack)
{
	if (is_sorted(stack->a) && (!stack->b[0]))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	free_stack(t_stack *stack)
{
	if (ft_stacklen(stack->a) > MIN_MSORT)
		free (stack->interval);
	free (stack->a);
	free (stack->b);
	free (stack->op);
}

void	exit_err(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}
