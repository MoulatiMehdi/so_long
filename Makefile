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

all : $(NAME) 

$(NAME) : $(OBJS)
	$(CC) $(CCFLAGS) $^ -o $@  -lmlx_Linux -lXext -lX11 -lm

%.o : %.c
	$(CC) $(CCFLAGS) $< -o $@ -c 

clean : 
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean 
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

.PHONY : re clean fclean all
