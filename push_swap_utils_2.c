/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakiray <ecakiray@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 07:53:14 by ecakiray          #+#    #+#             */
/*   Updated: 2026/05/08 08:00:34 by ecakiray         ###   ########.fr       */
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

static void	set_node_ranks(t_dlist *stk)
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
