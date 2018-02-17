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


// contain map object data and various informations about it
typedef struct s_map_data
{
	int			row;	// 	( - ) saves information about current line number
	int			col;	//	( | ) saves the number of columns there are
	long int 	*data;	// the data (the information about the `Z` axis from each line of the map)
	struct s_map_data	*next;
}	t_m_data;

typedef struct s_fdfmap
{
	char		*name;		// stores the maps name
	char		*path;		// stores the maps path
	long		**map;		// stores the map as an long int table[data->col][data->raw]
	long		*line_sz;	// stores the amount of number a line contains (for looping purpose)
	int			file_sz;	// stores the size if the map file
	int			lines;		// saves total number of lines in the chained list (data)
	t_m_data	*data;		// The chained list that contain each line of the map

	struct s_fdfmap	*next;	// next map;
}	t_map;

// THe Main structure with window and all
typedef struct	s_root
{
	void *mlx;
	void *win;
	int sz_x;
	int sz_y;
	char name[NAME_MAX + 5];
	t_map *map;
} t_root;



int file_size(const char *name);
t_map *get_map(char *name);
int is_dir(const char *name);
int is_file(const char *name);
void free_map(t_map *map);
#endif

