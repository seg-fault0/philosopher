SRC =	srcs/exit.c			\
		srcs/init.c			\
		srcs/libft.c		\
		srcs/main.c			\
		srcs/philo_utils.c	\
		srcs/routine.c		\

OBG = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

NAME = philo

I = -I ./includes/

all : $(NAME)

$(NAME) : $(OBG)
	cc $(FLAGS) $^ -o $@

%.o : %.c ./includes/philo.h
	cc -c $< $(I) -o $@

clean :
	rm -f $(OBG)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean