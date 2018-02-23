#ifndef MAIN_H
# define MAIN_H

# include <limits.h>		// Get Path Name limits
# include <sys/stat.h>		// For file status
# include <fcntl.h>			// For open
# include <stdio.h>			// For printf
# include <unistd.h>		// For read
# include <errno.h>			// For read

# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"
# include "button_map.h"	// Tus use buttom macros


# define DEF_ROOT_X 1200		// Window width
# define DEF_ROOT_Y 700		// Window Height

# define ORIGINE_X  100.0f
# define ORIGINE_Y  170.0f
# define STEP  30.0f
//# define get_col(r, g, b, a) ((r << 16) + (g << 8) + (b) + ((a << 24) * -1))
//# define STEP_X 10;


typedef struct	s_color  // Converts colors
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char a;
}		t_color;

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

typedef struct s_fdfmap
{
	char		*name;		// stores the maps name
	char		*path;		// stores the maps path
	//long		**map;		// stores the map as an long int table[data->col][data->raw]
	t_point		**map;	// stores the map as an long int table[data->col][data->raw]
	long		*line_sz;	// stores the amount of number a line contains (for looping purpose)
	int			file_sz;	// stores the size if the map file
	int			lines;		// saves total number of lines in the chained list (data)

	t_m_data	*data;		// The chained list that contain each line of the map

	double		origine_x;	// Where should the ´x´ point of the map start
	double		origine_y;	// Where should the ´y´ point of the map start
	int			step;		// Distance between each points

	struct s_fdfmap	*next;	// next map;
}	t_map;

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
} t_img;

// THe Main structure with window and all
typedef struct	s_root
{
	void *mlx;
	void *win;
	int sz_x;
	int sz_y;
	char name[NAME_MAX + 5];
	t_map *map;
	void *img_ptr;
	char *img;
	t_img menu;
	t_img prev;
} t_root;



int		file_size(const char *name);
t_map	*get_map(char *name);
int		is_dir(const char *name);
int		is_file(const char *name);
void	free_map(t_map *map);
void	print_map(t_map *map, int space);
int		pre_check(int argc, char **argv);
void	root_init(t_root *root, char **argv);

t_color	get_col(int r, int g, int b, int a);
void	put_color(t_img *img, int x, int y, t_color col);
void	set_color(char *img, unsigned int len, t_color col);

void init_menu(t_root *root, t_img *menu);
void init_prev(t_root *root, t_img *prev);



#endif
