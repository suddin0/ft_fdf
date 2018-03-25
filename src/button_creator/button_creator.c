#include "main.h"
#include "button_creator.h"


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
	(*file)[jim] = 0;
	return (1);
}

void show_image(char *img, int x, int y)
{
	int i = 0;

	while(i++ != (x * y))
			printf("image i[%d] x[%d] y[%d] img[%d]\n", i, x, y, img[i]);
}



int main(int argc, char **argv)
{
	t_image ig[3]; // image
	char ***file;
	int i;
	t_button b[BUTTON_MAX];
	t_root root;
	t_b_create_data button_data[BUTTON_MAX]; // has information about buttons

	button_data_init(button_data);
	if(file_verif(argc, argv, &file) == -1)
		return (-1);
	root.mlx = mlx_init();
	i = 0;

	while (i != argc - 1)
	{
		(ig[0]).img_ptr = mlx_xpm_file_to_image(root.mlx, file[i][0], &((ig[0]).x), &((ig[0]).y));
		(ig[1]).img_ptr = mlx_xpm_file_to_image(root.mlx, file[i][1], &((ig[1]).x), &((ig[1]).y));
		(ig[2]).img_ptr = mlx_xpm_file_to_image(root.mlx, file[i][2], &((ig[2]).x), &((ig[2]).y));
		if(!((ig[0]).img_ptr) || !((ig[1]).img_ptr) || !((ig[2]).img_ptr))
		{
			printf("[-] Error: getting mlx image pointer\n");
			perror("[!] Reason");
			free_file(file, argc);
			return (-1);
		}

		(ig[0]).img = mlx_get_data_addr((ig[0]).img_ptr, &((ig[0]).bpp), &((ig[0]).sl), &((ig[0]).end));
		(ig[1]).img = mlx_get_data_addr((ig[1]).img_ptr, &((ig[1]).bpp), &((ig[1]).sl), &((ig[1]).end));
		(ig[2]).img = mlx_get_data_addr((ig[2]).img_ptr, &((ig[2]).bpp), &((ig[2]).sl), &((ig[2]).end));

		size_check(file[i][0], (ig[0]).x, (ig[0]).x, BUTTON_SIZE);
		size_check(file[i][1], (ig[1]).x, (ig[1]).x, BUTTON_SIZE);
		size_check(file[i][2], (ig[2]).x, (ig[2]).x, BUTTON_SIZE);
		printf("[file][%-40s] x[%3d] y[%3d] TOTAL[%d]\n", file[i][0], (ig[0]).x, (ig[0]).x, ((ig[0]).x * (ig[0]).x) * 4);

		struct_manage(ig, b, button_data, file[i][2]);

		mlx_destroy_image(root.mlx, (ig[0]).img_ptr);
		mlx_destroy_image(root.mlx, (ig[1]).img_ptr);
		mlx_destroy_image(root.mlx, (ig[2]).img_ptr);

		// printf("NAME [%s]\n", b[i].name);
		i++;
	}
	write_struct(b, BUTTON_STRUCT_PATH);

	free_file(file, argc);
	exit(0);
	return (0);
}
