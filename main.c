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
	ft_memset(root->name, 0, NAME_MAX + 5);
	ft_strncpy(root->name, argv[1], strlen(argv[1]) - 4);
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

void print_map(t_map *map, int space)
{
	int l;
	int p;
	int num_sz;


	l = 0;
	p = 0;
	num_sz = 0;
	while (l < map->lines)
	{
		while (p < map->line_sz[l])
		{
			num_sz = ft_intlen(map->map[l][p]);
			if ((space - num_sz) > 0)
				ft_putnchar(' ', space - num_sz);
			ft_putnbr(map->map[l][p]);
			p++;
		}
		ft_putchar('\n');
		p = 0;
		l++;
	}
}

int	exit_esc(int key, t_root *root)
{
	//root->key_pressed = key;

	if(key == BTN_ESC || key == BTN_Q)
	{
		mlx_destroy_window(root->mlx,root->win);
		free_map(root->map);
		printf("Key pressed %d\n", key);
		printf("[!] Exiting the programme\n");
		exit(EXIT_SUCCESS);
	}
	else
		printf("Key pressed %d\n", key);
	return (0);
}

int main(int argc, char **argv)
{
	t_root root;
	t_map *map;

	map = NULL;
	if(pre_check(argc, argv) == 0)
		return (0);
	root_init(&root, argv);

	printf("is dot fdf [%d]\n", is_dot_fdf(argv[1]));
	map = get_map(argv[1]);
	root.map = map;

	printf("******** END OF PERSING *********\n");
	print_map(map, 2);

	mlx_key_hook (root.win , exit_esc, &root);
	mlx_loop(root.mlx);


	return (0);
}
