#ifndef MAIN_H
# define MAIN_H

# include <limits.h>		// Get Path Name limits
# include <sys/stat.h>		// For file status
# include <fcntl.h>			// For open
# include <stdio.h>			// For printf
# include <unistd.h>		// For read
# include <errno.h>			// For read
# include <math.h>			// For read

#include <sys/types.h>
#include <dirent.h>
# include <stdarg.h>

# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"
# include "button_map.h"	// Tus use buttom macros
# include "nn_mask.h"		// Tus use buttom macros
// # include "mlx_int.h" 	// If included many errors appears

/* Main Winsow */
# define DEF_ROOT_X 1600	// Window width
# define DEF_ROOT_Y 950		// Window Height

# define ORIGINE_X  270.0f
# define ORIGINE_Y  290.0f
# define STEP 		30.0f

// Image Sizes
# define MENU_X DEF_ROOT_X / 4
# define MENU_Y DEF_ROOT_Y

# define OPT_X MENU_X / 3
# define OPT_Y 95


# define FOOT_X DEF_ROOT_X - (DEF_ROOT_X / 4)
# define FOOT_Y 23

# define PREV_X DEF_ROOT_X - (DEF_ROOT_X / 4)
# define PREV_Y DEF_ROOT_Y - FOOT_Y

# define BUTTON_SIZE	19000 * 4	// max button size 8mb [8388608]
// # define CHAR_SIZE_28	1000 * 4	// max character size size 8mb [8388608]
# define CHAR_SIZE_28	20000 * 4		// max character size size 8mb [8388608]
# define CHAR_SIZE_16	54140 * 4	// max character size size 8mb [8388608]
# define FCHAR_MAX		97	// Maximum characters in the pile + space
# define BUTTON_MAX		16	// Maximum numer of buttons we will use in button creator or in our first menu
# define BUTTON_STRUCT_PATH	"res/__buttons__/button.struct"
# define FONT_STRUCT_PATH	"res/__font__/font.struct"
# define MAP_PATH			"maps"

# define MAX_ERROR_MSG 250 // Max error message size

// # define MENU_BG_COLOR	0x1b2d3b
// # define PREV_BG_COLOR	0x021626
# define MENU_BG_COLOR	0x383f49
# define FOOT_BG_COLOR	0x383f49
# define PREV_BG_COLOR	0x323842
# define MAP_COLOR		0xe0e0bd

// # define COL_R(R)		(R >> 16)
// # define COL_G(G)		((G >> 8) & 0xFF)
// # define COL_B(B)		(B & 0xFF)

# define COL_R(R)		((col >> 24) & 0xFF)	// R
# define COL_G(G)		((col >> 16) & 0xFF)	// G
# define COL_B(B)		((col >> 8 ) & 0xFF)	// B
# define COL_A(R)		(col & 0xFF);			// A

// -------------------

// Event Notification and mask shortcurring
// Notify NN_ButtonPress
# define PMOTION	NN_MotionNotify
# define KPRESS		NN_KeyPress
# define BPRESS		NN_ButtonPress
# define BRELEASE	NN_ButtonRelease
# define KRELEASE	NN_KeyRelease
# define VISIBL		NN_VisibilityNotify
# define ST_DEFAULT	0 // Button stat default
# define ST_HOVER	1 // Button stat hover
# define ST_ACTIVE	2 // Button stat active
# define TP_NORMAL	0 // Button type normal
# define TP_RADIO	1 // Button type radio
# define MV_TRANS	0 // Mouvement: translation
# define MV_ROTAT	1 // Mouvement: translation

// Masks
# define PMOTION_M	NN_PointerMotionMask
# define KPRESS_M	NN_KeyPressMask
# define BPRESS_M	NN_ButtonPressMask
# define BRELEASE_M	NN_ButtonReleaseMask
# define KRELEASE_M	NN_KeyReleaseMask
# define VISIBL_M	NN_VisibilityChangeMask
# define COLOR(MLX_PTR, H_COLOR) mlx_get_color_value(MLX_PTR, H_COLOR)
# define CLEAR(I) set_color(I.img, I.x * I.y, I.bg);
# define MAX_EVENT_KEY 15




typedef struct s_point
{
	double x;
	double y;
	double z;
} t_point;

