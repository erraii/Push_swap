/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakiray <ecakiray@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 09:25:06 by bkusi-fr          #+#    #+#             */
/*   Updated: 2026/05/07 23:42:43 by ecakiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"
#include "push_swap.h"

void	init_dlist(t_dlist *lst)
{
	lst->head = 0;
	lst->tail = 0;
}

t_node	*create_node(int num)
{
	t_node	*ret;

	ret = malloc(sizeof(t_node));
	if (!ret)
		return (0);
	ret->data = num;
	ret->rank = 0;
	ret->next = 0;
	ret->prev = 0;
	return (ret);
}

void	dlist_addfront(t_dlist *lst, t_node *new)
{
	if (!lst || !new)
		return ;
	if (!lst->head || !lst->tail)
	{
		lst->tail = new;
		new->next = new;
		new->prev = new;
	}
	else
	{
		new->next = lst->head;
		new->prev = lst->tail;
		lst->head->prev = new;
		lst->tail->next = new;
	}
	lst->head = new;
}

void	dlist_addback(t_dlist *lst, t_node *new)
{
	if (!lst || !new)
		return ;
	if (!lst->head || !lst->tail)
	{
		lst->head = new;
		lst->tail = new;
		new->next = new;
		new->prev = new;
	}
	else
	{
		new->prev = lst->tail;
		new->next = lst->head;
		lst->tail->next = new;
		lst->head->prev = new;
		lst->tail = new;
	}
}

t_node	*dlist_popfront(t_dlist *lst)
{
	t_node	*ret;
	t_node	*new_hd;

	if (!lst || !lst->head)
		return (0);
	ret = lst->head;
	if (lst->head == lst->tail)
	{
		lst->head = 0;
		lst->tail = 0;
	}
	else
	{
		new_hd = lst->head->next;
		new_hd->prev = lst->tail;
		lst->tail->next = new_hd;
		lst->head = new_hd;
	}
	ret->next = 0;
	ret->prev = 0;
	return (ret);
}

void	dlist_rotate(t_dlist *lst, int dxn)
{
	t_node	*hd;

	if (!lst || !lst->head || !lst->head->next || !lst->head->prev)
		return ;
	hd = lst->head;
	if (dxn == 1)
	{
		lst->head = hd->next;
		lst->tail = hd;
	}
	else
	{
		lst->head = hd->prev;
		lst->tail = lst->tail->prev;
	}
}
