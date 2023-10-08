# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 20:37:48 by tatashir          #+#    #+#              #
#    Updated: 2023/10/08 18:29:12 by tatashir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= minishell

SRC 		= 

SRCDIR		= ./src
INCDIR		= ./include
LIBDIR		= ./libft
OBJDIR		= ./obj

SRCS		= $(addprefix $(SRCDIR)/, $(SRC))
OBJS		= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
DEPS		= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.d)))
LIBS		= $(LIBDIR)/libft.a

CC			= cc
RM			= rm -r

CFLAGS		= -Wall -Werror -Wextra

INCLUDES	= -I$(INCDIR) -I$(LIBDIR)/include -I$(shell brew --prefix readline)/include/
LDFLAGS		= -L$(shell brew --prefix readline)/lib -lreadline


.PHONY:		all clean fclean re clean_partly 

all: $(LIBS) $(NAME)
clean:
	$(MAKE) clean -C $(LIBDIR)
	-$(RM) $(OBJDIR)
fclean: 
	$(MAKE) fclean -C $(LIBDIR)
	-$(RM) $(OBJDIR)
	-$(RM) $(NAME)
re: fclean all


$(NAME): $(OBJS)
	$(CC) $(INCLUDES) $(OBJS) $(LIBS) $(LDFLAGS) -o $(NAME)
$(LIBS):
	$(MAKE) -C $(LIBDIR)
$(OBJDIR):
	@mkdir -p $@
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<