# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 20:37:48 by tatashir          #+#    #+#              #
#    Updated: 2023/10/07 15:05:39 by tatashir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC

SRCDIR = 
INCDIR = 
LIBDIR = 
OBJDIR = 

SRCS			= $(addprefix $(SRCDIR)/, $(SRC))
OBJS			= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
DEPS			= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.d)))
LIBS			= $(LIBDIR)/libft.a

CC = cc
RM = rm

CFLAGS = -Wall -Werror -Wextra