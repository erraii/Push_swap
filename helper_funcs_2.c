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
