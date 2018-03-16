#include "main.h"
#include "button_creator.h"





int main(int argc, char **argv)
{
	t_root root;
	t_char chr[FCHAR_MAX];
	t_image ig;
	int i;

	root.mlx = mlx_init();
	i = 1;

	while (i != argc)
	{
		ig.img_ptr = mlx_xpm_file_to_image(root.mlx, argv[i], &(ig.x), &(ig.y));
		if(!(ig.img_ptr))
		{
			printf("[-] Error: getting mlx image pointer for %s\n", argv[i]);
			perror("[!] Reason");
			// free_file(file, argc);
			exit(-1);
		}
		ig.img = mlx_get_data_addr(ig.img_ptr, &(ig.bpp), &(ig.sl), &(ig.end));
		// name_copy(char *dest, char *src);
		size_check(argv[i], ig.x, ig.x, CHAR_SIZE);

		chr[0].x = ig.x;
		chr[0].y = ig.y;
		printf("[FONT] IG.X[%d] - IG.Y[%d]  CHR.X[%d] - CHR.Y[%d]\n", ig.x, ig.y, chr[0].x, chr[0].y);

		chr[0].ascii = name_to_num(argv[i]);
		ft_memcpy(chr[0].data, ig.img, (ig.x * ig.y) * 4);

		// struct_manage(ig, b, button_data, file[i][2]);

		mlx_destroy_image(root.mlx, ig.img_ptr);
		// printf("NAME [%s]\n", b[i].name);
		i++;
	}
	write_struct_font(chr, FONT_STRUCT_PATH);

	// free_file(file, argc);
	exit(0);
	return (0);
}
