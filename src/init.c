/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:18:57 by dpiza             #+#    #+#             */
/*   Updated: 2021/11/14 20:14:07 by dpiza            ###   ########.fr       */
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
		a[i] = argv[i + 1];
	}
	a[argc - 1] = '\0';
	return (a);
}

void	bubble_sort(char **arr)
{
	int		i;
	char	*tmp;

	while (!(is_sorted(arr)))
	{
		i = 0;
		while (i < ft_stacklen(arr) - 1)
		{
			if (ft_atoi(arr[i]) > ft_atoi(arr[i + 1]))
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
			i++;
		}
	}
}

char	**define_interval(char **arr, int len)
{
	char	**interval;
	int		rem;
	int		size;
	int		i;
	int		j;

	rem = 1;
	size = 20;
	if (len > 150)
		size = 50;
	if (len % size)
		rem = 2;
	interval = malloc((len / size + rem) * sizeof(char *));
	interval[len / size + rem - 1] = '\0';
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
	if (ft_stacklen(sorted) > MIN_QSORT)
		interval = define_interval(sorted, ft_stacklen(sorted));
	free (sorted);
	return (interval);
}
