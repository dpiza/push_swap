/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:38:57 by dpiza             #+#    #+#             */
/*   Updated: 2021/11/14 19:48:33 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_stack *stack)
{
	if (ft_stacklen(stack->a) > MIN_QSORT)
		free (stack->interval);
	free (stack->a);
	free (stack->b);
	free (stack->op);
}
