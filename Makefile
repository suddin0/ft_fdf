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


SRC		=	$(MAIN)									\
			src/map_perser/file_size.c				\
			src/map_perser/map_malloc.c				\
			src/map_perser/data_to_array.c			\
			src/map_perser/get_num.c				\
			src/map_perser/count_num.c				\
			src/map_perser/get_map.c				\
			src/map_perser/get_map_ext.c			\
			src/map_perser/is_dir.c					\
			src/map_perser/is_file.c				\
			src/free_map.c							\
			src/print_map.c							\
			src/pre_check.c							\
			src/root_init.c							\
			src/free_root.c 						\
			src/init.c								\
			src/init_ext.c						\
			src/color.c								\
			src/event/event_handler.c				\
			src/event/is_button_area.c				\
			src/event/event_func_init.c				\
			src/event/event_pmotion.c				\
			src/event/event_bpress.c				\
			src/draw_line.c							\
			src/draw_map.c							\
			src/matrans/modmatrix.c					\
			src/matrans/rotate_point.c 				\
			src/matrans/rotate_point_ext.c			\
			src/matrans/key_func_one.c				\
			src/matrans/key_func_two.c				\
			src/matrans/key_func_three.c			\
			src/button_res/button_init.c			\
			src/button_res/draw_button.c			\
			src/button_res/button_func.c			\
			src/button_res/button_func_ext_1.c		\
			src/button_res/button_func_ext_2.c		\
			src/font_res/printf_text.c				\
			src/font_res/draw_font.c				\
			src/map_list/init_list.c				\
			src/map_list/show_list.c				\
			src/map_list/free_list.c				\



BUTTON_CREATOR 	= $(P_BIN)/button_creator
FONT_24_CREATOR = $(P_BIN)/font_24_creator
FONT_18_CREATOR = $(P_BIN)/font_18_creator
FONT_11_CREATOR = $(P_BIN)/font_11_creator

P_BUTTON_CREATOR	= src/button_creator/button_creator.c
P_FONT_24_CREATOR	= src/button_creator/font_24_creator.c
P_FONT_18_CREATOR	= src/button_creator/font_18_creator.c
P_FONT_11_CREATOR	= src/button_creator/font_11_creator.c

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
				src/button_creator/font18_struct_init.c	\
				src/button_creator/font11_struct_init.c	\
				src/button_creator/font_struct_manage.c	\
				src/button_creator/font_verif.c			\
				src/map_perser/is_file.c				\



## Where buttons are found
XPM_BUTTON_PATH := res/__buttons__/xpm
XPM_FONT@24_PATH := res/__font__/xpm/font@24
XPM_FONT@18_PATH := res/__font__/xpm/font@18
XPM_FONT@11_PATH := res/__font__/xpm/font@11

BUTTON_STRUCT 	:= res/__buttons__/button.struct
FONT_24_STRUCT 	:= res/__font__/font@24.struct
FONT_18_STRUCT 	:= res/__font__/font@18.struct
FONT_11_STRUCT 	:= res/__font__/font@11.struct

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
					$(XPM_BUTTON_PATH)/reload	\
					$(XPM_BUTTON_PATH)/face		\
					$(XPM_BUTTON_PATH)/help		\

FONT_NAME	:=		33.xpm	\
					34.xpm	\
					35.xpm	\
					36.xpm	\
					37.xpm	\
					38.xpm	\
					39.xpm	\
					40.xpm	\
					41.xpm	\
					42.xpm	\
					43.xpm	\
					44.xpm	\
					45.xpm	\
					46.xpm	\
					47.xpm	\
					48.xpm	\
					49.xpm	\
					50.xpm	\
					51.xpm	\
					52.xpm	\
					53.xpm	\
					54.xpm	\
					55.xpm	\
					56.xpm	\
					57.xpm	\
					58.xpm	\
					59.xpm	\
					60.xpm	\
					61.xpm	\
					62.xpm	\
					63.xpm	\
					64.xpm	\
					65.xpm	\
					66.xpm	\
					67.xpm	\
					68.xpm	\
					69.xpm	\
					70.xpm	\
					71.xpm	\
					72.xpm	\
					73.xpm	\
					74.xpm	\
					75.xpm	\
					76.xpm	\
					77.xpm	\
					78.xpm	\
					79.xpm	\
					80.xpm	\
					81.xpm	\
					82.xpm	\
					83.xpm	\
					84.xpm	\
					85.xpm	\
					86.xpm	\
					87.xpm	\
					88.xpm	\
					89.xpm	\
					90.xpm	\
					91.xpm	\
					92.xpm	\
					93.xpm	\
					94.xpm	\
					95.xpm	\
					96.xpm	\
					97.xpm	\
					98.xpm	\
					99.xpm	\
					100.xpm	\
					101.xpm	\
					102.xpm	\
					103.xpm	\
					104.xpm	\
					105.xpm	\
					106.xpm	\
					107.xpm	\
					108.xpm	\
					109.xpm	\
					110.xpm	\
					111.xpm	\
					112.xpm	\
					113.xpm	\
					114.xpm	\
					115.xpm	\
					116.xpm	\
					117.xpm	\
					118.xpm	\
					119.xpm	\
					120.xpm	\
					121.xpm	\
					122.xpm	\
					123.xpm	\
					124.xpm	\
					125.xpm	\
					126.xpm	\
					127.xpm	\

FONT@24_NAME = $(addprefix $(XPM_FONT@24_PATH)/, $(FONT_NAME))
FONT@18_NAME = $(addprefix $(XPM_FONT@18_PATH)/, $(FONT_NAME))
FONT@11_NAME = $(addprefix $(XPM_FONT@11_PATH)/, $(FONT_NAME))


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

