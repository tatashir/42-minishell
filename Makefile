# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 20:37:48 by tatashir          #+#    #+#              #
#    Updated: 2023/10/12 00:37:18 by tatashir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= minishell

SRC			= ms_main.c \
			  ms_init.c \
			  ms_sigset.c \
			  ms_sighandler.c \
			  ms_lexer.c \
			  ms_lexer_gettoken.c \
			  ms_lexer_string.c \
			  ms_lexer_string_env.c \
			  ms_lexer_string_lst.c \
			  ms_lexer_tokenlen.c \
			  ms_parser.c \
			  ms_parser_cmdnew.c \
			  ms_parser_cmdnew_arg.c \
			  ms_parser_cmdnew_input.c \
			  ms_parser_cmdnew_output.c \
			  ms_parser_cmdnew_fdsize.c \
			  ms_getpath.c \
			  ms_setpath.c \
			  ms_exec.c \
			  ms_exec_builtin.c \
			  ms_exec_child.c \
			  ms_fd.c \
			  ms_env.c \
			  ms_builtin_cd.c \
			  ms_builtin_echo.c \
			  ms_builtin_env.c \
			  ms_builtin_exit.c \
			  ms_builtin_export.c \
			  ms_builtin_pwd.c \
			  ms_builtin_unset.c \
			  ms_lstclear.c \
			  ms_map_lst2map.c \
			  ms_map_clear.c \
			  ms_map_size.c \
			  ms_strisdigit.c \
			  ms_utils.c

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