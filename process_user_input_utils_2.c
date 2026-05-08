/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_user_input_utils_2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakiray <ecakiray@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 07:37:42 by ecakiray          #+#    #+#             */
/*   Updated: 2026/05/08 07:38:42 by ecakiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"
#include "push_swap.h"

int	is_strategy(char *arg)
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

int	parse_flag(t_state *state, char *arg)
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

int	read_sign(char *arg, int *i, int end)
{
	if (*i >= end)
		return (1);
	if (arg[*i] == '+' || arg[*i] == '-')
	{
		(*i)++;
		if (*i >= end)
			return (0);
	}
	return (1);
}

int	read_number(char *arg, int *i, int end, long long *num)
{
	while (*i < end)
	{
		if (!ft_isdigit(arg[*i]))
			return (0);
		*num = (*num * 10) + (arg[*i] - '0');
		if (*num > 2147483648LL)
			return (0);
		(*i)++;
	}
	return (1);
}
