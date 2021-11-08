/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:36:53 by dpiza             #+#    #+#             */
/*   Updated: 2021/11/07 21:34:49 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(int argc, int *stack)
{
	int	i;

	i = -1;
	while (++i < argc - 1)
	{
		ft_putnbr_fd(stack[i], 1);
		ft_printf("\n");
	}
}

void	print_stacks(int argc, int *stack)
{
	int	i;

	i = 0;
	(void)argc;
	while (i < argc - 1)
	{
		ft_putnbr_fd(stack[i], 1);
		ft_printf(" %d\n", sizeof(stack[i + 2]));
		i++;
	}
}

int	*fill_stack(int argc, char **argv)
{
	int	*a;
	int	i;

	i = -1;
	a = malloc ((argc + 1) * sizeof(int));
	while(++i < argc - 1)
	{
		if (!ft_isdigit(*argv[i + 1]) && *argv[i + 1] != '-')
			exit_err("Error\n");
		a[i] = atoi(argv[i + 1]);
		// if (a[i])
		// 	ft_printf("a[%d] = %d\n", i, a[i]);
	}
	return (a);
}

int	main(int argc, char **argv)
{
	int	*a;

	if(argc < 2)
		exit_err(USAGE);
	a = fill_stack(argc, argv);
	print_stacks(argc, a);

	return (0);
}