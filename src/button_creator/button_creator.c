#include "main.h"
#include "button_creator.h"


// int file_check(int argc, char ***argv)
// {
// 	int i;
//
// 	i = 0;
// 	while (i != argc - 1)
// 	{
// 		printf("CAME IIN FILE_CHECK [%d] [%s] - [%s] - [%s]\n", i, argv[i][0], argv[i][1], argv[i][2]);
// 		if(is_file(argv[i][0]) <= 0 || is_file(argv[i][1]) <= 0 || is_file(argv[i][2]) <= 0)
// 			return (i + 1);
// 		i++;
// 	}
// 	return (0);
// }

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


// void name_copy(char *dest, char *src)
// {
// 	int len;
// 	int start;
// 	int end;
// 	int i;
//
// 	if(!dest || !src)
// 		return;
// 	start = 0;
// 	i = 0;
// 	len = ft_strlen(src);
// 	while(len-- && src[len] != '/');
// 	start = (len == 0) ? len : len + 1;
// 	end =  ft_strlen(&(src[start])) - 6;
// 	while (i != end && src[start])
// 		dest[i++] = src[start++];
// 	dest[i] = 0;
// }

//
// void size_check(char *name, int a, int  b)
// {
// 	if ((a * b) > BUTTON_SIZE)
// 	{
// 		ft_printf("[-] Error size: %s is too larg to hold in stake %dmb, max size %dmb\n", name, a * b, BUTTON_SIZE);
// 		exit(-1);
// 	}
// }


// void write_struct(t_button b[], char *path)
// {
// 	int fd;
//
// 	fd = open(path, O_WRONLY | O_CREAT, 0644);
// 	write(fd, b, sizeof(t_button) * BUTTON_MAX);
// 	close(fd);
// }

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
