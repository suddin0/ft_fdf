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
.SILENT	: __START	NAME	clean fclean all re object library os_dep image_creator
.PHONY	: __START			clean fclean all re object library os_dep image_creator


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

CC_FLAG_ASAN ?=	-O1 -g -lm -fsanitize=address	\
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

## Variables are set deending on the OS
ifeq ($(shell uname -s),Darwin)
	MLX_FLAG = $(MLX_FLAG_MAC)
	P_MLX	= $(P_MLX_MAC)
else
	MLX_FLAG = $(MLX_FLAG_LINUX)
	P_MLX	= $(P_MLX_LINUX)
endif

BUTTON_STRUCT = $(P_RES)/__buttons__/button.struct


# Change the `..._MAC ` to `..._LINUX` depending on OS
# MLX_FLAG	?= $(MLX_FLAG_MAC)
# P_MLX		?= $(P_MLX_MAC)
## sources and objects where path names are removed.
## Add all your source files to this variable


SRC		=	$(MAIN)							\
			src/map_perser/file_size.c		\
			src/map_perser/map_malloc.c		\
			src/map_perser/data_to_array.c	\
			src/map_perser/get_num.c		\
			src/map_perser/count_num.c		\
			src/map_perser/get_map.c		\
			src/map_perser/is_dir.c			\
			src/map_perser/is_file.c		\
			src/free_map.c					\
			src/print_map.c					\
			src/pre_check.c					\
			src/root_init.c					\
			src/init.c						\
			src/color.c						\
			src/event/event_handler.c		\
			src/event/is_button_area.c		\
			src/event/event_func_init.c		\
			src/event/event_pmotion.c		\
			src/event/event_bpress.c		\
			src/draw_line.c					\
			src/draw_dot.c					\
			src/draw_map.c					\
			src/matrans/modmatrix.c			\
			src/matrans/rotate_point.c 		\
			src/matrans/key_func_one.c 		\
			src/matrans/key_func_two.c 		\
			src/matrans/key_func_three.c 	\
			src/button_res/button_init.c 	\
			src/button_res/draw_button.c 	\
			src/button_res/button_func.c 	\
			src/font_res/printf_text.c 		\
			src/font_res/draw_font.c 		\
			src/map_list/init_list.c 		\
			src/map_list/show_list.c 		\



BUTTON_CREATOR 	= $(P_BIN)/button_creator
FONT_CREATOR 	= $(P_BIN)/font_creator

P_BUTTON_CREATOR = src/button_creator/button_creator.c
P_FONT_CREATOR	 = src/button_creator/font_creator.c

## Button creator source
BUTTON_SRC =	src/map_perser/file_size.c				\
				src/map_perser/is_dir.c					\
				src/map_perser/is_file.c				\
				src/root_init.c							\
				src/button_creator/button_data_init.c	\
				src/button_creator/struct_manage.c		\
				src/button_creator/free_file.c			\
				src/button_creator/size_check.c			\
				src/button_creator/file_verif.c			\
				src/button_creator/name_copy.c			\
				src/button_creator/write_struct.c		\



FONT_SRC =		src/button_creator/size_check.c			\
				src/button_creator/write_struct.c		\
				src/button_creator/name_copy.c			\
				src/button_creator/font24_struct_init.c	\
				src/button_creator/font_struct_manage.c	\



## Where buttons are found
XPM_BUTTON_PATH := res/__buttons__/xpm
XPM_FONT@24_PATH := res/__font__/xpm/font@24
XPM_FONT@14_PATH := res/__font__/xpm/font@14

BUTTON_STRUCT 	:= res/__buttons__/button.struct
FONT_STRUCT 	:= res/__font__/font.struct

BUTTON_NAME 	:=	$(XPM_BUTTON_PATH)/right 	\
					$(XPM_BUTTON_PATH)/left 	\
					$(XPM_BUTTON_PATH)/down 	\
					$(XPM_BUTTON_PATH)/up		\
					$(XPM_BUTTON_PATH)/trans	\
					$(XPM_BUTTON_PATH)/rotate	\
					$(XPM_BUTTON_PATH)/controle	\
					$(XPM_BUTTON_PATH)/maps		\
					$(XPM_BUTTON_PATH)/info		\
					$(XPM_BUTTON_PATH)/zoom		\
					$(XPM_BUTTON_PATH)/uzoom	\

