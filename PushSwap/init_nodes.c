/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:44:01 by kgiannou          #+#    #+#             */
/*   Updated: 2025/01/08 16:44:51 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_list *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

static void	set_target_a(t_list *a, t_list *b)
{
	t_list		*cur_b;
	t_list		*target;
	long int	match;

	while (a)
	{
		match = LONG_MIN;
		cur_b = b;
		while (cur_b)
		{
			if (cur_b->num < a->num
				&& cur_b->num > match)
			{
				match = cur_b->num;
				target = cur_b;
			}
			cur_b = cur_b->next;
		}
		if (match == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target;
		a = a->next;
	}
}

static void	cost_analysis_a(t_list *a, t_list *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

void	set_cheapest(t_list *stack)
{
	t_list	*cheapest_until_now;

	if (!stack)
		return ;
	cheapest_until_now = stack;
	while (stack)
	{
		if (stack->push_cost < cheapest_until_now->push_cost)
			cheapest_until_now = stack;
		stack = stack->next;
	}
	cheapest_until_now->cheapest = true;
}

void	init_nodes(t_list *a, t_list *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
