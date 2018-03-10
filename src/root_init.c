#include "main.h"


void root_init(t_root *root, char **argv)
{
	root->mlx = mlx_init();
	root->sz_x = DEF_ROOT_X;
	root->sz_y = DEF_ROOT_Y;
	ft_memset(root->name, 0, NAME_MAX + 5);
	ft_strncpy(root->name, argv[1], strlen(argv[1]) - 4);
	ft_putstr(root->name);
	root->win = mlx_new_window(root->mlx, root->sz_x, root->sz_y, root->name);
}