FONT@24_NAME	:=	$(XPM_FONT@24_PATH)/33.xpm		\
					$(XPM_FONT@24_PATH)/34.xpm		\
					$(XPM_FONT@24_PATH)/35.xpm		\
					$(XPM_FONT@24_PATH)/36.xpm		\
					$(XPM_FONT@24_PATH)/37.xpm		\
					$(XPM_FONT@24_PATH)/38.xpm		\
					$(XPM_FONT@24_PATH)/39.xpm		\
					$(XPM_FONT@24_PATH)/40.xpm		\
					$(XPM_FONT@24_PATH)/41.xpm		\
					$(XPM_FONT@24_PATH)/42.xpm		\
					$(XPM_FONT@24_PATH)/43.xpm		\
					$(XPM_FONT@24_PATH)/44.xpm		\
					$(XPM_FONT@24_PATH)/45.xpm		\
					$(XPM_FONT@24_PATH)/46.xpm		\
					$(XPM_FONT@24_PATH)/47.xpm		\
					$(XPM_FONT@24_PATH)/48.xpm		\
					$(XPM_FONT@24_PATH)/49.xpm		\
					$(XPM_FONT@24_PATH)/50.xpm		\
					$(XPM_FONT@24_PATH)/51.xpm		\
					$(XPM_FONT@24_PATH)/52.xpm		\
					$(XPM_FONT@24_PATH)/53.xpm		\
					$(XPM_FONT@24_PATH)/54.xpm		\
					$(XPM_FONT@24_PATH)/55.xpm		\
					$(XPM_FONT@24_PATH)/56.xpm		\
					$(XPM_FONT@24_PATH)/57.xpm		\
					$(XPM_FONT@24_PATH)/58.xpm		\
					$(XPM_FONT@24_PATH)/59.xpm		\
					$(XPM_FONT@24_PATH)/60.xpm		\
					$(XPM_FONT@24_PATH)/61.xpm		\
					$(XPM_FONT@24_PATH)/62.xpm		\
					$(XPM_FONT@24_PATH)/63.xpm		\
					$(XPM_FONT@24_PATH)/64.xpm		\
					$(XPM_FONT@24_PATH)/65.xpm		\
					$(XPM_FONT@24_PATH)/66.xpm		\
					$(XPM_FONT@24_PATH)/67.xpm		\
					$(XPM_FONT@24_PATH)/68.xpm		\
					$(XPM_FONT@24_PATH)/69.xpm		\
					$(XPM_FONT@24_PATH)/70.xpm		\
					$(XPM_FONT@24_PATH)/71.xpm		\
					$(XPM_FONT@24_PATH)/72.xpm		\
					$(XPM_FONT@24_PATH)/73.xpm		\
					$(XPM_FONT@24_PATH)/74.xpm		\
					$(XPM_FONT@24_PATH)/75.xpm		\
					$(XPM_FONT@24_PATH)/76.xpm		\
					$(XPM_FONT@24_PATH)/77.xpm		\
					$(XPM_FONT@24_PATH)/78.xpm		\
					$(XPM_FONT@24_PATH)/79.xpm		\
					$(XPM_FONT@24_PATH)/80.xpm		\
					$(XPM_FONT@24_PATH)/81.xpm		\
					$(XPM_FONT@24_PATH)/82.xpm		\
					$(XPM_FONT@24_PATH)/83.xpm		\
					$(XPM_FONT@24_PATH)/84.xpm		\
					$(XPM_FONT@24_PATH)/85.xpm		\
					$(XPM_FONT@24_PATH)/86.xpm		\
					$(XPM_FONT@24_PATH)/87.xpm		\
					$(XPM_FONT@24_PATH)/88.xpm		\
					$(XPM_FONT@24_PATH)/89.xpm		\
					$(XPM_FONT@24_PATH)/90.xpm		\
					$(XPM_FONT@24_PATH)/91.xpm		\
					$(XPM_FONT@24_PATH)/92.xpm		\
					$(XPM_FONT@24_PATH)/93.xpm		\
					$(XPM_FONT@24_PATH)/94.xpm		\
					$(XPM_FONT@24_PATH)/95.xpm		\
					$(XPM_FONT@24_PATH)/96.xpm		\
					$(XPM_FONT@24_PATH)/97.xpm		\
					$(XPM_FONT@24_PATH)/98.xpm		\
					$(XPM_FONT@24_PATH)/99.xpm		\
					$(XPM_FONT@24_PATH)/100.xpm	\
					$(XPM_FONT@24_PATH)/101.xpm	\
					$(XPM_FONT@24_PATH)/102.xpm	\
					$(XPM_FONT@24_PATH)/103.xpm	\
					$(XPM_FONT@24_PATH)/104.xpm	\
					$(XPM_FONT@24_PATH)/105.xpm	\
					$(XPM_FONT@24_PATH)/106.xpm	\
					$(XPM_FONT@24_PATH)/107.xpm	\
					$(XPM_FONT@24_PATH)/108.xpm	\
					$(XPM_FONT@24_PATH)/109.xpm	\
					$(XPM_FONT@24_PATH)/110.xpm	\
					$(XPM_FONT@24_PATH)/111.xpm	\
					$(XPM_FONT@24_PATH)/112.xpm	\
					$(XPM_FONT@24_PATH)/113.xpm	\
					$(XPM_FONT@24_PATH)/114.xpm	\
					$(XPM_FONT@24_PATH)/115.xpm	\
					$(XPM_FONT@24_PATH)/116.xpm	\
					$(XPM_FONT@24_PATH)/117.xpm	\
					$(XPM_FONT@24_PATH)/118.xpm	\
					$(XPM_FONT@24_PATH)/119.xpm	\
					$(XPM_FONT@24_PATH)/120.xpm	\
					$(XPM_FONT@24_PATH)/121.xpm	\
					$(XPM_FONT@24_PATH)/122.xpm	\
					$(XPM_FONT@24_PATH)/123.xpm	\
					$(XPM_FONT@24_PATH)/124.xpm	\
					$(XPM_FONT@24_PATH)/125.xpm	\
					$(XPM_FONT@24_PATH)/127.xpm	\



