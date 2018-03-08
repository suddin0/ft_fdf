#include "main.h"

int file_check(int argc, char ***argv)
{
	int i;

	i = 0;
	while (i != argc - 1)
	{
		printf("CAME IIN FILE_CHECK [%d] [%s] - [%s] - [%s]\n", i, argv[i][0], argv[i][1], argv[i][2]);
		if(is_file(argv[i][0]) <= 0 || is_file(argv[i][1]) <= 0 || is_file(argv[i][2]) <= 0)
			return (i + 1);
		i++;
	}
	return (0);
}

void clear_button(t_button *button)
{
	button->type = 0;
	button->stat = 0;
	memset(button->view[0], 0, BUTTON_SIZE);
	memset(button->view[1], 0, BUTTON_SIZE);
	memset(button->view[2], 0, BUTTON_SIZE);
	memset(button->view[2], 0, BUTTON_SIZE);
	memset(button->name	  , 0, 100);
	button->x		= 0;
	button->y		= 0;
	button->o_x		= 0;
	button->o_y		= 0;
	button->value	= NULL;
	button->f		= NULL;

}

int create_name(char ****file, int argc, char **argv)
{
	int lim;
	int jim;

	lim = 1;
	jim = 0;
	if((*file = (char ***) malloc(sizeof(char **) * (argc))) == NULL)
		return -1;
	memset(*file, 0, argc);
	while(lim != argc)
	{
		printf("INSIDE WHILE [jim][%d]\n", jim);
		if (((*file)[jim] = (char **) malloc(sizeof(char *) * 3)) == NULL)
			return (-1);
		if (((*file)[jim][0] = ft_strnew(ft_strlen(argv[lim]) + 7)) == NULL) // The +6 is for the
			return (-1);											 // Extention and the extra number befor
		if (((*file)[jim][1] = ft_strnew(ft_strlen(argv[lim]) + 7)) == NULL) // The +6 is for the
			return (-1);											 // Extention and the extra number befor
		if (((*file)[jim][2] = ft_strnew(ft_strlen(argv[lim]) + 7)) == NULL) // The +6 is for the
			return (-1);											 // Extention and the extra number befor

		ft_strcpy((*file)[jim][0], argv[lim]);
		ft_strcpy((*file)[jim][1], argv[lim]);
		ft_strcpy((*file)[jim][2], argv[lim]);

		ft_strcat((*file)[jim][0], "_0.xpm");
		ft_strcat((*file)[jim][1], "_1.xpm");
		ft_strcat((*file)[jim][2], "_2.xpm");

		jim++;
		lim++;
	}
	// printf("I AFTER MALLOCS [%d]\n", jim);
	(*file)[jim] = 0;
	return (1);
}

// static void r_init(t_root *root, char **argv)
// {
// 	root->mlx = mlx_init();
// 	root->sz_x = DEF_ROOT_X;
// 	root->sz_y = DEF_ROOT_Y;
// 	ft_memset(root->name, 0, NAME_MAX + 5);
// 	ft_strncpy(root->name, argv[1], strlen(argv[1]) - 4);
// 	// ft_putstr(root->name);
// 	// root->win = mlx_new_window(root->mlx, root->sz_x, root->sz_y, root->name);
// }

static void free_file(char ***file, int argc)
{
	int i;

	i = 0;
	while(i != argc && file[i])
	{
		printf("i[%d]\n", i);
		free((file[i])[0]);
		free((file[i])[1]);
		free((file[i])[2]);
		free(file[i]);
		i++;
	}
	free(file);
}


void name_copy(char *dest, char *src)
{
	int len;
	int start;
	int end;

	if(!dest || src)
		return;
	start = 0;
	len = ft_strlen(src);
	while(len--)
		if (src[len] == '/')
			start = len + 1;
	end =  ft_strlen(&(src[start])) - 5;
	ft_strncpy(&(dest[start]), src, end);
}


void size_check(char *name, int a, int  b)
{
	if ((a * b) > BUTTON_SIZE)
	{
		ft_printf("[-] Error size: %s is too larg to hold in stake %dmb, max size %dmb\n", name, a * b, BUTTON_SIZE);
		exit(-1);
	}
}
int main(int argc, char **argv)
{

	// void *img_ptr[3];
	// char *img[3];

	t_image ig[3]; // image
	char ***file;
	int i;
	int file_error;
	t_button b;
	t_root root;


	if (argc < 2)
	{
		ft_printf("[!] No file was given as arguments\n");
		return (-1);
	}

	if (create_name(&file, argc, argv) != 1)
	{
		ft_printf("[-] Error setting file name in create_name(...) function");
		return (-1);
	}
	if((file_error = file_check(argc, file)) != 0)
	{
		ft_printf("[-] Error files: %s\n", argv[file_error]);
		free_file(file, argc);
		return (-1);
	}
	file_error = -1;
	root.mlx = mlx_init();
	i = 0;
	int ll = 0;
	while(file[ll] && ll != argc)
	{
		printf("[%3d] : [0][%40s] - [1][%40s] - [2][%40s]\n", ll, file[ll][0], file[ll][1], file[ll][2]);
		ll++;
	}
	i = 0;

	while (i != argc - 1)
	{
		printf("CAME HERE WHINE in MAIN\n");
		clear_button(&b);
		(ig[0]).img_ptr = mlx_xpm_file_to_image(root.mlx, file[i][0], &((ig[0]).x), &((ig[0]).y));
		(ig[1]).img_ptr = mlx_xpm_file_to_image(root.mlx, file[i][1], &((ig[1]).x), &((ig[1]).y));
		(ig[2]).img_ptr = mlx_xpm_file_to_image(root.mlx, file[i][2], &((ig[2]).x), &((ig[2]).y));

		(ig[0]).img = mlx_get_data_addr((ig[0]).img_ptr, &((ig[0]).bpp), &((ig[0]).sl), &((ig[0]).end));
		(ig[1]).img = mlx_get_data_addr((ig[1]).img_ptr, &((ig[1]).bpp), &((ig[1]).sl), &((ig[1]).end));
		(ig[2]).img = mlx_get_data_addr((ig[2]).img_ptr, &((ig[2]).bpp), &((ig[2]).sl), &((ig[2]).end));

		size_check(file[i][0], (ig[0]).x, (ig[0]).x);
		size_check(file[i][1], (ig[1]).x, (ig[1]).x);
		size_check(file[i][2], (ig[2]).x, (ig[2]).x);

		b.type = 0;
		b.stat = 0;
		ft_strncpy((b.view)[0], (ig[0]).img, (ig[0]).x * (ig[0]).y);
		ft_strncpy((b.view)[1], (ig[1]).img, (ig[1]).x * (ig[1]).y);
		ft_strncpy((b.view)[2], (ig[2]).img, (ig[2]).x * (ig[2]).y);
		name_copy (b.name, file[i][0]);


		mlx_destroy_image(root.mlx, (ig[0]).img_ptr);
		mlx_destroy_image(root.mlx, (ig[1]).img_ptr);
		mlx_destroy_image(root.mlx, (ig[2]).img_ptr);
		printf("NAME [%s]", b.name);
		i++;
	}

	free_file(file, argc);
	exit(0);
	return (0);
}
