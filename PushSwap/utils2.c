/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:16:38 by kgiannou          #+#    #+#             */
/*   Updated: 2025/01/08 19:25:07 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_min(t_list *stack)
{
	int		min;
	t_list	*node;

	if (!stack)
		return (NULL);
	min = stack->num;
	node = stack;
	while (stack)
	{
		if (stack->num < node->num)
		{
			min = stack->num;
			node = stack;
		}
		stack = stack->next;
	}
	return (node);
}
