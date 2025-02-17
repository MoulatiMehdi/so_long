# commands 
CC = cc
RM = rm 
AR = ar

# flags 
CCDEBUG = -g -fsanitize=address
CCFLAGS = -Wall -Wextra $(CCDEBUG) 
RMFLAGS = -rf 
ARFLAGS = -crs

# files
SRCS = $(wildcard ./*.c)
DEPS = $(wildcard ./*.h)
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a
NAME = so_long 

all :  $(LIBFT) $(NAME) 

$(NAME) :  $(OBJS) 
	$(CC) $(CCFLAGS) $^ -o $@   -lmlx_Linux -Lminilibx-linux/ -lXext -lX11 -lm -I./minilibx-linux/ -lft -Llibft

$(LIBFT) : 
	make -C libft --no-print-directory
%.o : %.c
	$(CC) $(CCFLAGS) $< -o $@ -c -lmlx_Linux -Lminilibx-linux/ -lXext -lX11 -lm -I./minilibx-linux/ -lft -Llibft

clean : 
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean 
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

.PHONY : re clean fclean all
