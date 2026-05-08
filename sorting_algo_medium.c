/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo_medium.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakiray <ecakiray@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:56:21 by ecakiray          #+#    #+#             */
/*   Updated: 2026/05/08 03:52:24 by ecakiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"
#include "push_swap.h"

static int	generate_chunk(int size)
{
	int	chunk;

	chunk = 1;
	while (chunk * chunk <= size)
		chunk++;
	chunk--;
	if (chunk < 2)
		chunk = 2;
	return (chunk);
}

static void	move_chunks(t_dlist *a, t_dlist *b, int chunk, t_output *out)
{
	int	counter;

	counter = 0;
	while (a && a->head)
	{
		if (a->head->data <= counter)
		{
			px(a, b);
			emit_op(out, "pb");
			rx(b);
			emit_op(out, "rb");
			counter++;
		}
		else if (a->head->data <= counter + chunk)
		{
			px(a, b);
			emit_op(out, "pb");
			counter++;
		}
		else
		{
			rx(a);
			emit_op(out, "ra");
		}
	}
}

static void	sort_chunks(t_dlist *a, t_dlist *b, int mx, t_output *out)
{
	int	len;
	int	pos;

	len = mx;
	while (--mx > -1)
	{
		pos = find_node(b, mx);
		if (pos < len - pos)
			perform_rotations(b, pos, 1, 'b', out);
		else
			perform_rotations(b, len - pos, -1, 'b', out);
		px(b, a);
		emit_op(out, "pa");
		len--;
	}
}

void	butterfly_sort(t_dlist *a, t_dlist *b, int mx, t_output *out)
{
	int	chunk;

	if (!a || !b || mx < 2)
		return ;
	chunk = generate_chunk(mx);
	move_chunks(a, b, chunk, out);
	sort_chunks(a, b, mx, out);
}