FONT_NAME		:=	$(XPM_FONT_PATH)/33.xpm		\
					$(XPM_FONT_PATH)/34.xpm		\
					$(XPM_FONT_PATH)/35.xpm		\
					$(XPM_FONT_PATH)/36.xpm		\
					$(XPM_FONT_PATH)/37.xpm		\
					$(XPM_FONT_PATH)/38.xpm		\
					$(XPM_FONT_PATH)/39.xpm		\
					$(XPM_FONT_PATH)/40.xpm		\
					$(XPM_FONT_PATH)/41.xpm		\
					$(XPM_FONT_PATH)/42.xpm		\
					$(XPM_FONT_PATH)/43.xpm		\
					$(XPM_FONT_PATH)/44.xpm		\
					$(XPM_FONT_PATH)/45.xpm		\
					$(XPM_FONT_PATH)/46.xpm		\
					$(XPM_FONT_PATH)/47.xpm		\
					$(XPM_FONT_PATH)/48.xpm		\
					$(XPM_FONT_PATH)/49.xpm		\
					$(XPM_FONT_PATH)/50.xpm		\
					$(XPM_FONT_PATH)/51.xpm		\
					$(XPM_FONT_PATH)/52.xpm		\
					$(XPM_FONT_PATH)/53.xpm		\
					$(XPM_FONT_PATH)/54.xpm		\
					$(XPM_FONT_PATH)/55.xpm		\
					$(XPM_FONT_PATH)/56.xpm		\
					$(XPM_FONT_PATH)/57.xpm		\
					$(XPM_FONT_PATH)/58.xpm		\
					$(XPM_FONT_PATH)/59.xpm		\
					$(XPM_FONT_PATH)/60.xpm		\
					$(XPM_FONT_PATH)/61.xpm		\
					$(XPM_FONT_PATH)/62.xpm		\
					$(XPM_FONT_PATH)/63.xpm		\
					$(XPM_FONT_PATH)/64.xpm		\
					$(XPM_FONT_PATH)/65.xpm		\
					$(XPM_FONT_PATH)/66.xpm		\
					$(XPM_FONT_PATH)/67.xpm		\
					$(XPM_FONT_PATH)/68.xpm		\
					$(XPM_FONT_PATH)/69.xpm		\
					$(XPM_FONT_PATH)/70.xpm		\
					$(XPM_FONT_PATH)/71.xpm		\
					$(XPM_FONT_PATH)/72.xpm		\
					$(XPM_FONT_PATH)/73.xpm		\
					$(XPM_FONT_PATH)/74.xpm		\
					$(XPM_FONT_PATH)/75.xpm		\
					$(XPM_FONT_PATH)/76.xpm		\
					$(XPM_FONT_PATH)/77.xpm		\
					$(XPM_FONT_PATH)/78.xpm		\
					$(XPM_FONT_PATH)/79.xpm		\
					$(XPM_FONT_PATH)/80.xpm		\
					$(XPM_FONT_PATH)/81.xpm		\
					$(XPM_FONT_PATH)/82.xpm		\
					$(XPM_FONT_PATH)/83.xpm		\
					$(XPM_FONT_PATH)/84.xpm		\
					$(XPM_FONT_PATH)/85.xpm		\
					$(XPM_FONT_PATH)/86.xpm		\
					$(XPM_FONT_PATH)/87.xpm		\
					$(XPM_FONT_PATH)/88.xpm		\
					$(XPM_FONT_PATH)/89.xpm		\
					$(XPM_FONT_PATH)/90.xpm		\
					$(XPM_FONT_PATH)/91.xpm		\
					$(XPM_FONT_PATH)/92.xpm		\
					$(XPM_FONT_PATH)/93.xpm		\
					$(XPM_FONT_PATH)/94.xpm		\
					$(XPM_FONT_PATH)/95.xpm		\
					$(XPM_FONT_PATH)/96.xpm		\
					$(XPM_FONT_PATH)/97.xpm		\
					$(XPM_FONT_PATH)/98.xpm		\
					$(XPM_FONT_PATH)/99.xpm		\
					$(XPM_FONT_PATH)/100.xpm	\
					$(XPM_FONT_PATH)/101.xpm	\
					$(XPM_FONT_PATH)/102.xpm	\
					$(XPM_FONT_PATH)/103.xpm	\
					$(XPM_FONT_PATH)/104.xpm	\
					$(XPM_FONT_PATH)/105.xpm	\
					$(XPM_FONT_PATH)/106.xpm	\
					$(XPM_FONT_PATH)/107.xpm	\
					$(XPM_FONT_PATH)/108.xpm	\
					$(XPM_FONT_PATH)/109.xpm	\
					$(XPM_FONT_PATH)/110.xpm	\
					$(XPM_FONT_PATH)/111.xpm	\
					$(XPM_FONT_PATH)/112.xpm	\
					$(XPM_FONT_PATH)/113.xpm	\
					$(XPM_FONT_PATH)/114.xpm	\
					$(XPM_FONT_PATH)/115.xpm	\
					$(XPM_FONT_PATH)/116.xpm	\
					$(XPM_FONT_PATH)/117.xpm	\
					$(XPM_FONT_PATH)/118.xpm	\
					$(XPM_FONT_PATH)/119.xpm	\
					$(XPM_FONT_PATH)/120.xpm	\
					$(XPM_FONT_PATH)/121.xpm	\
					$(XPM_FONT_PATH)/122.xpm	\
					$(XPM_FONT_PATH)/123.xpm	\
					$(XPM_FONT_PATH)/124.xpm	\
					$(XPM_FONT_PATH)/125.xpm	\
					$(XPM_FONT_PATH)/126.xpm	\
					$(XPM_FONT_PATH)/127.xpm	\



