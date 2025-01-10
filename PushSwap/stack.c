/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:58:04 by kgiannou          #+#    #+#             */
/*   Updated: 2025/01/06 19:13:02 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init(int num, t_list *last)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->num = num;
	new->prev = last;
	new->cheapest = false;
	new->index = 0;
	new->push_cost = 0;
	new->above_median = false;
	new->target_node = NULL;
	return (new);
}

int	ft_create_stack(t_list **stack_a, char **argv, int argc)
{
	int		i;
	t_list	*new;
	t_list	*last;

	if (argc == 2)
		i = 0;
	else
		i = 1;
	*stack_a = init(ft__atoi(argv[i++]), NULL);
	if (!*stack_a)
		return (0);
	last = *stack_a;
	while (argv[i])
	{
		new = init(ft__atoi(argv[i++]), last);
		if (!new)
			return (0);
		last->next = new;
		last = new;
	}
	return (1);
}

int	stack_a_is_sorted(t_list *stack_a)
{
	t_list	*current;

	current = stack_a;
	while (current && current->next)
	{
		if (current->num > current->next->num)
			return (0);
		current = current->next;
	}
	return (1);
}

int	stack_len(t_list *stack)
{
	int	sum;

	if (!stack)
		return (0);
	sum = 0;
	while (stack)
	{
		stack = stack->next;
		sum++;
	}
	return (sum);
}
