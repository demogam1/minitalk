CC=gcc
AR=ar
ARFLAGS=rc
SERVER=server
CLIENT=client
SERVER_BONUS=bonus/server_bonus
CLIENT_BONUS=bonus/client_bonus
FLAGS= -Wall -Werror -Wextra
NAME=minitalk.a
BONUS= bonus/server_bonus.c \
	bonus/client_bonus.c \

SRC= client.c \
	server.c \

LIBFT=  libft/ft_memset.c \
	   libft/ft_bzero.c \
	   libft/ft_memcpy.c \
	   libft/ft_memccpy.c \
	   libft/ft_memmove.c \
	   libft/ft_memchr.c \
	   libft/ft_memcmp.c \
	   libft/ft_strlen.c \
	   libft/ft_strdup.c \
	   libft/ft_strlcat.c \
	   libft/ft_strchr.c \
	   libft/ft_strrchr.c \
	   libft/ft_strnstr.c \
	   libft/ft_strncmp.c \
	   libft/ft_atoi.c \
	   libft/ft_strlcpy.c \
	   libft/ft_calloc.c \
	   libft/ft_isalpha.c \
	   libft/ft_isdigit.c \
	   libft/ft_isalnum.c \
	   libft/ft_isascii.c \
	   libft/ft_isprint.c \
	   libft/ft_toupper.c \
	   libft/ft_tolower.c \
	   libft/ft_strmapi.c \
	   libft/ft_split.c \
	   libft/ft_substr.c \
	   libft/ft_strjoin.c \
	   libft/ft_strtrim.c \
	   libft/ft_itoa.c \
	   libft/ft_putchar_fd.c \
	   libft/ft_putstr_fd.c \
	   libft/ft_putendl_fd.c \
	   libft/ft_putnbr_fd.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)


$(NAME): $(OBJ)
	make -C libft/
	mv libft/libft.a ./minitalk.a
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	$(CC) -o $(SERVER) server.c $(NAME)
	$(CC) -o $(CLIENT) client.c $(NAME)

bonus : $(NAME) $(OBJ)
	make -C libft/
	mv libft/libft.a ./minitalk.a
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	$(CC) -o $(SERVER_BONUS) bonus/server_bonus.c $(NAME)
	$(CC) -o $(CLIENT_BONUS) bonus/client_bonus.c $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@
clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(SERVER) $(CLIENT) $(CLIENT_BONUS) $(SERVER_BONUS) 

re: fclean all
