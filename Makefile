SRC = \
	server.c \
	client.c \
	
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
SERVER = server
CLIENT = client

# Doğru yol tanımlamaları
PRINTF_DIR = lib/ft_printf/
LIBFT_DIR = lib/libft/
PRINTF = $(PRINTF_DIR)libftprintf.a
LIBFT = $(LIBFT_DIR)libft.a

all: $(LIBFT) $(PRINTF) server client 

server: server.o
	$(CC) $(CFLAGS) server.o $(PRINTF) -o $(SERVER)

client: client.o
	$(CC) $(CFLAGS) client.o $(LIBFT) $(PRINTF) -o $(CLIENT)

#libftprintf.a:
#	make -C lib/ft_printf

#libft.a:
#	make -C lib/libft

clean:
	rm -f $(OBJ)
	make -C lib/ft_printf clean
	make -C lib/libft clean

fclean: clean
		rm -f server client libft.a libftprintf.a

re: fclean all

.PHONY: all libft libftprintf clean fclean re