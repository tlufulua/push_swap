NAME		=	push_swap
CC			=	@gcc
CFLAGS		=	-Wall -Werror -Wextra -I $(INC) -I $(LIBFT_INC)
INC			=	inc/
SRCS_DIR	=	srcs/
SRCS		=	push_swap.c utils.c utils2.c push_swap_funct.c rotate_funct.c \
				rotate_funct2.c simple_cases.c hard_cases.c error.c
LIBFT_DIR	=	$(INC)libft/
LIBFT_INC	=	$(LIBFT_DIR)inc/
LIBFT		=	$(LIBFT_DIR)libft.a
OBJS		=	$(addprefix $(SRCS_DIR), $(SRCS:%.c=%.o))

all:	$(NAME)

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@find . -name "*.o" -delete
	@find . -name "*.swp" -delete
	@find . -name ".DS_Store" -delete
	@find . -name "*.gch" -delete
	@make clean -C $(LIBFT_DIR)

fclean:	clean
	@find . -name "$(NAME)" -delete
	@make fclean -C $(LIBFT_DIR)

re:		fclean all
