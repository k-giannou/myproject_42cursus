/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:17:31 by kgiannou          #+#    #+#             */
/*   Updated: 2025/01/06 18:54:17 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack, char c)//1 2 3 -> 2 1 3
{
	t_list	*first;
	t_list	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*stack = second;
	if (c == 'a' || c == 'b')
		ft_printf("s%c\n", c);
}

void	swap_double(t_list **stacka, t_list **stackb)
{
	swap(stacka, 's');
	swap(stackb, 's');
	ft_printf("ss\n");
}

void	push(t_list **stackfrom, t_list **stackto, char c)
{
	t_list	*firstfrom;

	if (!*stackfrom)
		return ;
	firstfrom = *stackfrom;
	*stackfrom = firstfrom->next;
	if (*stackfrom)
		(*stackfrom)->prev = NULL;
	firstfrom->next = *stackto;
	if (*stackto)
		(*stackto)->prev = firstfrom;
	firstfrom->prev = NULL;
	*stackto = firstfrom;
	ft_printf("p%c\n", c);
}

void	rotate(t_list **stack, char c)//1 2 4 3 -> 2 4 3 1
{
	t_list	*first;
	t_list	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = first->next;
	second->prev = NULL;
	*stack = second;
	while (second->next)
		second = second->next;
	second->next = first;
	first->next = NULL;
	first->prev = second;
	if (c == 'a' || c == 'b')
		ft_printf("r%c\n", c);
}

void	rotate_double(t_list **stacka, t_list **stackb)
{
	rotate(stacka, 's');
	rotate(stackb, 's');
	ft_printf("rr\n");
}
