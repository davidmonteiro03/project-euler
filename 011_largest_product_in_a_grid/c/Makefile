# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 08:08:38 by dcaetano          #+#    #+#              #
#    Updated: 2025/03/27 16:28:58 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# === BINARY ================================================================= #

NAME     = solve_c
LIB      = $(NAME).a

# === COMMANDS =============================================================== #

CC       = cc
MK       = mkdir
RM       = rm
AR_RCS   = ar rcs

# === DIRECTORIES ============================================================ #

INCS_D   = includes
SRCS_D   = srcs
OBJS_D   = objs

# === EXTENSIONS ============================================================= #

C_EXT    = .c
H_EXT    = .h
O_EXT    = .o

# === FILES ================================================================== #

CFILES   = solution/init solution/execute
HFILES   = $(NAME) solution

INCS     = $(addprefix $(INCS_D)/, \
                       $(addsuffix $(H_EXT), \
                       $(HFILES)))
SRCS     = $(addprefix $(SRCS_D)/, \
                       $(addsuffix $(C_EXT), \
                       $(CFILES)))
OBJS     = $(patsubst $(SRCS_D)/%$(C_EXT), \
                      $(OBJS_D)/$(SRCS_D)/%$(O_EXT), \
                      $(SRCS))

SOLVE_C  = solve$(C_EXT)
SOLVE_O  = $(patsubst %$(C_EXT), \
                      $(OBJS_D)/%$(O_EXT), \
                      $(SOLVE_C))

# === FLAGS ================================================================== #

C_FLAGS  = -Wall -Wextra -Werror
MK_FLAGS = -p
RM_FLAGS = -rfv

# === RULES ================================================================== #

all: $(NAME)

$(OBJS_D)/%$(O_EXT): %$(C_EXT) $(INCS)
	@$(MK) $(MK_FLAGS) $(dir $@) > /dev/null 2>&1
	@$(CC) $(C_FLAGS) -c $< -o $@ #> /dev/null 2>&1

$(OBJS_D)/$(SRCS_D)/%$(O_EXT): $(SRCS_D)/%$(C_EXT) $(INCS)
	@$(MK) $(MK_FLAGS) $(dir $@) > /dev/null 2>&1
	@$(CC) $(C_FLAGS) -c $< -o $@ #> /dev/null 2>&1

$(LIB): $(OBJS)
	@$(AR_RCS) $(LIB) $(OBJS) > /dev/null 2>&1

$(NAME): $(LIB) $(SOLVE_O)
	@$(CC) $(C_FLAGS) $(SOLVE_O) $(LIB) -o $(NAME) > /dev/null 2>&1

clean:
	@$(RM) $(RM_FLAGS) $(OBJS_D)

fclean: clean
	@$(RM) $(RM_FLAGS) $(NAME) $(LIB)

re: fclean all

.PHONY: all clean fclean re
