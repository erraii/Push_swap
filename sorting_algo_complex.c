/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo_complex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakiray <ecakiray@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 16:15:25 by bkusi-fr          #+#    #+#             */
/*   Updated: 2026/05/08 03:44:09 by ecakiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"
#include "push_swap.h"

static int	get_bit_len(int num)
{
	int	i;

	i = 31;
	while ((num & (1 << i)) == 0)
		i--;
	return (i + 1);
}

static void	handle_radix_sort_cycle(t_dlist *st_a, t_dlist *st_b, int len, int i, t_output *out)
{
	while (len--)
	{
		if (!st_a || !st_a->head)
			break ;
		if (st_a->head->data & (1 << i))
		{
			rx(st_a);
			emit_op(out, "ra");
		}
		else
		{
			px(st_a, st_b);
			emit_op(out, "pb");
		}
	}
	while (1)
	{
		if (px(st_b, st_a) == 0)
			break ;
		emit_op(out, "pa");
	}
}

void	radix_sort(t_dlist *st_a, t_dlist *st_b, int mx, t_output *out)
{
	int	max_bit_len;
	int	i;

	i = -1;
	max_bit_len = get_bit_len(mx - 1);
	while (++i < max_bit_len)
	{
		handle_radix_sort_cycle(st_a, st_b, mx, i, out);
	}
}