$(NAME):	$(SRC) $(BUTTON_STRUCT) $(FONT_24_STRUCT) $(FONT_18_STRUCT) $(FONT_11_STRUCT)
	@$(CC) $(CC_FLAG_ASAN) $(SRC) -I ./$(P_INCLUDE) -I ./$(P_MLX)  -L $(P_MLX)  $(MLX_FLAG) $(LIBFT)  \
		-o $(NAME)

## Clean objects and others
clean:				button_clean	font_24_clean	font_18_clean	font_11_clean
	@rm		-f	$(NAME)
	printf	"$(WARN)[!][$(PROJECT)] Removed all objects from ./$(P_OBJ)$(C_DEF)\n"
	printf	"$(OK)[+][$(PROJECT)] Cleaned$(C_DEF)\n"

## Cleans everything
fclean:		clean	button_fclean	font_24_fclean	font_18_fclean	font_11_fclean
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






## ----------------- FONT Creator --------------- ##
## --------------@24----------- ##
$(FONT_24_CREATOR): $(LIBFT_A)  $(P_FONT_CREATOR) $(FONT_SRC) $(P_BIN)
	@printf "$(WARN)[!][$(PROJECT)] Creating font_creator in $(P_BIN)$(C_DEF)\n"
	@$(CC) $(P_FONT_24_CREATOR)  $(CC_FLAG_ASAN) $(FONT_SRC) -I ./$(P_INCLUDE) \
		-I ./$(P_MLX)  -L $(P_MLX)  $(MLX_FLAG) $(LIBFT) -o $(FONT_24_CREATOR)
	@printf "$(OK)[+][$(PROJECT)] button_creator compiled in $(P_BIN)$(C_DEF)\n"
# BUTTON_PATH := res/__buttons__/xpm
# BUTTON_NAME := $(BUTTON_PATH)/arrow
$(FONT_24_STRUCT) :
	@make font_24_make --no-print-directory

font_24_make: $(P_BIN) $(FONT_24_CREATOR) $(XPM_FONT_PATH)
	@./$(FONT_24_CREATOR) $(FONT@24_NAME)

font_24_clean:
	@printf	"$(WARN)[!][$(PROJECT)] font_24_creator in $(P_BIN)$(C_DEF)\n"
	@rm -f $(FONT_24_CREATOR)

font_24_fclean: font_24_clean
	@printf	"$(WARN)[!][$(PROJECT)] Removed $(FONT_24_STRUCT)$(C_DEF)\n"
	@rm -f $(FONT_24_STRUCT)

font_24_re: font_24_fclean font_24_make


## --------------@18----------- ##
$(FONT_18_CREATOR): $(LIBFT_A)  $(P_FONT_CREATOR) $(FONT_SRC) $(P_BIN)
	@printf "$(WARN)[!][$(PROJECT)] Creating font_creator in $(P_BIN)$(C_DEF)\n"
	@$(CC) $(P_FONT_18_CREATOR)  $(CC_FLAG_ASAN) $(FONT_SRC) -I ./$(P_INCLUDE) \
		-I ./$(P_MLX)  -L $(P_MLX)  $(MLX_FLAG) $(LIBFT) -o $(FONT_18_CREATOR)
	@printf "$(OK)[+][$(PROJECT)] button_creator compiled in $(P_BIN)$(C_DEF)\n"
# BUTTON_PATH := res/__buttons__/xpm
# BUTTON_NAME := $(BUTTON_PATH)/arrow
$(FONT_18_STRUCT) :
	@make font_18_make --no-print-directory

font_18_make: $(P_BIN) $(FONT_18_CREATOR) $(XPM_FONT_PATH)
	@./$(FONT_18_CREATOR) $(FONT@18_NAME)

font_18_clean:
	@printf	"$(WARN)[!][$(PROJECT)] font_18_creator in $(P_BIN)$(C_DEF)\n"
	@rm -f $(FONT_18_CREATOR)

font_18_fclean: font_18_clean
	@printf	"$(WARN)[!][$(PROJECT)] Removed $(FONT_18_STRUCT)$(C_DEF)\n"
	@rm -f $(FONT_18_STRUCT)

font_18_re: font_18_fclean font_18_make

## --------------@18----------- ##
$(FONT_11_CREATOR): $(LIBFT_A)  $(P_FONT_CREATOR) $(FONT_SRC) $(P_BIN)
	@printf "$(WARN)[!][$(PROJECT)] Creating font_creator in $(P_BIN)$(C_DEF)\n"
	@$(CC) $(P_FONT_11_CREATOR)  $(CC_FLAG_ASAN) $(FONT_SRC) -I ./$(P_INCLUDE) \
		-I ./$(P_MLX)  -L $(P_MLX)  $(MLX_FLAG) $(LIBFT) -o $(FONT_11_CREATOR)
	@printf "$(OK)[+][$(PROJECT)] button_creator compiled in $(P_BIN)$(C_DEF)\n"
# BUTTON_PATH := res/__buttons__/xpm
# BUTTON_NAME := $(BUTTON_PATH)/arrow
$(FONT_11_STRUCT) :
	@make font_11_make --no-print-directory

font_11_make: $(P_BIN) $(FONT_11_CREATOR) $(XPM_FONT_PATH)
	@./$(FONT_11_CREATOR) $(FONT@11_NAME)

font_11_clean:
	@printf	"$(WARN)[!][$(PROJECT)] font_11_creator in $(P_BIN)$(C_DEF)\n"
	@rm -f $(FONT_11_CREATOR)

font_11_fclean: font_11_clean
	@printf	"$(WARN)[!][$(PROJECT)] Removed $(FONT_11_STRUCT)$(C_DEF)\n"
	@rm -f $(FONT_11_STRUCT)

font_18_re: font_11_fclean font_11_make


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
