##
## Makefile for Makefile in /home/plasko_a/projet/epitech/PSU_2014_zappy
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.eu>
## 
## Started on  Tue Jun 16 16:38:09 2015 Antoine Plaskowski
## Last update Thu Jun 18 17:44:35 2015 Antoine Plaskowski
##

SERVER		=	server

CLIENT_AI	=	client_ai

CC		?=	gcc

CXX		?=	g++

RM		=	rm

DEBUG		?=	no

LEVEL		?=	3

COLOR		?=	no

LIB		=

INCLUDE		=	-I include -I include/server -I include/client_ai

CFLAGS		+=	-Wall -Wextra -O$(LEVEL)
CFLAGS		+=	-ansi -pedantic
CFLAGS		+=	$(INCLUDE)
CFLAGS          +=      -D _POSIX_SOURCE -D _GNU_SOURCE -D _XOPEN_SOURCE

CXXFLAGS	+=	-Wall -Wextra -O$(LEVEL)
CXXFLAGS	+=	-ansi -pedantic
CXXFLAGS	+=	$(INCLUDE)

ifeq ($(CC), clang)
CFLAGS		+=	-Weverything -Wno-padded
endif

ifeq ($(CXX), clang++)
CXXFLAGS	+=	-Weverything -Wno-padded
endif

ifneq ($(DEBUG), no)
CFLAGS		+=	-g
CXXFLAGS	+=	-g
endif

ifneq ($(COLOR), no)
CFLAGS		+=	-f diagnostics-color
CXXFLAGS	+=	-f diagnostics-color
endif

LDFLAGS		=	$(LIB)

ifeq ($(DEBUG), no)
LDFLAGS		+=	-s
endif

include			source_server.mk
include			source_client_ai.mk

DPD_SERVER	=	$(SRC_SERVER:.c=.dpd)

OBJ_SERVER	=	$(SRC_SERVER:.c=.o)

DPD_CLIENT_AI	=	$(SRC_CLIENT_AI:.cpp=.dpd)

OBJ_CLIENT_AI	=	$(SRC_CLIENT_AI:.cpp=.o)

all		:	$(SERVER) $(CLIENT_AI)

$(SERVER)	:	$(OBJ_SERVER)
			$(CC) $(OBJ_SERVER) -o $(SERVER) $(LDFLAGS)

$(CLIENT_AI)	:	$(OBJ_CLIENT_AI)
			$(CXX) $(OBJ_CLIENT_AI) -o $(CLIENT_AI) $(LDFLAGS)

clean		:
			$(RM) -f $(OBJ_SERVER)
			$(RM) -f $(OBJ_CLIENT_AI)
			$(RM) -f $(DPD_SERVER)
			$(RM) -f $(DPD_CLIENT_AI)

fclean		:	clean
			$(RM) -f $(SERVER)
			$(RM) -f $(CLIENT_AI)

re		:	fclean all

%.dpd		:	%.c
			$(CC) -MM $(<) -o $(@) $(CFLAGS) -MT $(<:.c=.o)

%.o		:	%.c
			$(CC) -c $(<) -o $(@) $(CFLAGS)

%.dpd		:	%.cpp
			$(CXX) -MM $(<) -o $(@) $(CXXFLAGS) -MT $(<:.cpp=.o)

%.o		:	%.cpp
			$(CXX) -c $(<) -o $(@) $(CXXFLAGS)

.PHONY		:	all clean fclean re %.dpd %.o

.SUFFIXES	:	.o.c .dpd.c .o.cpp .dpd.cpp

include			$(DPD_SERVER) $(DPD_CLIENT_AI)
