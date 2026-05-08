/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakiray <ecakiray@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 09:20:09 by bkusi-fr          #+#    #+#             */
/*   Updated: 2026/05/08 06:19:04 by ecakiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"
#include "push_swap.h"
#include <stdio.h>

// void	print_dlist(t_dlist *lst)
// {
// 	t_node	*trav;

// 	if (!lst || !lst->head)
// 		return ;
// 	trav = lst->head;
// 	do
// 	{
// 		if (trav)
// 			printf("%d ", trav->data);
// 		trav = trav->next;
// 	} while (trav && trav != lst->head);
// 	printf("\n");
// }

static void	init_dlist(t_dlist *lst)
{
	lst->head = 0;
	lst->tail = 0;
}

static void	init_all_vars(t_state *input, t_dlist *sa, t_dlist *sb)
{
	init_state(input);
	init_dlist(sa);
	init_dlist(sb);
}

static void	set_forced_bench(t_state *state, t_bench *bench)
{
	if (ft_strncmp(state->mode, "simple", 7) == 0)
	{
		bench->strategy = "Simple";
		bench->complexity = "O(n^2)";
	}
	else if (ft_strncmp(state->mode, "medium", 7) == 0)
	{
		bench->strategy = "Medium";
		bench->complexity = "O(n√n)";
	}
	else if (ft_strncmp(state->mode, "complex", 8) == 0)
	{
		bench->strategy = "Complex";
		bench->complexity = "O(n log n)";
	}
}

static int	stack_len(t_dlist *stk)
{
	t_node	*cur;
	int		len;

	if (!stk || !stk->head)
		return (0);
	len = 1;
	cur = stk->head->next;
	while (cur != stk->head)
	{
		len++;
		cur = cur->next;
	}
	return (len);
}

static void	run_adap_sort(t_dlist *a, t_dlist *b, t_output *out, t_bench *bench)
{
	int	len;

	len = stack_len(a);
	bench->strategy = "Adaptive";
	if (bench->disorder < 0.2)
	{
		bench->complexity = "O(n^2)";
		selection_sort(a, b, len, out);
	}
	else if (bench->disorder < 0.5)
	{
		bench->complexity = "O(n√n)";
		butterfly_sort(a, b, len, out);
	}
	else
	{
		bench->complexity = "O(n log n)";
		radix_sort(a, b, len, out);
	}
}

static void	init_output(t_output *out)
{
	int	i;

	out->pending[0] = '\0';
	out->total_ops = 0;
	i = 0;
	while (i < 11)
	{
		out->op_count[i] = 0;
		i++;
	}
}

static void	run_selected_sort(t_state *state, t_dlist *stk_a, t_dlist *stk_b)
{
	t_output	out;
	t_bench		bench;

	init_output(&out);
	bench.disorder = compute_disorder_dlist(stk_a);
	bench.strategy = "Adaptive";
	bench.complexity = "O(n^2)";
	set_forced_bench(state, &bench);
	if (state->len >= 2 && bench.disorder != 0)
	{
		if (ft_strncmp(state->mode, "simple", 7) == 0)
			selection_sort(stk_a, stk_b, state->len, &out);
		else if (ft_strncmp(state->mode, "medium", 7) == 0)
			butterfly_sort(stk_a, stk_b, state->len, &out);
		else if (ft_strncmp(state->mode, "complex", 8) == 0)
			radix_sort(stk_a, stk_b, state->len, &out);
		else
			run_adap_sort(stk_a, stk_b, &out, &bench);
	}
	flush_op(&out);
	if (state->is_benchmark_mode)
		print_benchmark(&bench, &out);
}
// void	transfer_arr_to_stack(t_dlist *stk, int *arr, int len)
// {
// 	t_node	*node;

// 	while (--len > -1)
// 	{
// 		node = create_node(arr[len]);
// 		dlist_addfront(stk, node);
// 	}
// }

int	main(int ac, char **av)
{
	t_state	user_input;
	t_dlist	stk_a;
	t_dlist	stk_b;

	init_all_vars(&user_input, &stk_a, &stk_b);
	if (!process_input(&user_input, &stk_a, av, ac))
		return (1);
	// transform_input(&user_input);
	// transfer_arr_to_stack(&stk_a, user_input.arr, user_input.len);
	populate_stack(&stk_a);
	//butterfly_sort(&stk_a, &stk_b, user_input.len);
	run_selected_sort(&user_input, &stk_a, &stk_b);
	//print_dlist(&stk_a);
	return (0);
}
