/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:40:03 by dpiza             #+#    #+#             */
/*   Updated: 2021/11/09 18:51:36 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "defines.h"

typedef struct	s_stack {
	char	**a;
	char	**b;
	char	*op;
	int		in;
}	t_stack;

int		push_swap(t_stack *stack);
void	lesser_swap(t_stack *stack);
void	small_sort(t_stack *stack);

int		is_sorted(char **stack);
int		is_sorted_b(char **stack);
void	print_stacks(t_stack *stack);
void	add_op(char	**stack_op, char *op);

void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	swap_ab(t_stack *stack);
void	push_a(t_stack *stack);
void	push_b(t_stack *stack);
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rotate_ab(t_stack *stack);
void	reverse_a(t_stack *stack);
void	reverse_b(t_stack *stack);
void	reverse_ab(t_stack *stack);

int		ft_stacklen(char **s);
void	top_rmv(char **stack);
void	top_add(char **stack, char *member);

void	exit_err(char *str);

#endif