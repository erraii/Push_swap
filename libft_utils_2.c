/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakiray <ecakiray@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:17:18 by ecakiray          #+#    #+#             */
/*   Updated: 2026/05/07 14:36:31 by ecakiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	src_len;

	if (s)
	{
		src_len = 0;
		while (s[src_len])
		{
			ft_putchar_fd(s[src_len], fd);
			src_len++;
		}
	}
}

static int	check_begin(char *str, int *sign, int *i)
{
	while ((str[*i] == ' ') || str[*i] == '\n' || str[*i] == '\t'
		|| str[*i] == '\r' || str[*i] == '\f' || str[*i] == '\v')
		(*i)++;
	if (str[*i] == '-')
	{
		*sign *= -1;
		(*i)++;
		return (1);
	}
	else if (str[*i] == '+')
	{
		(*i)++;
		return (1);
	}
	else if ((str[*i] >= '0') && str[*i] <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	i;
	int	result;

	result = 0;
	sign = 1;
	i = 0;
	if (check_begin((char *)nptr, &sign, &i) == 1)
	{
		while (nptr[i])
		{
			if ((nptr[i] >= '0') && (nptr[i] <= '9'))
			{
				result *= 10;
				result += (nptr[i] - 48);
			}
			else
				return (sign * result);
			i++;
		}
	}
	else
		return (0);
	return (sign * result);
}
