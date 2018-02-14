#ifndef MAIN_H
# define MAIN_H

# include <limits.h>	// Get Path Name limits
# include <sys/stat.h>	// For file status
# include <fcntl.h>		// For open
# include <stdio.h>		// For printf
# include <unistd.h>	// For read
# include <errno.h>	// For read

# include "libft.h"
# include "mlx.h"

# define DEF_ROOT_X 200	// Window width
# define DEF_ROOT_Y 200	// Window Height

// THe Main structure with window and all
typedef struct	s_root
{
	void *mlx;
	void *win;
	int sz_x;
	int sz_y;
	char name[NAME_MAX + 5];
} t_root;

// contain map object data and various informations about it
typedef struct S_MAP_DATA
{
	int			row;	// 	( - ) saves information about current line number
	int			col;	//	( | ) saves the number of columns there are
	long int 	*data;	// the data (the information about the `Z` axis from each line of the map)
	struct S_MAP_DATA	*next;
}	T_M_DATA;

typedef struct S_FDFMAP
{
	char		*name;		// stores the maps name
	char		*path;		// stores the maps path
	long		**map;		// stores the map as an long int table[data->col][data->raw]
	long		*line_sz;	// stores the amount of number a line contains (for looping purpose)
	int			file_sz;	// stores the size if the map file
	int			lines;		// saves total number of lines in the chained list (data)
	T_M_DATA	*data;		// The chained list that contain each line of the map

	struct S_FDFMAP	*next;	// next map;
}	T_MAP;



int file_size(const char *name);
T_MAP *get_map(char *name);
int is_dir(const char *name);
int is_file(const char *name);


#endif

