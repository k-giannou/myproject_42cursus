/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:53:00 by kgiannou          #+#    #+#             */
/*   Updated: 2025/01/08 18:23:36 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_last(t_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	reverse_rotate(t_list **stack, char c)//1 2 4 3 -> 3 1 2 4
{
	t_list	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
	if (c == 'a' || c == 'b')
		ft_printf("rr%c\n", c);
}

void	reverse_rotate_double(t_list **stacka, t_list **stackb)
{
	reverse_rotate(stacka, 's');
	reverse_rotate(stackb, 's');
	ft_printf("rrr\n");
}
