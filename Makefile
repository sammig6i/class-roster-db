NAME        := roster

SRC_DIR     := src
OBJ_DIR     := obj
SRCS        := \
    main.cpp         \
    student.cpp      \
    roster.cpp
SRCS        := $(SRCS:%=$(SRC_DIR)/%)
OBJS        := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CC          := g++
CFLAGS      := -Wall -Wextra -Werror -std=c++11 -g
CPPFLAGS    := -I include

RM          := rm -f
MAKEFLAGS   += --no-print-directory
DIR_DUP     = mkdir -p $(@D)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(OBJS) -o $(NAME)
		@echo "CREATED $(NAME)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
		$(DIR_DUP)
		$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
		@echo "CREATED $@"

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re:
		$(MAKE) fclean
		$(MAKE) all


.PHONY: clean fclean re
.SILENT:

