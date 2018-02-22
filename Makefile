###############################################################################
##                                                                           ##
##  This is a generalized makefiles made to be used on different kind        ##
##  of projects, such as making libraries , source files etc.                ##
##  Please note that to use this make files you need to posses the `.misc`   ##
##  directory that is included in the repo by default. This path is needed   ##
##  as some files used by make files are included there. Do change anything  ##
##  dependeing on your need.                                                 ##
##                                                                           ##
##  In the file `color` located in `.misc/make` you can find terminal escape ##
##  codes for colors arr or remove or eddid to get result as you want.       ##
##                                                                           ##
##                                                                           ##
##  In the file `path` located in `.misc/make` information about varius paths##
##  are included for to make this Makefile easier and to manage the make file##
##  More easily.                                                             ##
##                                                                           ##
###############################################################################


## Please do not remove the includes
## as they contain impoirtent information
## variables and rules

include .misc/make/color
include .misc/make/paths
include .misc/make/misc_var

## Te `.SILENT` launche evrything specified in
## silent mode so you dont have to put the `@`
.SILENT	: __START	NAME	clean fclean all re object library os_dep
.PHONY	: __START			clean fclean all re object library os_dep


## This is launched if no param given
.DEFAULT_GOAL = __START

## Project name (will be used)
PROJECT	=	FDF

## compiler related
CC		?=	clang 		## default compiler is clang
CC_FLAG ?=	-Werror \
			-Wall	\
			-Wextra \
			-O1 -g -fsanitize=address	\
			-fno-omit-frame-pointer		\
			-fsanitize-address-use-after-scope \
			-lm \

CC_FLAG_ASAN ?=	-O1 -g -fsanitize=address	\
			-fno-omit-frame-pointer		\
			-fsanitize-address-use-after-scope \

## some useful `flags` for memory verifications
##
## -O1 -g -fsanitize=address	\
## -fno-omit-frame-pointer		\
## -fsanitize-address-use-after-scope \


## binary, library etc...
MAIN	?=	main.c
NAME	?=	fdf 		## The name of your binary

#The name of the library you want to make

P_LIBFT ?= lib/libft
LIBFT_A	?= $(P_LIBFT)/lib/libft.a
LIBFT ?= -I ./$(P_LIBFT)/include -L ./$(P_LIBFT)/lib -lft -lftprintf

P_MLX_LINUX	?= lib/mlx_linux
P_MLX_MAC	?= lib/mlx_mac

MLX_FLAG_LINUX ?= -lXext -lX11 -lmlx
MLX_FLAG_MAC ?= -lmlx -framework OpenGL -framework AppKit

# Change the `..._MAC ` to `..._LINUX` depending on OS
MLX_FLAG	?= $(MLX_FLAG_MAC)
P_MLX		?= $(P_MLX_MAC)
## sources and objects where path names are removed.
## Add all your source files to this variable
SRC		=	$(MAIN)		\
			src/map_perser/file_size.c		\
			src/map_perser/get_map.c		\
			src/map_perser/is_dir.c			\
			src/map_perser/is_file.c		\
			src/free_map.c		\
			src/print_map.c		\
			src/pre_check.c		\
			src/root_init.c		\

## Objects without path names
OBJ		:=	$(notdir $(SRC:.c=.o))

## Objects with their path name
OBJ_P	=	$(addprefix $(P_OBJ)/,$(OBJ))	## addprefix add the 
											## path name to the files...
## Start making here
__START: all
	 printf "$(OK)[+][$(PROJECT)] Done$(C_DEF)\n"

## For multiple Binarys
all : $(LIBFT_A) $(NAME)

$(NAME):	$(SRC)
	@$(CC) $(CC_FLAG_ASAN) $(SRC) -I ./$(P_INCLUDE) -I ./$(P_MLX)  -L $(P_MLX)  $(MLX_FLAG) $(LIBFT)  \
		-o $(NAME)

## Clean objects and others
clean:
	@rm		-f	$(NAME)
	printf	"$(WARN)[!][$(PROJECT)] Removed all objects from ./$(P_OBJ)$(C_DEF)\n"
	printf	"$(OK)[+][$(PROJECT)] Cleaned$(C_DEF)\n"

## Cleans everything
fclean:		clean
	@rm		-f	$(NAME)
	printf	"$(WARN)[!][$(PROJECT)] Removed $(NAME)$(C_DEF)\n"
	@make -C lib/libft fclean --no-print-directory
	printf	"$(OK)[+][$(PROJECT)] Fully cleaned$(C_DEF)\n"

$(LIBFT_A):
	@make -C lib/libft lib/libft.a ft_printf --no-print-directory

re:			fclean all

## This function creat object files from sources.
## It treates the string of large source names as
## individual names, when it creat objects it do
## not gives al the names in the same time to gcc
## but one by one.
object:		$(SRC) $(P_SRC) $(P_OBJ)
	$(foreach SOURCE, $(SRC), \
		$(CC) $(CC_FLAG) -I$(P_INCLUDE) -c $(SOURCE) -o $(P_OBJ)/$(notdir $(SOURCE:.c=.o))	&& \
		printf "$(OK)[+][$(PROJECT)] $(SOURCE)$(C_DEF)" && sleep $(SLEEP)	&& \
		printf "\r\033[K" \
	;)
	printf "$(OK)[+][$(PROJECT)] Objects are made in ./$(P_OBJ)$(C_DEF)\n"

## Make the actual library (archive)
library:	object $(P_OBJ) $(OBJ_P)
	printf "$(WARN)[!][$(PROJECT)] Creating archive $(LIB_A)$(C_DEF)\n"
	@ar rc $(LIB_A) $(OBJ_P)
	printf "$(WARN)[!][$(PROJECT)] Generating index in $(LIB_A)$(C_DEF)\n"
	@ranlib $(LIB_A)
	printf "$(OK)[+][$(PROJECT)] The $(LIB_A) library was made$(C_DEF)\n"



## This rule is called when a difference in operating sistem has been
## detected. You can put your prerequisite to be changed if a different
## os has been detected
os_dep: #put your prerequisite for os dependent stufs
	## put your os dependent comands here
	## this will be launched if the os name is 
	## different then what read from the os file.
	## ex: make re
	printf "[$(PROJECT)] Os dependent stufs\n"

## Useful Makefile tricks
##
## ?= 			// let you put a default variable then later change it
## j<number>	// let you launche the number of job at the same time
## ifdef		// let you verify if used defined something or not
## .SILENT		// This parameter let you launch rules in silent mod
## .IGNORE		// Ignore parameter used as .SILENT
#
## --stop-on-faliur			// stop the program if error occures
## -k or --keep-going		// To keep ignoring all errors
## -i or --ignore-errors	// To Ignor error
## --no-print-directory		// This do not show the 'entered ... directory' warning
