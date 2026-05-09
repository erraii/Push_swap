/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_brute_force.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkusi-fr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 01:55:56 by bkusi-fr          #+#    #+#             */
/*   Updated: 2026/05/09 01:56:01 by bkusi-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	solve(int node1, int node2, int node3, t_output *out)
{
	if (node1 < node2 && node3 < node2 && node3 > node1)
	{
		emit_op(out, "ra");
		emit_op(out, "sa");
		emit_op(out, "rra");
	}
	if (node1 > node2 && node2 < node3 && node3 > node1)
		emit_op(out, "sa");
	else if (node1 < node2 && node3 < node2 && node3 < node1)
		emit_op(out, "rra");
	else if (node1 > node2 && node1 > node3 && node3 > node2)
		emit_op(out, "ra");
	else if (node1 > node2 && node1 > node3 && node2 > node3)
	{
		emit_op(out, "sa");
		emit_op(out, "rra");
	}
}

void	brute_force_sort(t_dlist *a, t_dlist *b, int mx, t_output *out)
{
	int	node1;
	int	node2;
	int	node3;

	if (mx > 5 || !a || !a->head)
		return ;
	if (mx == 5)
	{
		selection_sort(a, b, mx, out);
		return ;
	}
	node1 = a->head->data;
	node2 = a->head->next->data;
	node3 = a->tail->data;
	solve(node1, node2, node3, out);
}
