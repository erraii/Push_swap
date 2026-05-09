/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo_simple.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakiray <ecakiray@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 09:30:20 by bkusi-fr          #+#    #+#             */
/*   Updated: 2026/05/08 05:50:34 by ecakiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"
#include "push_swap.h"

int	find_node(t_dlist *lst, int tg)
{
	int		i;
	t_node	*trav;

	if (!lst || !lst->head)
		return (-1);
	trav = lst->head;
	i = 0;
	if (trav->data == tg)
		return (i);
	trav = trav->next;
	i++;
	while (trav && trav != lst->head)
	{
		if (trav->data == tg)
			return (i);
		i++;
		trav = trav->next;
	}
	return (-1);
}

void	rotate_st(t_dlist *st, int cnt, t_output *out, char stack_name)
{
	while (cnt-- > 0)
	{
		rx(st);
		if (stack_name == 'a')
			emit_op(out, "ra");
		else
			emit_op(out, "rb");
	}
}

void	rev_rotate_st(t_dlist *st, int cnt, t_output *out, char stack_name)
{
	while (cnt-- > 0)
	{
		rrx(st);
		if (stack_name == 'a')
			emit_op(out, "rra");
		else
			emit_op(out, "rrb");
	}
}

void	selection_sort(t_dlist *st_a, t_dlist *st_b, int mx, t_output *out)
{
	int	i;
	int	pos;

	i = -1;
	while (++i < mx && compute_disorder_dlist(st_a) > 0.00006)
	{
		pos = find_node(st_a, i);
		if (pos < 0)
			return ;
		if (pos >= (mx - i - pos))
			rev_rotate_st(st_a, mx - i - pos, out, 'a');
		else if (pos < (mx - i - pos))
			rotate_st(st_a, pos, out, 'a');
		px(st_a, st_b);
		emit_op(out, "pb");
	}
	while (1)
	{
		if (px(st_b, st_a) == 0)
			break ;
		emit_op(out, "pa");
	}
}
