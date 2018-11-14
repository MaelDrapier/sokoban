##
## Makefile for *project_name* in /home/mael.drapier/bin
## 
## Made by mael drapier
## Login   <mael.drapier@epitech.net>
## 
## Started on  Tue Nov  8 16:48:53 2016 mael drapier
## Last update Tue Dec 20 18:17:53 2016 mael drapier
##

CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-W -Wextra -Wall -Werror
CFLAGS	+=	-I include/

LDFLAGS	=	-lncurses

NAME	=	my_sokoban

SRCS	=	src/display.c \
		src/game.c \
		src/event1.c \
		src/map_tab.c \
		src/bonus_win.c \
		src/main.c

OBJS	=	$(SRCS:.c=.o)


all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