// contain map object data and various informations about it
typedef struct s_map_data
{
	int			row;	// 	( - ) saves information about current line number
	int			col;	//	( | ) saves the number of columns there are
	long int 	*data;	// the data (the information about the `Z` axis from each line of the map)
	struct s_map_data	*next;
	struct s_map_data	*prev;
}	t_m_data;


typedef struct s_mlx_image
{
	void *img_ptr;	// Image pointer
	char *img;		// Image
	int	  bpp;		// Bit par pixel
	int	  sl;		// Size_len
	int	  end;		// Endian;
	int	  o_x;		// Origine x;
	int	  o_y;		// Origine y
	int	  x;		// width
	int	  y;		// height
	int	  bg;		// Background color
} t_image;

typedef struct s_fdfmap
{
	char		*name;		// stores the maps name
	char		*path;		// stores the maps path
	t_image		*img;		// A copy of the section where map is shown
	//long		**map;		// stores the map as an long int table[data->col][data->raw]
	t_point		**map;		// stores the map as an long int table[data->col][data->raw]
	long		*line_sz;	// stores the amount of number a line contains (for looping purpose)
	int			file_sz;	// stores the size if the map file
	int			lines;		// saves total number of lines in the chained list (data)

	t_m_data	*data;		// The chained list that contain each line of the map

	double		origine_x;	// Where should the ´x´ point of the map start
	double		origine_y;	// Where should the ´y´ point of the map start
	int			step;		// Distance between each points
	int 		color;

	struct s_fdfmap	*next;	// next map;
}	t_map;


typedef struct s_button
{
	int		id;					// Button id
	char	type;				// Button type (radiobutton/ clickable button)
	char	stat;				// Acitve, inactive etc...
	char	view[3][BUTTON_SIZE];			// Image / color in active, desctiv, hovrt etc... mode
	char	name[100];			// Button name (might be used for search or hover uses)
	int 	x;					// Width
	int 	y;					// Height
	int		o_x;				// Origine x
	int		o_y;				// origine y
	void 	*value;				// Contain some value
	void 	(*f)(void *root);	// A function to execute with a certain parameter
} t_button;

typedef struct s_char
{
	unsigned	ascii; // The ascii value
	// char		name[100]; // tmp
	int			x;	// width
	int			y;	// height
	char		data[CHAR_SIZE_28];	// Contain the image data
	int			pad_top;	// Top padding
	int			pad_left;	// Left paddin
	int			pad_right;	// Right padding
} t_char;

typedef t_char t_font;


// typedef struct s_alphabet
// {
//
// } t_alphabet;

typedef struct s_map_list
{
	int 	total_map;	// Total valide map files found
	char 	**map_name;	// Name of all files found
	int		curr_map; 	// current active map (-1) on error
	char	error;		// Set positive value on error else 0
	char	error_msg[MAX_ERROR_MSG + NAME_MAX];	// Error Message
	int		o_x;		// origine x
	int		o_y;		// origine y
	int		x;			// width
	int		y;			// heidth
} t_map_list;

typedef struct s_event_func
{
	int 	(*pmotion[3])(int x, int y, void *rot);	// A function to execut when an event occurs on a specific menu
	int 	(*kpress [3])(int key, void *rot);	// A function to execut when an event occurs on a specific menu
	int 	(*kreleas[3])(int key, void *rot);	// A function to execut when an event occurs on a specific menu
	int 	(*bpress [3])(int key, int x, int y, void *rot);	// A function to execut when an event occurs on a specific menu
	int 	(*breleas[3])(int key, int x, int y, void *rot);	// A function to execut when an event occurs on a specific menu

} t_event_func;


typedef struct s_menu
{
	t_image *img;			// Image of the section where we can modify
	char	hover;			// If there are any hoverable content present (0 (no) / 1 (yes))
	char	click;			// if there are any clickable content present (0 (no) / 1 (yes))
	void	(*hover_f)(void *root);	// Function to execute on click
	void	(*click_f)(void *root);	// Function to execute on click

	// t_button	opt[4]; // temp
	t_button	button[BUTTON_MAX];	// All graphical Buttons in the default menu including the top 3
	char 		curr_opt; // current selected option (controle / maps / information)
	// t_button	ctl[12];	// Controle buttons for the first option
	t_button	*maps;		// Maps as buttons as they might have undefined numbers for second option
	int 	mvment;			// Mouvements: 0[translation] 1[rotation]
	// char	c_opt;			// define at what options it is in 0 (default) 1 (chose map) 3 (info)
	int 	btn_hover;		// The button that was hovered
	int 	btn_clicked;	// The button was clicked

} t_menu;



