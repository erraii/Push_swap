/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakiray <ecakiray@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 22:22:56 by bkusi-fr          #+#    #+#             */
/*   Updated: 2026/05/08 02:43:53 by ecakiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"
#include "push_swap.h"

// double	compute_disorder(int *arr, size_t size)
// {
// 	double	mistakes;
// 	int		total_pairs;
// 	size_t	i;
// 	size_t	j;

// 	mistakes = 0;
// 	total_pairs = 0;
// 	i = 0;
// 	while (i < size)
// 	{
// 		j = i + 1;
// 		while (j < size)
// 		{
// 			total_pairs += 1;
// 			if (arr[i] > arr[j])
// 				mistakes += 1;
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (mistakes / total_pairs);
// }

static int	stack_size(t_dlist *st)
{
	int		size;
	t_node	*trav;

	if (!st || !st->head)
		return (0);
	size = 1;
	trav = st->head->next;
	while (trav && trav != st->head)
	{
		size++;
		trav = trav->next;
	}
	return (size);
}
void	populate_stack(t_dlist *stk)
{
	t_node	*outer;
	t_node	*inner;
	int		first;

	if (!stk || !stk->head)
		return ;
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
	outer = stk->head;
	first = 1;
	while (first || outer != stk->head)
	{
		first = 0;
		outer->data = outer->rank;
		outer = outer->next;
	}
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

// void	transform_input(t_state *state)
// {
// 	int	arr[1000];
// 	int	compressed[1000];
// 	int	i;
// 	int	j;
// 	int	tmp;

// 	ft_memcpy(arr, state->arr, state->len * sizeof(int));
// 	i = -1;
// 	while (++i < (int)state->len)
// 	{
// 		j = i;
// 		while (++j < (int)state->len)
// 		{
// 			if (arr[i] > arr[j])
// 			{
// 				tmp = arr[i];
// 				arr[i] = arr[j];
// 				arr[j] = tmp;
// 			}
// 		}
// 	}
// 	i = -1;
// 	while (++i < (int)state->len)
// 		compressed[i] = find_pos(state->arr[i], arr, state->len);
// 	ft_memcpy(state->arr, compressed, state->len * sizeof(int));
// }

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

	if (stack_size(st) < 2)
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
