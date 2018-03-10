#ifndef MAIN_H
# define MAIN_H

# include <limits.h>		// Get Path Name limits
# include <sys/stat.h>		// For file status
# include <fcntl.h>			// For open
# include <stdio.h>			// For printf
# include <unistd.h>		// For read
# include <errno.h>			// For read
# include <math.h>			// For read

# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"
# include "button_map.h"	// Tus use buttom macros
# include "nn_mask.h"		// Tus use buttom macros
// # include "mlx_int.h" 	// If included many errors appears

/* Main Winsow */
# define DEF_ROOT_X 1600		// Window width
# define DEF_ROOT_Y 950		// Window Height

# define ORIGINE_X  270.0f
# define ORIGINE_Y  290.0f
# define STEP 		30.0f

# define PREV_X DEF_ROOT_X
# define PREV_Y DEF_ROOT_Y

# define MENU_BG_COLOR	0x1b2d3b
# define PREV_BG_COLOR	0x021626
# define MAP_COLOR		0xe0e0bd

// -------------------

// Event Notification and mask shortcurring
// Notify NN_ButtonPress
# define PMOTION	NN_MotionNotify
# define KPRESS		NN_KeyPress
# define BPRESS		NN_ButtonPress
# define KRELEASE	NN_KeyRelease
# define VISIBL		NN_VisibilityNotify

// Masks
# define PMOTION_M	NN_PointerMotionMask
# define KPRESS_M	NN_KeyPressMask
# define BPRESS_M	NN_ButtonPressMask
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

// THe Main structure with window and all
typedef struct	s_root
{
	void	*mlx;	// Mlx pointer
	void	*win;	// Window pointer
	int		sz_x;	// Window Width
	int		sz_y;	// Window Height
	char	name[NAME_MAX + 5]; // Window name
	t_map *map;		// Stores the map to show in Preview section
	t_image	prev; 	// Previeu section
	void 	(*(kevent[MAX_EVENT_KEY]))(struct s_root *root); // Functions executed in key press
	int		key_set[MAX_EVENT_KEY];
} t_root;


int		file_size(const char *name);
t_map	*get_map(char *name, t_image *img);
int		is_dir(const char *name);
int		is_file(const char *name);
void	free_map(t_map *map);
void	print_map(t_map *map, int space);
int		pre_check(int argc, char **argv);
void	root_init(t_root *root, char **argv);


void	put_color(t_image *img, int x, int y, int col);
void	set_color(char *img, unsigned int len, int col);

// void	init_menu(t_root *root, t_image *menu);
void	init_prev(t_root *root, t_image *prev);
// void	init_foot(t_root *root, t_image *f);

void	event_handler(t_root *root);

void	draw_line(t_map  *map, t_point o, t_point n, int color);
void 	draw_map(void *img_ptr, t_map *map);



void modmatrix(t_map *map, void f(t_point *a, double val), double rot);
void rotate_x(t_point *a, double v);
void rotate_y(t_point *a, double v);
void rotate_z(t_point *a, double v);
void trans_x(t_map *a, double v);
void trans_y(t_map *a, double v);
void zoom(t_map *a, int v);

void k_up(t_root *root);
void k_down(t_root *root);
void k_right(t_root *root);
void k_left(t_root *root);
void k_plus(t_root *root);
void k_minus(t_root *root);
void k_x(t_root *root);
void k_s(t_root *root);
void k_y(t_root *root);
void k_u(t_root *root);
void k_z(t_root *root);
void k_a(t_root *root);
void k_esc(t_root *root);


#endif