## Objects without path names
OBJ		:=	$(notdir $(SRC:.c=.o))

## Objects with their path name
OBJ_P	=	$(addprefix $(P_OBJ)/,$(OBJ))	## addprefix add the
											## path name to the files...
## Start making here
__START: all
	 printf "$(OK)[+][$(PROJECT)] Done$(C_DEF)\n"

## For multiple Binarys
all : $(LIBFT_A) $(NAME) $(BUTTON_STRUCT)

$(NAME):	$(SRC)
	@$(CC) $(CC_FLAG_ASAN) $(SRC) -I ./$(P_INCLUDE) -I ./$(P_MLX)  -L $(P_MLX)  $(MLX_FLAG) $(LIBFT)  \
		-o $(NAME)

## Clean objects and others
clean: button_clean
	@rm		-f	$(NAME)
	printf	"$(WARN)[!][$(PROJECT)] Removed all objects from ./$(P_OBJ)$(C_DEF)\n"
	printf	"$(OK)[+][$(PROJECT)] Cleaned$(C_DEF)\n"

## Cleans everything
fclean:		clean button_fclean
	@rm		-f	$(NAME)
	printf	"$(WARN)[!][$(PROJECT)] Removed $(NAME)$(C_DEF)\n"
	@make -C lib/libft fclean --no-print-directory
	@rm -rf $(P_BIN)
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


