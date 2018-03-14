#ifndef BUTTON_CREATOR_H
# define BUTTON_CREATOR_H

# include "main.h"

# define X_MAIN		133
# define X_MAP		133
# define X_INFO		133
# define X_LEFT		101
# define X_DOWN		101
# define X_RIGHT	101
# define X_UP		101
# define X_UZOOM	58
# define X_ZOOM		58
# define X_DEFAULT	0
# define X_FACE		0
# define X_SIDE		0
# define X_TRANS	135
# define X_ROTATE	135

# define Y_MAIN		60
# define Y_MAP		60
# define Y_INFO		60
# define Y_LEFT		101
# define Y_DOWN		101
# define Y_RIGHT	101
# define Y_UP		101
# define Y_UZOOM	88
# define Y_ZOOM		58
# define Y_DEFAULT	0
# define Y_FACE		0
# define Y_SIDE		0
# define Y_TRANS	43
# define Y_ROTATE	43


# define OX_MAIN	0
# define OX_MAP		X_MAIN
# define OX_INFO	X_INFO + X_MAP
# define OX_DOWN	(MENU_X / 2) - (X_DOWN / 2)
# define OX_LEFT	OX_DOWN - X_LEFT
# define OX_RIGHT	OX_DOWN + X_RIGHT
# define OX_UP		OX_DOWN
# define OX_UZOOM	OX_UP + (X_DOWN + (X_ZOOM / 3))
# define OX_ZOOM	OX_UP - (X_ZOOM + (X_ZOOM / 3))
# define OX_DEFAULT	0
# define OX_FACE	0
# define OX_SIDE	0
# define OX_TRANS	(MENU_X / 2) - X_TRANS
# define OX_ROTATE	(MENU_X / 2)

# define OY_MAIN	0
# define OY_MAP		0
# define OY_INFO	0
# define OY_DOWN	MENU_Y - (Y_DOWN + 30)
# define OY_LEFT	OY_DOWN
# define OY_RIGHT	OY_DOWN
# define OY_UP		OY_DOWN - Y_UP
# define OY_UZOOM	OY_UP + (Y_ZOOM / 3)//+ (Y_UZOOM + (Y_UZOOM  / 2))
# define OY_ZOOM	OY_UP + (Y_ZOOM / 3)//- (Y_ZOOM  + (Y_ZOOM   / 2))
# define OY_DEFAULT	0
# define OY_FACE	0
# define OY_SIDE	0
# define OY_TRANS	(MENU_Y / 2) - (Y_TRANS		+ 20)
# define OY_ROTATE	(MENU_Y / 2) - (Y_ROTATE	+ 20)



typedef struct s_button_create_data
{
	char name[100];
	int id;
	int type;
	int stat;
	int o_x;
	int o_y;
} t_b_create_data;

int file_check(int argc, char ***argv);
void clear_button(t_button *button);
int create_name(char ****file, int argc, char **argv);
void free_file(char ***file, int argc);
void name_copy(char *dest, char *src);
void size_check(char *name, int a, int  b);
void write_struct(t_button b[], char *path);
void show_image(char *img, int x, int y);


void init_bid  (t_b_create_data *b);
void init_btype(t_b_create_data *b);
void init_bstat(t_b_create_data *b);
void init_borigine (t_b_create_data *b);
void button_data_init(t_b_create_data *b);
void struct_manage(t_image *ig, t_button *b, t_b_create_data *bdata, char *fn);
int file_verif(int argc, char **argv, char ****file);
// void init_bo_y (t_b_create_data *b);


# endif
