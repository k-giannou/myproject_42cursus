/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:44:20 by kgiannou          #+#    #+#             */
/*   Updated: 2025/01/08 19:26:26 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_for_push(t_list **stack, t_list *cheapest, char c)
{
	while (*stack != cheapest)
	{
		if (c == 'a')
		{
			if (cheapest->above_median)
				rotate(stack, c);
			else
				reverse_rotate(stack, c);
		}
		else if (c == 'b')
		{
			if (cheapest->above_median)
				rotate(stack, c);
			else
				reverse_rotate(stack, c);
		}
	}
}

void	ft_sort_three(t_list **a)
{
	t_list	*max;

	max = find_max(*a);
	if (max == *a)
		rotate(a, 'a');
	else if ((*a)->next == max)
		reverse_rotate(a, 'a');
	if ((*a)->num > (*a)->next->num)
		swap(a, 'a');
}

void	ft_sort(t_list **a, t_list **b)
{
	if (stack_len(*a) == 2)
		swap(a, 'a');
	else if (stack_len(*a) == 3)
		ft_sort_three(a);
	else
		push_swap(a, b);
}
