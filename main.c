#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int is_dot_fdf(char *str)
{
	int i;

	i = ft_strlen(str);
	if (ft_strcmp(&(str[ft_strlen(str) - 4]), ".fdf") == 0)
		return (1);
	else
		return (0);
}

void root_init(t_root *root, char **argv)
{
	root->mlx = mlx_init();
	root->sz_x = DEF_ROOT_X;
	root->sz_y = DEF_ROOT_Y;
	ft_strcpy(root->name, argv[1]);
	ft_putstr(root->name);
	root->win = mlx_new_window(root->mlx, root->sz_x, root->sz_y, root->name);
}

int pre_check(int argc, char **argv)
{
	if(argc < 2)
	{
		ft_putstr("[-] Error: Not enough argument\n");
		return (0);
	}
	else if(argc > 2)
	{
		ft_putstr("[-] Error: Tooo much arguments\n");
		return (0);
	}
	else if(ft_strlen(argv[1]) > NAME_MAX)
	{
		ft_putstr("[-] Error: File name Too long\n");
		return (0);
	}
	else if(is_dot_fdf(argv[1]) == 0)
	{
		ft_putstr("[-] Error: File do not have .fdf extention\n");
		return (0);
	}
	else
		return (1);

}
int main(int argc, char **argv)
{
	t_root root;

	if(pre_check(argc, argv) == 0)
		return (0);
	root_init(&root, argv);

	printf("is dot fdf [%d]\n", is_dot_fdf(argv[1]));
	printf("WIN_X = [%d]\n", root.sz_x);
	printf("WIN_Y = [%d]\n", root.sz_y);

	mlx_loop(root.mlx);

	return (0);
}
