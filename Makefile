NAME_SERVER = server
NAME_CLIENT = client
CC =	cc
CFLAGS = -Wall -Wextra -Werror
LIBFTPRINTF = utlis/libftprintf.a
C_SRCS = client.c utlis_minitalk.c
S_SRCS = server.c utlis_minitalk.c
S_OBG = $(S_SRCS:.c=.o)
C_OBG = $(C_SRCS:.c=.o)
INC = minitalk.h	   

all : $(NAME_CLIENT) $(NAME_SERVER)

client : $(C_OBG)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(C_OBG) $(LIBFTPRINTF)
server : $(S_OBG)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(S_OBG) $(LIBFTPRINTF)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(S_OBG) $(C_OBG)

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER) 

re: fclean all

.PHONY: clean fclean re
