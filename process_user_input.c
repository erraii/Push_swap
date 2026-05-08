/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_user_input.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakiray <ecakiray@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 15:59:24 by bkusi-fr          #+#    #+#             */
/*   Updated: 2026/05/08 03:04:22 by ecakiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"
#include "push_swap.h"
#include <limits.h>

void	init_state(t_state *state)
{
	state->len = 0;
	state->is_benchmark_mode = 0;
	ft_bzero(state->mode, 10);
	ft_strlcpy(state->mode, "adaptive", 10);
}

static int	is_space(char c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}

static void	clear_stack(t_dlist *lst)
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

static int	is_strategy(char *arg)
{
	if (ft_strncmp(arg, "simple", 7) == 0)
		return (1);
	if (ft_strncmp(arg, "medium", 7) == 0)
		return (1);
	if (ft_strncmp(arg, "complex", 8) == 0)
		return (1);
	if (ft_strncmp(arg, "adaptive", 9) == 0)
		return (1);
	return (0);
}

static int	parse_flag(t_state *state, char *arg)
{
	if (ft_strncmp(arg, "bench", 6) == 0)
	{
		state->is_benchmark_mode = 1;
		return (1);
	}
	if (is_strategy(arg))
	{
		ft_strlcpy(state->mode, arg, 10);
		return (1);
	}
	return (0);
}

static int	parse_int_token(char *arg, int start, int end, int *value)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = start;
	if (i < end && (arg[i] == '+' || arg[i] == '-'))
	{
		if (arg[i] == '-')
			sign = -1;
		i++;
	}
	if (i == end)
		return (0);
	while (i < end)
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		result = result * 10 + (arg[i] - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && result > 2147483648L))
			return (0);
		i++;
	}
	*value = (int)(result * sign);
	return (1);
}
static int	list_has_value(t_dlist *lst, int value)
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

static int	add_value_to_stack(t_state *state, t_dlist *stk_a, int value)
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
static int	process_token(t_state *state, t_dlist *stk_a, char *arg, int *i)
{
	int	start;
	int	value;

	while (arg[*i] && is_space(arg[*i]))
		(*i)++;
	if (!arg[*i])
		return (2);
	start = *i;
	while (arg[*i] && !is_space(arg[*i]))
		(*i)++;
	if (!parse_int_token(arg, start, *i, &value))
		return (0);
	if (!add_value_to_stack(state, stk_a, value))
		return (0);
	return (1);
}

static int	process_arg(t_state *state, t_dlist *stk_a, char *arg)
{
	int	i;
	int	ret;
	int	count;

	i = 0;
	count = 0;
	while (arg[i])
	{
		ret = process_token(state, stk_a, arg, &i);
		if (ret == 0)
			return (0);
		if (ret == 1)
			count++;
	}
	return (count > 0);
}
// static int	valid_num(const char *num)
// {
// 	int	i;
// 	int	digits;

// 	i = 0;
// 	digits = 0;
// 	while (num[i] == ' ' || (9 <= num[i] && num[i] <= 13))
// 		i++;
// 	if (num[i] == '+' || num[i] == '-')
// 		i++;
// 	while (num[i])
// 	{
// 		if (!ft_isdigit(num[i]))
// 			return (0);
// 		digits = 1;
// 		i++;
// 	}
// 	return (digits);
// }

// static int	add_arg_to_stack(t_state *state, t_dlist *stk_a, char *arg)
// {
// 	int		value;
// 	t_node	*node;

// 	if (!valid_num(arg))
// 		return (0);
// 	value = ft_atoi(arg);
// 	if (list_has_value(stk_a, value))
// 		return (0);
// 	node = create_node(value);
// 	if (!node)
// 		return (0);
// 	dlist_addback(stk_a, node);
// 	state->len += 1;
// 	return (1);
// }

int	process_input(t_state *state, t_dlist *stk_a, char **av, int ac)
{
	int	i;

	init_state(state);
	i = 1;
	while (i < ac && av[i][0] == '-' && av[i][1] == '-')
	{
		if (!parse_flag(state, av[i] + 2))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		i++;
	}
	while (i < ac)
	{
		if (!process_arg(state, stk_a, av[i]))
		{
			clear_stack(stk_a);
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}
