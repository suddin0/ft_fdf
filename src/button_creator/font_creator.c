#include "main.h"
#include "button_creator.h"


void char_init(t_char *chr)
{
	chr->ascii		= 0;
	chr->data[0]	= 0;
	chr->x			= 0;
	chr->y			= 0;
}


int main(int argc, char **argv)
{
	t_root root;
	t_char chr[FCHAR_MAX];
	t_image ig;
	int i;
	int ch_count;

	root.mlx = mlx_init();
	i = 1;
	ch_count = 0;

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
		if(!(ig.img))
		{
			printf("[-] Error: getting mlx data pointer for [%s]\n", argv[i]);
			perror("[!] Reason");
			// free_file(file, argc);
			exit(-1);
		}
		char_init(&(chr[ch_count]));
		// name_copy(char *dest, char *src);
		size_check(argv[i], ig.x, ig.x, CHAR_SIZE_28);

		chr[ch_count].x = ig.x;
		chr[ch_count].y = ig.y;
		chr[ch_count].ascii = name_to_num(argv[i]);
		printf("[FONT][%3d][%c] IG.X[%3d] - IG.Y[%3d]  CHR.X[%3d] - CHR.Y[%3d] MAX[%3d] TOTAL[%d]\n", i, chr[ch_count].ascii, ig.x, ig.y, chr[ch_count].x, chr[ch_count].y, ig.x * ig.y, ( ig.x * ig.y) * 4);

		ft_memcpy(chr[ch_count].data, ig.img, (ig.x * ig.y) * 4);

		// struct_manage(ig, b, button_data, file[i][2]);

		mlx_destroy_image(root.mlx, ig.img_ptr);
		// printf("NAME [%s]\n", b[i].name);
		i++;
		ch_count++;
	}
	write_struct_font(chr, FONT_STRUCT_PATH);

	// free_file(file, argc);
	exit(0);
	return (0);
}


// 1428
// 2088
// 1344
// 2088
// 1596
// 1456
// 2088
// 1904
// 336
// 1152
// 2016
// 336
// 2520
// 1428
// 1596
// 2088
// 2088
// 1008
// 1344
// 1352
// 1428
// 1600
// 2160
// 1600
// 2240
// 1280
