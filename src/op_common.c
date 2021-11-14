/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_common.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:39:49 by dpiza             #+#    #+#             */
/*   Updated: 2021/11/14 19:55:07 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	top_add(char **stack, char *member)
{
	int		len;
	char	*t_old;
	char	*t_new;
	int		i;

	len = ft_stacklen(stack);
	i = 0;
	t_new = member;
	while (i <= len)
	{
		t_old = stack[i];
		stack[i] = t_new;
		t_new = t_old;
		i++;
	}
}

void	top_rmv(char **stack)
{
	int		len;
	int		i;

	len = ft_stacklen(stack);
	i = 0;
	while (i < len - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[len - 1] = NULL;
}

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
