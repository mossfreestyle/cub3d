NAME = libft.a

MY_OPTIONS = -I -c $(MY_INCLUDES)

MY_SOURCES = ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_strcmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c  \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_swap.c \
			gnl/get_next_line.c \
    		gnl/get_next_line_utils.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

MY_SOURCES_BONUS = ft_lstnew.c \
					ft_lstadd_front.c \
					ft_lstsize.c \
					ft_lstlast.c \
					ft_lstadd_back.c \
					ft_lstdelone.c \
					ft_lstclear.c \
					ft_lstiter.c \
					ft_lstmap.c 

MY_OBJECTS_BONUS = $(MY_SOURCES_BONUS:.c=.o)

MY_INCLUDES = -I. -Ignl

CC = cc

CFLAGS = -Wall -Wextra -Werror -fPIC

MY_OPTIONS = -I -c $(MY_INCLUDES)

all : $(NAME) 

$(NAME) : $(MY_OBJECTS)
	@ar rcs $(NAME) $(MY_OBJECTS)

bonus : $(MY_OBJECTS) $(MY_OBJECTS_BONUS)
	@ar rcs $(NAME) $(MY_OBJECTS_BONUS)

%.o: %.c
	@$(CC) $(CFLAGS) $(MY_INCLUDES) -c $< -o $@

clean :  
	@rm -f $(MY_OBJECTS) $(MY_OBJECTS_BONUS)

fclean : clean 
	@rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re all