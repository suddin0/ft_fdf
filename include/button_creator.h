#ifndef BUTTON_CREATOR_H
# define BUTTON_CREATOR_H

# include "main.h"

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
static void free_file(char ***file, int argc);
void name_copy(char *dest, char *src);
void size_check(char *name, int a, int  b);
void write_struct(t_button b[], char *path);
void show_image(char *img, int x, int y);

void init_bname(t_b_create_data *b);
void init_bid  (t_b_create_data *b);
void init_btype(t_b_create_data *b);
void init_bstat(t_b_create_data *b);
void init_bo_x (t_b_create_data *b);
void init_bo_y (t_b_create_data *b);


# endif
