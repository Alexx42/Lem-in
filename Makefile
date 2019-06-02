NAME = lem-in
LIB = libft/libft.a
LIB_PRINTF = ft_printf/libftprintf.a
PRINTF_PATH = ft_printf/
INCLUDES = -I ./includes -I./libft/ -I ./ft_printf/
FLAGS = -Wall -Werror -Wextra
LIBFT_PATH = libft/
SRCS =  $(addprefix srcs/, main.c hash_table.c lists.c infos.c parsing.c queue.c graph.c error.c dispatch.c dispatch2.c bfs.c free.c get_paths.c)
OBJ = $(SRCS:.c=.o)
CC = gcc
RED = \x1b[31m
GREEN = \x1b[32m
RESET = \x1b[0m

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME):$(LIB_PRINTF) $(LIB) $(OBJ)
	@echo "$(GREEN)" Compiling lem-in... "$(RESET)"
	@$(CC) $(FLAGS) $(INCLUDES) $(SRCS) $(LIB) $(LIB_PRINTF) -o $(NAME)


$(LIB):
	@echo "$(GREEN)" Compiling libft... "$(RESET)"
	@make -C $(LIBFT_PATH)

$(LIB_PRINTF):
	@echo "$(GREEN)" Compiling ft_printf... "$(RESET)"
	@make -C $(PRINTF_PATH)


clean:
	@echo "$(RED)" Cleaning libft and ft_printf objects.. "$(RESET)"
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(PRINTF_PATH)
	@echo "$(RED)" Cleaning objects.. "$(RESET)"
	@rm -f $(OBJ)

fclean: clean
	@echo "$(RED)" Removing ft_printf and libft objects and executable... "$(RESET)"
	@make fclean -C $(LIBFT_PATH)
	@make fclean -C $(PRINTF_PATH)
	@echo "$(RED)" Removing objects and executables... "$(RESET)"
	@rm -f $(NAME) && rm -rf *.dSYM

re: fclean all
