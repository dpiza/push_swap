/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:40:03 by dpiza             #+#    #+#             */
/*   Updated: 2021/11/14 20:04:11 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "defines.h"

typedef struct s_stack {
	char	**a;
	char	**b;
	char	**interval;
	char	*op;
	int		in;
}	t_stack;

int		push_swap(t_stack *stack);

int		is_sorted(char **stack);
int		is_sorted_b(char **stack);

int		check_duplicates(char **stack);
char	**fill_stack(int argc, char **argv);
char	**fill_interval(char **a);
void	bubble_sort(char **arr);

void	print_stacks(t_stack *stack);
void	print_interval(t_stack *stack);

void	top_add(char **stack, char *member);
void	top_rmv(char **stack);
int		ft_stacklen(char **s);
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

void	free_stack(t_stack *stack);

void	exit_err(char *str);

#endif