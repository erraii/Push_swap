/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo_simple.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakiray <ecakiray@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 09:30:20 by bkusi-fr          #+#    #+#             */
/*   Updated: 2026/05/08 05:02:01 by ecakiray         ###   ########.fr       */
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

void	perform_rotations(t_dlist *st, int cnt, int dxn, char stack_name, t_output *out)
{
	while (cnt > 0)
	{
		if (dxn == 1)
		{
			rx(st);
			if (stack_name == 'a')
				emit_op(out, "ra");
			else
				emit_op(out, "rb");
		}
		else
		{
			rrx(st);
			if (stack_name == 'a')
				emit_op(out, "rra");
			else
				emit_op(out, "rrb");
		}
		cnt--;
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
		if (pos > (mx - i - pos))
			perform_rotations(st_a, mx - i - pos, -1, 'a', out);
		else if (pos < (mx - i - pos))
			perform_rotations(st_a, pos, 1, 'a', out);
		px(st_a, st_b);
		ft_putstr_fd("pb\n", 1);
	}
	while (1)
	{
		if (px(st_b, st_a) == 0)
			break ;
		ft_putstr_fd("pa\n", 1);
	}
}
