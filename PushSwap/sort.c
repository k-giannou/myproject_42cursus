/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:53:10 by kgiannou          #+#    #+#             */
/*   Updated: 2025/01/08 19:36:47 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_list **a, t_list **b, t_list *cheapest)
{
	while (cheapest != *a && cheapest->target_node != *b)
		rotate_double(a, b);
	current_index(*a);
	current_index(*b);
}

static void	rev_rotate_both(t_list **a, t_list **b, t_list *cheapest)
{
	while (cheapest != *a && cheapest->target_node != *b)
		reverse_rotate_double(a, b);
	current_index(*a);
	current_index(*b);
}

static void	move_a_to_b(t_list **a, t_list **b)
{
	t_list	*cur;
	t_list	*cheapest;

	cur = *a;
	while (cur)
	{
		if (cur->cheapest)
		{
			cheapest = cur;
			break ;
		}
		cur = cur->next;
	}
	if (cheapest->above_median
		&& cheapest->target_node->above_median)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->above_median)
		&& !(cheapest->target_node->above_median))
		rev_rotate_both(a, b, cheapest);
	prep_for_push(a, cheapest, 'a');
	prep_for_push(b, cheapest->target_node, 'b');
	push(a, b, 'b');
}

static void	min_on_top(t_list **a)
{
	while ((*a)->num != find_min(*a)->num)
	{
		if (find_min(*a)->above_median)
			rotate(a, 'a');
		else
			reverse_rotate(a, 'a');
	}
}

void	push_swap(t_list **a, t_list **b)
{
	int	len;

	len = stack_len(*a);
	if (len-- > 3 && !stack_a_is_sorted(*a))
		push(a, b, 'b');
	if (len-- > 3 && !stack_a_is_sorted(*a))
		push(a, b, 'b');
	while (len-- > 3 && !stack_a_is_sorted(*a))
	{
		init_nodes(*a, *b);
		move_a_to_b(a, b);
	}
	ft_sort_three(a);
	while (*b)
	{
		init_nodes_in_b(*a, *b);
		prep_for_push(a, (*b)->target_node, 'a');
		push(b, a, 'a');
	}
	current_index(*a);
	min_on_top(a);
}
