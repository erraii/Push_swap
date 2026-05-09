/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakiray <ecakiray@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 15:59:07 by bkusi-fr          #+#    #+#             */
/*   Updated: 2026/05/08 07:40:24 by ecakiray         ###   ########.fr       */
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

typedef struct s_radix_cycle
{
	int				len;
	int				bit;
}					t_radix_cycle;

typedef struct s_block
{
	int				start;
	int				end;
	int				mid;
}					t_block;

void				init_state(t_state *state);
int					process_input(t_state *state, t_dlist *stk_a, char **av,
						int ac);
void				populate_stack(t_dlist *stk);
t_node				*create_node(int num);
void				dlist_addfront(t_dlist *lst, t_node *new);
void				dlist_addback(t_dlist *lst, t_node *new);
t_node				*dlist_popfront(t_dlist *lst);
void				dlist_rotate(t_dlist *lst, int dxn);
int					px(t_dlist *origin, t_dlist *dest);
void				rx(t_dlist *stk);
void				rr(t_dlist *stk_a, t_dlist *stk_b);
void				rrx(t_dlist *stk);
void				rrr(t_dlist *stk_a, t_dlist *stk_b);
void				sx(t_dlist *stk);
void				ss(t_dlist *stk_a, t_dlist *stk_b);
double				compute_disorder_dlist(t_dlist *st);
void				selection_sort(t_dlist *st_a, t_dlist *st_b, int mx,
						t_output *out);
void				radix_sort(t_dlist *st_a, t_dlist *st_b, int mx,
						t_output *out);
void				butterfly_sort(t_dlist *a, t_dlist *b, int mx,
						t_output *out);
void				block_based_sort(t_dlist *a, t_dlist *b, int mx,
						t_output *out);
int					find_node(t_dlist *lst, int tg);
void				rotate_st(t_dlist *st, int cnt, t_output *out,
						char stack_name);
void				rev_rotate_st(t_dlist *st, int cnt, t_output *out,
						char stack_name);
void				emit_op(t_output *out, char *op);
void				flush_op(t_output *out);
void				print_benchmark(t_bench *bench, t_output *out);
void				clear_stack(t_dlist *lst);
int					add_value_to_stack(t_state *state, t_dlist *stk_a,
						int value);
int					list_has_value(t_dlist *lst, int value);
int					is_strategy(char *arg);
int					parse_flag(t_state *state, char *arg);
int					read_sign(char *arg, int *i, int end);
int					read_number(char *arg, int *i, int end, long long *num);
int					stack_len(t_dlist *stk);
void				init_dlist(t_dlist *lst);
void				init_all_vars(t_state *input, t_dlist *sa, t_dlist *sb);
void				set_forced_bench(t_state *state, t_bench *bench);
void				set_node_ranks(t_dlist *stk);
void				brute_force_sort(t_dlist *a, t_dlist *b, int mx,
						t_output *out);
#endif
