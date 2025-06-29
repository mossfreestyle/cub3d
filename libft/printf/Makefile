NAME = libftprintf.a

MY_OPTIONS = -I -c $(MY_INCLUDES)

MY_SOURCES = ft_printf.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putnbr.c \
			ft_putnbr_base.c \
			ft_putptr.c \
			ft_putnbr_us.c


MY_OBJECTS = $(MY_SOURCES:.c=.o)

MY_INCLUDES = libftprintf.h

CC = cc

CFLAGS = -Wall -Wextra -Werror

MY_OPTIONS = -I -c $(MY_INCLUDES)

all : $(NAME) 

$(NAME) : $(MY_OBJECTS)
	@ar rcs $(NAME) $(MY_OBJECTS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :  
	@rm -f $(MY_OBJECTS) 

fclean : clean 
	@rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re all