## --------------- BUTTON Creator --------------- ##
$(BUTTON_CREATOR): $(LIBFT_A)  $(P_BUTTON_CREATOR) $(IMAGE_SRC) $(P_BIN)
	@printf "$(WARN)[!][$(PROJECT)] Creating button_creator in $(P_BIN)$(C_DEF)\n"
	@$(CC) $(P_BUTTON_CREATOR)  $(CC_FLAG_ASAN) $(BUTTON_SRC) -I ./$(P_INCLUDE) -I ./$(P_MLX)  -L $(P_MLX)  $(MLX_FLAG) $(LIBFT) \
	-o $(P_BIN)/button_creator
	@printf "$(OK)[+][$(PROJECT)] button_creator compiled in $(P_BIN)$(C_DEF)\n"

# BUTTON_PATH := res/__buttons__/xpm
# BUTTON_NAME := $(BUTTON_PATH)/arrow
$(BUTTON_STRUCT) :
	@make button_make --no-print-directory
button_make: $(P_BIN) $(BUTTON_CREATOR) $(XPM_BUTTON_PATH)
	@./$(BUTTON_CREATOR) $(BUTTON_NAME)

button_clean:
	@printf	"$(WARN)[!][$(PROJECT)] Removed $(BUTTON_CREATOR)$(C_DEF)\n"
	@rm -f $(BUTTON_CREATOR)

button_fclean: button_clean
	@printf	"$(WARN)[!][$(PROJECT)] Removed $(BUTTON_STRUCT)$(C_DEF)\n"
	@rm -f $(BUTTON_STRUCT)

button_re: button_fclean button_make

# button_test: $(LIBFT_A) $(P_BIN)
# 	@printf "$(WARN)[!][$(PROJECT)] Creating button_test in $(P_BIN)$(C_DEF)\n"
# 	$(CC) button_test.c  $(CC_FLAG_ASAN) $(IMAGE_SRC) -I ./$(P_INCLUDE) -I ./$(P_MLX)  -L $(P_MLX)  $(MLX_FLAG) $(LIBFT) \
# 	-o button_test
# 	@printf "$(OK)[+][$(PROJECT)] button_test compiled in $(P_BIN)$(C_DEF)\n"

## ----------------- FONT Creator --------------- ##
$(FONT_CREATOR): $(LIBFT_A)  $(P_FONT_CREATOR) $(FONT_SRC) $(P_BIN)
	@printf "$(WARN)[!][$(PROJECT)] Creating font_creator in $(P_BIN)$(C_DEF)\n"
	@$(CC) $(P_FONT_CREATOR)  $(CC_FLAG_ASAN) $(FONT_SRC) -I ./$(P_INCLUDE) \
		-I ./$(P_MLX)  -L $(P_MLX)  $(MLX_FLAG) $(LIBFT) -o $(FONT_CREATOR)
	@printf "$(OK)[+][$(PROJECT)] button_creator compiled in $(P_BIN)$(C_DEF)\n"
# BUTTON_PATH := res/__buttons__/xpm
# BUTTON_NAME := $(BUTTON_PATH)/arrow
$(FONT_STRUCT) :
	@make button_make --no-print-directory

font_make: $(P_BIN) $(FONT_CREATOR) $(XPM_FONT_PATH)
	@./$(FONT_CREATOR) $(FONT@24_NAME)

font_clean:
	@printf	"$(WARN)[!][$(PROJECT)] font_creator in $(P_BIN)$(C_DEF)\n"
	@rm -f $(FONT_CREATOR)

font_fclean: font_clean
	@printf	"$(WARN)[!][$(PROJECT)] Removed $(FONT_STRUCT)$(C_DEF)\n"
	@rm -f $(FONT_STRUCT)

font_re: font_fclean font_make

# font_test: $(LIBFT_A) $(P_BIN)
# 	@printf "$(WARN)[!][$(PROJECT)] Creating font_test in $(P_BIN)$(C_DEF)\n"
# 	$(CC) button_test.c  $(CC_FLAG_ASAN) $(FONT_NAME) -I ./$(P_INCLUDE) -I ./$(P_MLX)  -L $(P_MLX)  $(MLX_FLAG) $(LIBFT) \
# 	-o button_test
# 	@printf "$(OK)[+][$(PROJECT)] button_test compiled in $(P_BIN)$(C_DEF)\n"
#
#

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
