/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argc_argv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:42:38 by kgiannou          #+#    #+#             */
/*   Updated: 2025/01/08 17:34:10 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_check_argc_argv(int argc, char **argv)
{
	if (argc == 1)
		exit (1);
	if (argc == 2 && argv[1][0] == '\0')
		exit (1);
	if (argc == 2)
		if (ft_strlen(argv[1]) == 2 && argv[1][0] == '-'
			|| ft_strlen(argv[1]) == 1)
			exit (1);
	return ;
}

int	is_valid(char c)
{
	if ((c >= '0' && c <= '9') || c == ' ' || c == '-')
		return (1);
	return (0);
}

int	second_check_argv(char **argv)
{
	int	i;
	int	k;

	i = 0;
	k = 1;
	while (argv[k])
	{
		i = 0;
		while (argv[k][i] != '\0')
		{
			if (is_valid(argv[k][i]))
			{
				if ((argv[k][i] == '-' && argv[k][i + 1] == ' ')
					|| (i != 0 && argv[k][i] == '-' && argv[k][i - 1] != ' ')
					|| (argv[k][i] == '-' && argv[k][i + 1] == '\0'))
					return (0);
			}
			else
				return (0);
			i++;
		}
		k++;
	}
	return (1);
}

int	third_check_argv_dup_limit(char **arr, int argc)
{
	int		i;
	int		k;
	long	num;

	i = 1;
	if (argc == 2)
		i = 0;
	while (arr[i])
	{
		num = ft__atoi(arr[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (0);
		k = i + 1;
		while (arr[k])
		{
			if (ft__atoi(arr[k]) < INT_MIN && ft__atoi(arr[k]) > INT_MAX)
				return (0);
			if (num == ft__atoi(arr[k]))
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}
