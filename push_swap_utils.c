/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakiray <ecakiray@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 22:22:56 by bkusi-fr          #+#    #+#             */
/*   Updated: 2026/05/08 07:11:45 by ecakiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"
#include "push_swap.h"

static void	replace_data_with_rank(t_dlist *stk)
{
	t_node	*cur;

	cur = stk->head;
	while (1)
	{
		cur->data = cur->rank;
		cur = cur->next;
		if (!cur || cur == stk->head)
			break ;
	}
}

void	populate_stack(t_dlist *stk)
{
	if (!stk || !stk->head)
		return ;
	set_node_ranks(stk);
	replace_data_with_rank(stk);
}

int	find_pos(int tg, int *arr, int arrlen)
{
	int	i;

	i = 0;
	while (i < arrlen)
	{
		if (arr[i] == tg)
			return (i);
		i++;
	}
	return (-1);
}

void	create_stack_from_arr(t_dlist *stk, int *arr, int len)
{
	t_node	*node;

	while (--len > -1)
	{
		node = create_node(arr[len]);
		if (!node)
			return ;
		dlist_addfront(stk, node);
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
