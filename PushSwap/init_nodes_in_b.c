/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_in_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:49:56 by kgiannou          #+#    #+#             */
/*   Updated: 2025/01/08 19:33:37 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_in_b(t_list *a, t_list *b)
{
	t_list	*cur_a;
	t_list	*target;
	long	best_num;

	while (b)
	{
		best_num = LONG_MAX;
		cur_a = a;
		while (cur_a)
		{
			if (b->num < cur_a->num
				&& cur_a->num < best_num)
			{
				target = cur_a;
				best_num = cur_a->num;
			}
			cur_a = cur_a->next;
		}
		if (best_num == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target;
		b = b->next;
	}
}

void	init_nodes_in_b(t_list *a, t_list *b)
{
	current_index(a);
	current_index(b);
	set_target_in_b(a, b);
}
