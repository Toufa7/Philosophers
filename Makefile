# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otoufah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 14:20:58 by otoufah           #+#    #+#              #
#    Updated: 2022/06/21 09:26:49 by otoufah          ###   ########.fr        #s
#                                                                              #
# **************************************************************************** #

NAME	=	philo

FLAGS	=	-Wall -Werror -Wextra -fsanitize=thread

REMOVE	=	rm -rf

COMPILING	=	gcc 

FUNCTIONS	=	creating_philos.c\
				ft_atoi.c\
				ft_strlen.c\
				ft_eat.c\
				ft_get_time.c\
				ft_grab_fork.c\
				ft_mutex_init.c\
				ft_release_fork.c\
				ft_sleep.c\
				ft_think.c\
				ft_is_dead.c\
				ft_check_args.c\
				colors.c\

OBJECTS	=	$(FUNCTIONS:.c=.o)

all	: $(NAME)

$(NAME)	:	$(OBJECTS)
			$(COMPILING) $(FLAGS) $(OBJECTS) main.c -o $(NAME)

clean	:	
			$(REMOVE) $(OBJECTS)

fclean	:	clean
			$(REMOVE) $(OBJECTS) $(NAME)

re	:	fclean all
