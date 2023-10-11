# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 20:37:48 by tatashir          #+#    #+#              #
#    Updated: 2023/10/12 01:38:40 by tatashir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= minishell

SRC			= main.c \
			  init.c \
			  sigset.c \
			  sighandler.c \
			  lexer.c \
			  lexer_gettoken.c \
			  lexer_string.c \
			  lexer_string_lst.c \
			  lexer_tokenlen.c \
			  parser.c \
			  parser_cmdnew.c \
			  parser_cmdnew_arg.c \
			  parser_cmdnew_input.c \
			  parser_cmdnew_output.c \
			  parser_cmdnew_fdsize.c \
			  getpath.c \
			  setpath.c \
			  exec.c \
			  exec_builtin.c \
			  exec_child.c \
			  fd.c \
			  env.c \
			  builtin_cd.c \
			  builtin_echo.c \
			  builtin_env.c \
			  builtin_exit.c \
			  builtin_export.c \
			  builtin_unset.c \
			  lstclear.c \
			  map_lst2map.c \
			  map_clear.c \
			  map_size.c \
			  strisdigit.c \
			  lexer_string_env.c \
			  builtin_pwd.c \
			  utils.c

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