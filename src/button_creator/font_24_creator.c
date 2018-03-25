#include "main.h"
#include "button_creator.h"


void char_init(t_char *chr)
{
	chr->ascii		= 0;
	chr->data[0]	= 0;
	chr->x			= 0;
	chr->y			= 0;
	chr->pad_top	= 0;
	chr->pad_left	= 0;
	chr->pad_right	= 0;
}



int main(int argc, char **argv)
{
	t_root root;
	t_char chr[FCHAR_MAX];
	t_f_create_data fdata[FCHAR_MAX];
	t_image ig;
	int i;
	int ch_count;

	if(font_verif(argc, argv) == -1)
		return(-1);

	root.mlx = mlx_init();
	font24_struct_init(fdata);
	i = 1;
	ch_count = 0;
	char_init(&(chr[ch_count++]));
	chr[0].ascii = 32;
	while (i != argc)
	{
		ig.img_ptr = mlx_xpm_file_to_image(root.mlx, argv[i], &(ig.x), &(ig.y));
		if(!(ig.img_ptr))
		{
			printf("[-] Error: getting mlx image pointer for %s\n", argv[i]);
			perror("[!] Reason");
			exit(-1);
		}
		ig.img = mlx_get_data_addr(ig.img_ptr, &(ig.bpp), &(ig.sl), &(ig.end));
		if(!(ig.img))
		{
			printf("[-] Error: getting mlx data pointer for [%s]\n", argv[i]);
			perror("[!] Reason");
			exit(-1);
		}
		char_init(&(chr[ch_count]));
		size_check(argv[i], ig.x, ig.x, CHAR_SIZE_28);
		chr[ch_count].x = ig.x;
		chr[ch_count].y = ig.y;
		chr[ch_count].ascii = name_to_num(argv[i]);
		ft_memcpy(chr[ch_count].data, ig.img, (ig.x * ig.y) * 4);
		mlx_destroy_image(root.mlx, ig.img_ptr);
		i++;
		ch_count++;
	}
	font_struct_manage(chr, fdata);
	write_struct_font(chr, FONT_24_STRUCT_PATH);
	exit(0);
	return (0);
}
