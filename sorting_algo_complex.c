/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo_complex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakiray <ecakiray@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 16:15:25 by bkusi-fr          #+#    #+#             */
/*   Updated: 2026/05/08 07:08:35 by ecakiray         ###   ########.fr       */
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

static void	handle_radix_sort_cycle(t_dlist *st_a, t_dlist *st_b,
	t_radix_cycle cycle, t_output *out)
{
	int	i;

	i = 0;
	while (i < cycle.len)
	{
		if (((st_a->head->data >> cycle.bit) & 1) == 0)
		{
			px(st_a, st_b);
			emit_op(out, "pb");
		}
		else
		{
			rx(st_a);
			emit_op(out, "ra");
		}
		i++;
	}
	while (st_b->head)
	{
		px(st_b, st_a);
		emit_op(out, "pa");
	}
}

void	radix_sort(t_dlist *st_a, t_dlist *st_b, int mx, t_output *out)
{
	t_radix_cycle	cycle;
	int				max_bit_len;

	cycle.len = mx;
	cycle.bit = 0;
	max_bit_len = get_bit_len(mx - 1);
	while (cycle.bit < max_bit_len)
	{
		handle_radix_sort_cycle(st_a, st_b, cycle, out);
		cycle.bit++;
	}
}
