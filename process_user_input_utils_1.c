/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_user_input_utils_1.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakiray <ecakiray@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 07:31:33 by ecakiray          #+#    #+#             */
/*   Updated: 2026/05/08 07:59:45 by ecakiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"
#include "push_swap.h"

void	clear_stack(t_dlist *lst)
{
	t_node	*node;
	t_node	*next;

	if (!lst || !lst->head)
		return ;
	node = lst->head;
	while (1)
	{
		next = node->next;
		free(node);
		if (!next || next == lst->head)
			break ;
		node = next;
	}
	lst->head = 0;
	lst->tail = 0;
}

int	add_value_to_stack(t_state *state, t_dlist *stk_a, int value)
{
	t_node	*node;

	if (list_has_value(stk_a, value))
		return (0);
	node = create_node(value);
	if (!node)
		return (0);
	dlist_addback(stk_a, node);
	state->len += 1;
	return (1);
}

int	list_has_value(t_dlist *lst, int value)
{
	t_node	*trav;

	if (!lst || !lst->head)
		return (0);
	trav = lst->head;
	while (1)
	{
		if (trav->data == value)
			return (1);
		trav = trav->next;
		if (!trav || trav == lst->head)
			break ;
	}
	return (0);
}