// THe Main structure with window and all
typedef struct	s_root
{
	void	*mlx;	// Mlx pointer
	void	*win;	// Window pointer
	int		sz_x;	// Window Width
	int		sz_y;	// Window Height
	char	name[NAME_MAX + 5]; // Window name
	t_map *map;		// Stores the map to show in Preview section
	t_image	menu; 	// Menu section
	t_image	prev; 	// Previeu section
	t_image	foot; 	// Footer section
	// char	opt;	// This store the option you are in (Controle_map / Select_Map/ Info_fdf)
	t_menu 	men;
	int 	(*(kevent[MAX_EVENT_KEY]))(struct s_root *root); // Functions executed in key press
	t_event_func	evnt;
	int		key_set[MAX_EVENT_KEY];
	t_font	*font_24;
	t_font	*font_14;
} t_root;



int is_dot_fdf(char *str);
int		file_size(const char *name);
int		is_dir(const char *name);
int		is_file(const char *name);
t_point **data_to_array(t_map *map);
long 	*get_num(char *str, long o_line, int n_line, int dig);
int 	count_num(char *str, long o_line, long n_line);
t_map 	*map_malloc(t_image *img);
t_map	*get_map(char *name, t_image *img);

void	free_map(t_map *map);
void	print_map(t_map *map, int space);
int		pre_check(int argc, char **argv);
void	root_init(t_root *root, char **argv);


void	put_color(t_image *img, int x, int y, int col);
void	set_color(char *img, unsigned int len, int col);

void	init_menu(t_root *root, t_image *menu);
void	init_prev(t_root *root, t_image *prev);
void	init_foot(t_root *root, t_image *f);


void	event_handler(t_root *root);

// void	draw_line(t_image *img, t_point o, t_point n, int color);
void	draw_line(t_map  *map, t_point o, t_point n, int color);
void  	draw_dot(t_map *img, t_point o, t_point n, int color);
// void	draw_map(void *v, t_map *map, t_image *img);
void draw_map(void *img_ptr, t_map *map);


void modmatrix(t_map *map, void f(t_point *a, double val), double rot);
void rotate_x(t_point *a, double v);
void rotate_y(t_point *a, double v);
void rotate_z(t_point *a, double v);
void trans_x(t_map *a, double v);
void trans_y(t_map *a, double v);
void zoom(t_map *a, int v);

int k_up(t_root *root);
int k_down(t_root *root);
int k_right(t_root *root);
int k_left(t_root *root);
int k_plus(t_root *root);
int k_minus(t_root *root);
int k_x(t_root *root);
int k_s(t_root *root);
int k_y(t_root *root);
int k_u(t_root *root);
int k_z(t_root *root);
int k_a(t_root *root);
int k_esc(t_root *root);


int is_button_area(t_button *b, int x, int y);
void show_button(t_root *root, t_image *m);
void draw_button(t_button button, t_image *img, int stat);
void button_init(t_root *root, t_image *m);

int b0(t_root *root);
int b1(t_root *root);
int b2(t_root *root);
int b3(t_root *root);
int b4(t_root *root);
int b5(t_root *root);
int b6(t_root *root);
int b7(t_root *root);
int b8(t_root *root);
int b12(t_root *root);
int b13(t_root *root);

int pmotion_func_0(int x, int y, void *root);
int pmotion_func_1(int x, int y, void *root);
int pmotion_func_2(int x, int y, void *root);

int bpress_func_0(int key, int x, int y, void *rot);
int bpress_func_1(int key, int x, int y, void *rot);
int bpress_func_2(int key, int x, int y, void *rot);

void event_func_init(t_root *root);

/* font */
void printf_text(t_root *root, t_image *img, char *str, ...);
void draw_font(t_char chr, t_image *img, int o_x, int o_y, unsigned int col);


#endif
