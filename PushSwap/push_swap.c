/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:29:03 by kgiannou          #+#    #+#             */
/*   Updated: 2025/01/09 11:44:07 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	first_check_argc_argv(argc, argv);
	if (!second_check_argv(argv))
		return (ft_error());
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			return (1);
	}
	if (!(third_check_argv_dup_limit(argv, argc)))
		return (ft_error(), ft_free(NULL, argv, argc));
	if (!ft_create_stack(&stack_a, argv, argc))
		return (ft_error(), ft_free(&stack_a, argv, argc));
	if (stack_a_is_sorted(stack_a))
		return (ft_free(&stack_a, argv, argc), 1);
	ft_sort(&stack_a, &stack_b);
	return (ft_free(&stack_a, argv, argc), 0);
}
/*
#include <stdio.h>
void	ft_displaynode(t_list *stack_a)
{
	t_list	*tmp;
	int		flag;

	if (stack_a == NULL)
	{
		ft_printf("List is empty.");
		exit (1);
	}
	tmp = stack_a;
	flag = 0;
	while (tmp)
	{
		if (tmp->prev)
			ft_printf("prev: %d \t \t", tmp->prev->num);
		else
			ft_printf("prev: null \t \t");
		ft_printf("cur: [%d] ", tmp->num);
		if (tmp->next)
			ft_printf("\t \t next: %d\n", tmp->next->num);
		else
			ft_printf("\t \t next: null\n");
		if (tmp->next)
		{
			if (tmp->num > tmp->next->num)
				flag = 1;
		}
		tmp = tmp->next;
	}
	if (flag == 0)
		printf("\033[35m<<< sort is CORRECT >>>\033[0m\n");
	else
		printf("\033[31m<<< sort is WRONG >>>\033[0m\n");
	write (1, "\n", 1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	first_check_argc_argv(argc, argv);
	if (!second_check_argv(argv))
		return (ft_error());
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			return (1);
	}
	if (!(third_check_argv_dup_limit(argv, argc)))
		return (ft_error(), ft_free(NULL, argv, argc));
	if (!ft_create_stack(&stack_a, argv, argc))
		return (ft_error(), ft_free(&stack_a, argv, argc));
	if (stack_a_is_sorted(stack_a))
		return (ft_free(&stack_a, argv, argc), 1);
	ft_sort(&stack_a, &stack_b);
	ft_displaynode(stack_a);
	return (ft_free(&stack_a, argv, argc), 0);
}*/
