NAME =		libft.a
CC =		@cc
CFLAGS =	-Wall -Werror -Wextra -I $(INC)
INC=		inc/
SRCS_DIR =	srcs/
SRCS = 		ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
			ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
			ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
			ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_calloc.c ft_strdup.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c \
			ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c get_next_line.c ft_itoa_base.c repeat_char.c \
			ft_union.c ft_atoli.c ft_isdiff.c

PRINTF_DIR=	$(SRCS_DIR)printf/
PRINTF=		ft_printf.c integers.c chars.c funct_utils.c get_flags.c flags.c
OBJS = 		$(addprefix $(SRCS_DIR), $(SRCS:%.c=%.o)) $(addprefix $(PRINTF_DIR), $(PRINTF:%.c=%.o))

%o:		%c
	$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

$(NAME): 	$(OBJS)
	@ar -rc $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)
	@find . -name ".DS_Store" -delete
	@find . -name "a.out" -delete
	@find . -name "*.swp" -delete
	@find . -name "*.gch" -delete
	@rm -rf *.dSYM

fclean: clean
	@rm -f $(NAME)

re: fclean all
