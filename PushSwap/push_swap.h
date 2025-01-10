/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:24:38 by kgiannou          #+#    #+#             */
/*   Updated: 2025/01/08 19:37:18 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_list
{
	int				num;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_list	*target_node;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

void				first_check_argc_argv(int argc, char **argv);
int					is_valid(char c);
int					second_check_argv(char **argv);
int					third_check_argv_dup_limit(char **arr, int argc);
long long			ft__atoi(const char *str);
int					ft_error(void);
int					ft_free(t_list **stacka, char **argv, int argc);
void				free_stack(t_list **stack);
int					ft_create_stack(t_list **stack_a, char **argv, int argc);
t_list				*init(int num, t_list *last);
int					stack_a_is_sorted(t_list *stack_a);
void				swap(t_list **stack, char c);
void				rotate(t_list **stack, char c);
void				reverse_rotate(t_list **stack, char c);
void				swap_double(t_list **stacka, t_list **stackb);
void				rotate_double(t_list **stacka, t_list **stackb);
void				reverse_rotate_double(t_list **stacka, t_list **stackb);
t_list				*find_last(t_list *stack);
void				push(t_list **stackfrom, t_list **stackto, char c);
int					stack_len(t_list *stack);
void				ft_sort(t_list **a, t_list **b);
void				ft_sort_three(t_list **a);
void				push_swap(t_list **a, t_list **b);
t_list				*find_max(t_list *a);
t_list				*find_min(t_list *stack);
void				init_nodes(t_list *a, t_list *b);
void				current_index(t_list *a);
static void			set_target_a(t_list *a, t_list *b);
static void			cost_analysis_a(t_list *a, t_list *b);
void				set_cheapest(t_list *stack);
static void			move_a_to_b(t_list **a, t_list **b);
static void			rotate_both(t_list **a, t_list **b, t_list *cheapest);
static void			rev_rotate_both(t_list **a, t_list **b, t_list *cheapest);
void				prep_for_push(t_list **a, t_list *cheapest, char c);
void				init_nodes_in_b(t_list *a, t_list *b);
static void			set_target_in_b(t_list *a, t_list *b);
void				ft_displaynode(t_list *stack_a);
#endif
