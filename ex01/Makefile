# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mle-duc <mle-duc@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 16:55:24 by mle-duc           #+#    #+#              #
#    Updated: 2024/01/15 17:24:19 by mle-duc          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			ex01

CC =			c++

RM =			rm -f

SRCS =			main.cpp Fixed.cpp

OBJS =			${SRCS:.cpp=.o}

CPPFLAGS =		-Wall -Wextra -Werror -std=c++98

all: ${NAME}

.cpp.o:
	$(CC) ${CPPFLAGS} -c $< -o ${<:.cpp=.o}

${NAME}: ${OBJS}
	$(CC) $(OBJS) ${CPPFLAGS} -o $(NAME)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
