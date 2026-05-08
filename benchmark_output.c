/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakiray <ecakiray@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 04:01:50 by ecakiray          #+#    #+#             */
/*   Updated: 2026/05/08 04:40:16 by ecakiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"
#include "push_swap.h"

static void	putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putstr_fd("-", fd);
		n = -n;
	}
	if (n >= 10)
		putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

static void	put_percentage(double disorder)
{
	int	value;
	int	whole;
	int	decimal;

	value = (int)((disorder * 10000.0) + 0.5);
	whole = value / 100;
	decimal = value % 100;
	putnbr_fd(whole, 2);
	ft_putstr_fd(".", 2);
	if (decimal < 10)
		ft_putstr_fd("0", 2);
	putnbr_fd(decimal, 2);
	ft_putstr_fd("%\n", 2);
}

static void	put_op_count(char *name, int count)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	putnbr_fd(count, 2);
	ft_putstr_fd("  ", 2);
}

static void	print_strategy(t_bench *bench)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(bench->strategy, 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(bench->complexity, 2);
	ft_putstr_fd("\n", 2);
}

void	print_benchmark(t_bench *bench, t_output *out)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	put_percentage(bench->disorder);
	print_strategy(bench);
	ft_putstr_fd("[bench] total_ops: ", 2);
	putnbr_fd(out->total_ops, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] ", 2);
	put_op_count("sa", out->op_count[0]);
	put_op_count("sb", out->op_count[1]);
	put_op_count("ss", out->op_count[2]);
	put_op_count("pa", out->op_count[3]);
	put_op_count("pb", out->op_count[4]);
	ft_putstr_fd("\n[bench] ", 2);
	put_op_count("ra", out->op_count[5]);
	put_op_count("rb", out->op_count[6]);
	put_op_count("rr", out->op_count[7]);
	put_op_count("rra", out->op_count[8]);
	put_op_count("rrb", out->op_count[9]);
	put_op_count("rrr", out->op_count[10]);
	ft_putstr_fd("\n", 2);
}
