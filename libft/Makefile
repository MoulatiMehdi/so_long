CC = cc 
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = crs
NAME = libft.a

SRCS = ft_atoi.c     ft_isdigit.c       ft_lstdelone.c   ft_lstsize.c  ft_min.c         ft_strchr.c     ft_strlcpy.c  ft_strs_dup.c ft_bzero.c    ft_isprint.c       ft_lstiter.c     ft_memchr.c   ft_putchar_fd.c  ft_strconcat.c  ft_strlen.c   ft_strtrim.c ft_calloc.c   ft_itoa.c          ft_lstlast.c     ft_memcmp.c   ft_putendl_fd.c  ft_strdup.c     ft_strmapi.c  ft_substr.c ft_isalnum.c  ft_lstadd_back.c   ft_lstmap.c      ft_memcpy.c   ft_putnbr_fd.c   ft_striteri.c   ft_strncmp.c  ft_tolower.c ft_isalpha.c  ft_lstadd_front.c  ft_lstnew.c      ft_memmove.c  ft_putstr_fd.c   ft_strjoin.c    ft_strnstr.c  ft_toupper.c ft_isascii.c  ft_lstclear.c      ft_lst_remove.c  ft_memset.c   ft_split.c       ft_strlcat.c    ft_strrchr.c  get_next_line.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c libft.h
	$(CC) $(CFLAGS) $< -c -o $@

$(NAME) : $(OBJS) 
	$(AR) $(ARFLAGS) $(NAME) $?

clean : 
	rm -rf $(OBJS) 
fclean : clean 
	rm -rf $(NAME)

re : fclean all

.SECONDARY : $(OBJS)
.PHONY : all clean fclean re
