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

#include "push_swap.h"

int	px(t_dlist *origin, t_dlist *dest)
{
	t_node	*node;

	node = dlist_popfront(origin);
	if (!node)
		return (0);
	dlist_addfront(dest, node);
	return (1);
}

void	rx(t_dlist *stk)
{
	dlist_rotate(stk, 1);
}

void	rr(t_dlist *stk_a, t_dlist *stk_b)
{
	dlist_rotate(stk_a, 1);
	dlist_rotate(stk_b, 1);
}

void	rrx(t_dlist *stk)
{
	dlist_rotate(stk, -1);
}

void	rrr(t_dlist *stk_a, t_dlist *stk_b)
{
	rrx(stk_a);
	rrx(stk_b);
}
