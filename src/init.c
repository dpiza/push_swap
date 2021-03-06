/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:18:57 by dpiza             #+#    #+#             */
/*   Updated: 2021/11/25 18:45:55 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**fill_stack(int argc, char **argv)
{
	char	**a;
	int		i;

	i = -1;
	a = (char **)malloc((argc + 1) * sizeof(char *));
	while (++i < argc - 1)
	{
		if (!ft_isdigit(*argv[i + 1]) && *argv[i + 1] != '-')
			exit_err("Error\n");
		if (ft_atoi(argv[i + 1]) == 0 && *argv[i + 1] != '0')
			exit_err("Error\n");
		if (ft_atoi(argv[i + 1]) == -1 && *argv[i + 1] != '-')
			exit_err("Error\n");
		a[i] = argv[i + 1];
	}
	a[argc - 1] = '\0';
	return (a);
}

char	**define_interval(char **arr, int len)
{
	char	**interval;
	int		remainder;
	int		size;
	int		i;
	int		j;

	remainder = 1;
	size = SMALL_INTERVAL;
	if (len > BIG_INTERVAL_LEN)
		size = BIG_INTERVAL;
	if (len % size)
		remainder = 2;
	interval = malloc((len / size + remainder) * sizeof(char *));
	interval[len / size + remainder - 1] = '\0';
	i = 0;
	j = 0;
	while (++i < len)
	{
		if (i % size == 0)
			interval[j++] = arr[i];
	}
	if (i == len)
		interval[j] = arr[i - 1];
	return (interval);
}

char	**fill_interval(char **a)
{
	char	**sorted;
	char	**interval;
	int		i;

	sorted = (char **)malloc((ft_stacklen(a) + 1) * sizeof(char *));
	i = -1;
	while (i++ < ft_stacklen(a))
		sorted[i] = a[i];
	bubble_sort(sorted);
	if (ft_stacklen(sorted) > MIN_MSORT)
		interval = define_interval(sorted, ft_stacklen(sorted));
	free (sorted);
	return (interval);
}
