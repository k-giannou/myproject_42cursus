/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:39:59 by kgiannou          #+#    #+#             */
/*   Updated: 2025/01/06 19:26:46 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (2);
}

void	free_stack(t_list **stack)
{
	t_list	*current;
	t_list	*tmp;

	current = *stack;
	while (current)
	{
		tmp = current->next;
		free (current);
		current = tmp;
	}
	*stack = NULL;
}

int	ft_free(t_list **stacka, char **argv, int argc)
{
	t_list	*tmp;
	t_list	*current;
	int		i;

	if (stacka)
		free_stack(stacka);
	i = 0;
	if (argc == 2)
	{
		while (argv[i])
		{
			free (argv[i]);
			i++;
		}
		free (argv);
	}
	return (1);
}

long long	ft__atoi(const char *str)
{
	int			sign;
	long long	sum;
	long long	i;

	sign = 1;
	sum = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum = sum * 10 + str[i] - 48;
		i++;
	}
	return (sum * sign);
}

t_list	*find_max(t_list *stack)
{
	t_list	*max;

	if (!stack)
		return (NULL);
	max = stack;
	while (stack)
	{
		if (stack->num > max->num)
			max = stack;
		stack = stack->next;
	}
	return (max);
}
