/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkusi-fr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 09:30:20 by bkusi-fr          #+#    #+#             */
/*   Updated: 2026/05/05 09:30:30 by bkusi-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"
#include "push_swap.h"

void	sx(t_dlist *stk)
{
	int	tmp;

	if (!stk || !stk->head || !stk->head->next)
		return ;
	tmp = stk->head->next->data;
	stk->head->next->data = stk->head->data;
	stk->head->data = tmp;
}

void	ss(t_dlist *stk_a, t_dlist *stk_b)
{
	sx(stk_a);
	sx(stk_b);
}

void	init_dlist(t_dlist *lst)
{
	lst->head = 0;
	lst->tail = 0;
}

void	init_all_vars(t_state *input, t_dlist *sa, t_dlist *sb)
{
	init_state(input);
	init_dlist(sa);
	init_dlist(sb);
}

void	set_forced_bench(t_state *state, t_bench *bench)
{
	if (ft_strncmp(state->mode, "simple", 7) == 0)
	{
		bench->strategy = "Simple";
		bench->complexity = "O(n^2)";
	}
	else if (ft_strncmp(state->mode, "medium", 7) == 0)
	{
		bench->strategy = "Medium";
		bench->complexity = "O(n√n)";
	}
	else if (ft_strncmp(state->mode, "complex", 8) == 0)
	{
		bench->strategy = "Complex";
		bench->complexity = "O(n log n)";
	}
}
