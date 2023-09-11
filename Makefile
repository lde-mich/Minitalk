# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 15:20:41 by lde-mich          #+#    #+#              #
#    Updated: 2023/03/28 14:37:20 by lde-mich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	client.c
SRCS1			=	server.c
SRCSB			=	client_bonus.c
SRCS1B			=	server_bonus.c

OBJS			= ${SRCS:.c=.o}
OBJS1			= ${SRCS1:.c=.o}
OBJSB			= ${SRCSB:.c=.o}
OBJS1B			= ${SRCS1B:.c=.o}


CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= client
NAME1			= server
NAMEB			= client_bonus
NAME1B			= server_bonus


${NAME}:		${OBJS} ${OBJS1}
				${CC} ${CFLAGS} ${OBJS} -o ${NAME}
				${CC} ${CFLAGS} ${OBJS1} -o ${NAME1}

all:			${NAME}

bonus:			${OBJSB} ${OBJS1B}
				${CC} ${CFLAGS} ${OBJSB} -o ${NAMEB}
				${CC} ${CFLAGS} ${OBJS1B} -o ${NAME1B}

clean:
				${RM} ${OBJS}
				${RM} ${OBJS1}
				${RM} ${OBJSB}
				${RM} ${OBJS1B}

fclean:			clean
				${RM} ${NAME}
				${RM} ${NAME1}
				${RM} ${NAMEB}
				${RM} ${NAME1B}
				${RM} client_bonus server_bonus

re:				fclean ${NAME}
				fclean ${NAME1}
				fclean ${NAMEB}
				fclean ${NAME1B}


.PHONY:			all clean fclean re bonus
