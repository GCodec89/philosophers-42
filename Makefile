# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 16:12:02 by gonolive          #+#    #+#              #
#    Updated: 2024/12/09 18:29:52 by gonolive         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo
CC			=	cc
SRCS		=	srcs/main.c \
				srcs/inits.c \
				srcs/freeza.c \
				utils/ft_atoi.c \
				utils/ft_atol.c \
				validation/check_args.c \

CFLAGS		=	-Wall -Werror -Wextra -g
RM			=	rm -f
OBJS		=	$(SRCS:%.c=%.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			$(RM) $(OBJS)
			
clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
			
re:			fclean all

.PHONY:		all clean fclean re