/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:40:03 by dpiza             #+#    #+#             */
/*   Updated: 2021/11/24 23:41:11 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"
# include "defines.h"
/*
** 			STACKS A AND B
** 			MEMBERS INTERVAL
** 			OPERATIONS STRING
** 			OPERATION COUNT
*/
typedef struct s_stack {
	char	**a;
	char	**b;
	char	**interval;
	char	*op;
	int		in;
}	t_stack;
/*
** 			SORTING ALGORITHMS
** algos.c
*/
void	merge_sort(t_stack *stack);
void	select_sort(t_stack *stack);
void	lesser_swap(t_stack *stack);
void	small_sort(t_stack *stack);
void	bubble_sort(char **arr);
/*
** 			INITIALIZE STACKS
** init.c
*/
char	**fill_stack(int argc, char **argv);
char	**fill_interval(char **a);
/*
** 			VERIFICATIONS
** check.c
*/
int		check_duplicates(char **stack);
int		is_sorted(char **stack);
int		is_sorted_b(char **stack);
int		greater_check(char **stack);
int		lesser_check(char **stack);
/*
** 			UTILITY FUNCTIONS
** utils.c
*/
void	print_checker(t_stack *stack);
int		ft_stacklen(char **s);
void	add_op(char	**stack_op, char *op);
void	free_stack(t_stack *stack);
void	exit_err(char *str);
/*
** 			COMMON OPERATIONS
** op_common.c
*/
int		select_push(t_stack *stack, int min, int max);
void	push_all(t_stack *stack);
void	push_n_b(t_stack *stack, int n);
void	top_add(char **stack, char *member);
void	top_rmv(char **stack);
/*
** 			PUSH_SWAP OPERATIONS
** op_stack_a.c op_stack_b.c op_stack_ab.c
*/
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

#endif