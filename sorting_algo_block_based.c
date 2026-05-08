/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo_block_based.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakiray <ecakiray@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 03:57:46 by ecakiray          #+#    #+#             */
/*   Updated: 2026/05/08 03:58:59 by ecakiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"
#include "push_swap.h"

static int	generate_block_size(int size)
{
	int	block_size;

	block_size = 1;
	while (block_size * block_size < size)
		block_size++;
	if (block_size < 2)
		block_size = 2;
	return (block_size);
}

static int	get_stack_len(t_dlist *stack)
{
	int		len;
	t_node	*node;

	if (!stack || !stack->head)
		return (0);
	len = 1;
	node = stack->head->next;
	while (node && node != stack->head)
	{
		len++;
		node = node->next;
	}
	return (len);
}

static int	is_in_block(int data, int start, int end)
{
	return (data >= start && data <= end);
}

static int	find_block_pos(t_dlist *a, int start, int end)
{
	int		pos;
	t_node	*node;

	if (!a || !a->head)
		return (-1);
	pos = 0;
	node = a->head;
	while (node)
	{
		if (is_in_block(node->data, start, end))
			return (pos);
		node = node->next;
		pos++;
		if (node == a->head)
			break ;
	}
	return (-1);
}

static void	rotate_a_to_block(t_dlist *a, int start, int end, t_output *out)
{
	int	len;
	int	pos;

	len = get_stack_len(a);
	pos = find_block_pos(a, start, end);
	if (pos < 0)
		return ;
	if (pos <= len / 2)
		perform_rotations(a, pos, 1, 'a', out);
	else
		perform_rotations(a, len - pos, -1, 'a', out);
}

static int	push_one_block_node(t_dlist *a, t_dlist *b, int start,
		int end, t_output *out)
{
	int	middle;
	int	value;

	if (find_block_pos(a, start, end) < 0)
		return (0);
	rotate_a_to_block(a, start, end, out);
	value = a->head->data;
	px(a, b);
	emit_op(out, "pb");
	middle = start + ((end - start) / 2);
	if (value <= middle && b->head && b->head != b->tail)
	{
		rx(b);
		emit_op(out, "rb");
	}
	return (1);
}

static void	push_blocks_to_b(t_dlist *a, t_dlist *b, int mx, t_output *out)
{
	int	start;
	int	end;
	int	block_size;

	start = 0;
	block_size = generate_block_size(mx);
	while (start < mx)
	{
		end = start + block_size - 1;
		if (end >= mx)
			end = mx - 1;
		while (push_one_block_node(a, b, start, end, out))
			;
		start = end + 1;
	}
}

static void	push_back_to_a(t_dlist *a, t_dlist *b, int mx, t_output *out)
{
	int	len;
	int	pos;
	int	target;

	target = mx - 1;
	len = mx;
	while (target >= 0)
	{
		pos = find_node(b, target);
		if (pos < 0)
			return ;
		if (pos <= len / 2)
			perform_rotations(b, pos, 1, 'b', out);
		else
			perform_rotations(b, len - pos, -1, 'b', out);
		px(b, a);
		emit_op(out, "pa");
		len--;
		target--;
	}
}

void	block_based_sort(t_dlist *a, t_dlist *b, int mx, t_output *out)
{
	if (!a || !b || mx < 2)
		return ;
	push_blocks_to_b(a, b, mx, out);
	push_back_to_a(a, b, mx, out);
}