CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRC = main.c \
		process_user_input.c \
		process_user_input_utils_1.c \
		process_user_input_utils_2.c \
		linked_list_utils.c \
		push_swap_utils_1.c \
		push_swap_utils_2.c \
		helper_funcs_1.c \
		helper_funcs_2.c \
		operation_output.c \
		benchmark_output.c \
		sorting_algo_simple.c \
		sorting_algo_complex.c \
		sorting_algo_medium.c \
		libft_utils_1.c \
		libft_utils_2.c
NAME = push_swap
OBJS = $(SRC:.c=.o)
$(NAME): all
all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
clean: 
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all