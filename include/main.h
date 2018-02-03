#ifndef MAIN_H
# define MAIN_H

#include <limits.h>
#include "libft.h"
#include "mlx.h"

# define DEF_ROOT_X 200
# define DEF_ROOT_Y 200


typedef struct	s_root
{
	void *mlx;
	void *win;
	int sz_x;
	int sz_y;
	char name[NAME_MAX + 5];
} t_root;

#endif

