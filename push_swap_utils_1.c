/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakiray <ecakiray@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 22:22:56 by bkusi-fr          #+#    #+#             */
/*   Updated: 2026/05/08 08:00:19 by ecakiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"
#include "push_swap.h"

void	set_node_ranks(t_dlist *stk)
{
	t_node	*outer;
	t_node	*inner;

	outer = stk->head;
	while (1)
	{
		outer->rank = 0;
		inner = stk->head;
		while (1)
		{
			if (inner->data < outer->data)
				outer->rank += 1;
			inner = inner->next;
			if (!inner || inner == stk->head)
				break ;
		}
		outer = outer->next;
		if (!outer || outer == stk->head)
			break ;
	}
}

double	compute_disorder_dlist(t_dlist *st)
{
	double	mistakes;
	int		total_pairs;
	t_node	*i;
	t_node	*j;

	if (stack_len(st) < 2)
		return (0);
	mistakes = 0;
	total_pairs = 0;
	i = st->head;
	while (1)
	{
		j = i->next;
		while (j && j != st->head)
		{
			total_pairs++;
			if (i->data > j->data)
				mistakes++;
			j = j->next;
		}
		i = i->next;
		if (!i || i == st->head)
			break ;
	}
	return (mistakes / total_pairs);
}
