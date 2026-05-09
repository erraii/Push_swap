/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_user_input.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakiray <ecakiray@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 15:59:24 by bkusi-fr          #+#    #+#             */
/*   Updated: 2026/05/08 07:51:40 by ecakiray         ###   ########.fr       */
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

static int	parse_int_token(char *arg, int start, int end, int *value)
{
	int			i;
	int			sign;
	long long	num;

	i = start;
	sign = 1;
	num = 0;
	if (arg[i] == '-')
		sign = -1;
	if (!read_sign(arg, &i, end))
		return (0);
	if (!read_number(arg, &i, end, &num))
		return (0);
	num *= sign;
	if (num < -2147483648LL || num > 2147483647LL)
		return (0);
	*value = (int)num;
	return (1);
}

static int	process_token(t_state *state, t_dlist *stk_a, char *arg, int *i)
{
	int	start;
	int	value;

	while (arg[*i] && (arg[*i] == ' ' || (9 <= arg[*i] && arg[*i] <= 13)))
		(*i)++;
	if (!arg[*i])
		return (2);
	start = *i;
	while (arg[*i] && !(arg[*i] == ' ' || (9 <= arg[*i] && arg[*i] <= 13)))
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
