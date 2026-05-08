/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakiray <ecakiray@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 15:59:07 by bkusi-fr          #+#    #+#             */
/*   Updated: 2026/05/08 04:11:27 by ecakiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

typedef struct s_state
{
	size_t			len;
	char			is_benchmark_mode;
	char			mode[10];
}					t_state;

typedef struct s_node
{
	int				data;
	int				rank;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_dlist
{
	struct s_node	*head;
	struct s_node	*tail;
}					t_dlist;

typedef struct s_output
{
	char			pending[4];
	int				total_ops;
	int				op_count[11];
}					t_output;

typedef struct s_bench
{
	double			disorder;
	char			*strategy;
	char			*complexity;
}					t_bench;

void		init_state(t_state *state);
int			process_input(t_state *state, t_dlist *stk_a, char **av, int ac);
void		populate_stack(t_dlist *stk);
t_node		*create_node(int num);
void		dlist_addfront(t_dlist *lst, t_node *new);
void		dlist_addback(t_dlist *lst, t_node *new);
t_node		*dlist_popfront(t_dlist *lst);
void		init_dlist(t_dlist *lst);
void		dlist_rotate(t_dlist *lst, int dxn);
int			px(t_dlist *origin, t_dlist *dest);
void		rx(t_dlist *stk);
void		rr(t_dlist *stk_a, t_dlist *stk_b);
void		rrx(t_dlist *stk);
void		rrr(t_dlist *stk_a, t_dlist *stk_b);
void		sx(t_dlist *stk);
void		ss(t_dlist *stk_a, t_dlist *stk_b);
double		compute_disorder_dlist(t_dlist *st);
void		selection_sort(t_dlist *st_a, t_dlist *st_b, int mx, t_output *out);
void		radix_sort(t_dlist *st_a, t_dlist *st_b, int mx, t_output *out);
void		butterfly_sort(t_dlist *a, t_dlist *b, int mx, t_output *out);
void		block_based_sort(t_dlist *a, t_dlist *b, int mx, t_output *out);
int			find_node(t_dlist *lst, int tg);
void		perform_rotations(t_dlist *st, int cnt, int dxn, char stack_name, t_output *out);
void		init_output(t_output *out);
void		emit_op(t_output *out, char *op);
void		flush_op(t_output *out);
void		print_benchmark(t_bench *bench, t_output *out);

#endif
