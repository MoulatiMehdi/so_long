# commands 
CC = cc
RM = rm 
AR = ar

# flags 
CCLIBS  = -lmlx_Linux -Lminilibx-linux/ -lft -Llibft -lXext -lX11 -lm 
CCDEBUG = -g 
CCFLAGS = -Wall -Wextra $(CCDEBUG) 

RMFLAGS = -rf 

DIR_OBJS = objs
DIR_SRCS = .
DIR_DEPS = .

# files
SRCS = $(wildcard *.c)
DEPS = $(wildcard *.h)
OBJS = $(addprefix $(DIR_OBJS)/,$(SRCS:.c=.o))

LIBFT = libft/libft.a
NAME = so_long 

all :  $(LIBFT) $(NAME) 

$(NAME) :  $(OBJS) 
	$(CC) $(CCFLAGS) $^ -o $@ -I./minilibx-linux/  $(CCLIBS)

$(DIR_OBJS)/%.o : %.c $(DIR_OBJS)
	$(CC) $(CCFLAGS) $< -o $@ -c  -I./minilibx-linux/  $(CCLIBS)

$(DIR_OBJS) : 
	mkdir $(DIR_OBJS)

$(LIBFT) : 
	make -C libft --no-print-directory
clean : 
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean 
	make fclean -C libft --no-print-directory
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

.PHONY : re clean fclean all
