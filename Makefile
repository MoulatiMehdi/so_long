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
NAME = so_long 
LIBFT = libft/libft.a

all : $(NAME) 

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CCFLAGS) $^ -o $@  -lmlx_Linux -lXext -lX11 -lm -lft -Llibft

$(LIBFT) : 
	make -C libft --no-print-directory

%.o : %.c
	$(CC) $(CCFLAGS) $< -o $@ -c 

clean : 
	$(RM) $(RMFLAGS) $(OBJS)
	make clean -C libft --no-print-directory

fclean : clean 
	$(RM) $(RMFLAGS) $(NAME)
	make fclean -C libft --no-print-directory

re : fclean all

.PHONY : re clean fclean all
