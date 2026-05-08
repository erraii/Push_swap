/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_output_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakiray <ecakiray@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 03:32:09 by ecakiray          #+#    #+#             */
/*   Updated: 2026/05/08 05:57:35 by ecakiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"
#include "push_swap.h"

static int	op_index(char *op)
{
	if (ft_strncmp(op, "sa", 3) == 0)
		return (0);
	if (ft_strncmp(op, "sb", 3) == 0)
		return (1);
	if (ft_strncmp(op, "ss", 3) == 0)
		return (2);
	if (ft_strncmp(op, "pa", 3) == 0)
		return (3);
	if (ft_strncmp(op, "pb", 3) == 0)
		return (4);
	if (ft_strncmp(op, "ra", 3) == 0)
		return (5);
	if (ft_strncmp(op, "rb", 3) == 0)
		return (6);
	if (ft_strncmp(op, "rr", 3) == 0)
		return (7);
	if (ft_strncmp(op, "rra", 4) == 0)
		return (8);
	if (ft_strncmp(op, "rrb", 4) == 0)
		return (9);
	return (10);
}

static int	is_combinable(char *first, char *second, char *combined)
{
	if (((ft_strncmp(first, "ra", 3) == 0)
			&& (ft_strncmp(second, "rb", 3) == 0))
		|| ((ft_strncmp(first, "rb", 3) == 0)
			&& (ft_strncmp(second, "ra", 3) == 0)))
		return (ft_strlcpy(combined, "rr", 4), 1);
	if (((ft_strncmp(first, "rra", 4) == 0)
			&& (ft_strncmp(second, "rrb", 4) == 0))
		|| ((ft_strncmp(first, "rrb", 4) == 0)
			&& (ft_strncmp(second, "rra", 4) == 0)))
		return (ft_strlcpy(combined, "rrr", 4), 1);
	if (((ft_strncmp(first, "sa", 3) == 0)
			&& (ft_strncmp(second, "sb", 3) == 0))
		|| ((ft_strncmp(first, "sb", 3) == 0)
			&& (ft_strncmp(second, "sa", 3) == 0)))
		return (ft_strlcpy(combined, "ss", 3), 1);
	return (0);
}

static void	write_counted(t_output *out, char *op)
{
	int	idx;

	idx = op_index(op);
	out->op_count[idx] += 1;
	out->total_ops += 1;
	ft_putstr_fd(op, 1);
	ft_putstr_fd("\n", 1);
}

void	flush_op(t_output *out)
{
	if (out->pending[0] != '\0')
	{
		write_counted(out, out->pending);
		out->pending[0] = '\0';
	}
}

void	emit_op(t_output *out, char *op)
{
	char	combined[4];

	if (out->pending[0] == '\0')
	{
		ft_strlcpy(out->pending, op, 4);
		return ;
	}
	if (is_combinable(out->pending, op, combined))
	{
		write_counted(out, combined);
		out->pending[0] = '\0';
		return ;
	}
	write_counted(out, out->pending);
	ft_strlcpy(out->pending, op, 4);
}
