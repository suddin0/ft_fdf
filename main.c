#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int get_root_sz(char **argv, char *sz, int  flag)
{
	int i;

	i = 0;
	printf("CAME HEER IN GET_ROOT_SZ\n");
	while(argv[i])
	{
		if (ft_memcmp(sz, argv[i], ft_strlen(sz) == 0))
				return (ft_atoi(&(argv[i][ft_strlen(sz)])));
		i++;
	}
	if (flag == 0)
		return (DEF_ROOT_X);
	else
		return (DEF_ROOT_Y);
}



void root_init(t_root *root, char **argv)
{
	root->mlx = mlx_init();
	root->sz_x = get_root_sz(argv, "win_x=", 0);
	root->sz_y = get_root_sz(argv, "win_y=", 1);

	root->win = mlx_new_window(root->mlx, root->sz_x, root->sz_y, root->name);
}

int main(int argc, char **argv)
{
	t_root root;

	root_init(&root, &(argv[2]));
	printf("WIN_X = [%d]\n", root.sz_x);
	printf("WIN_Y = [%d]\n", root.sz_y);
	printf("Hello there NAME_MAX[%d]\n", NAME_MAX);


	return (0);
}
