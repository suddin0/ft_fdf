#include "button_creator.h"



void struct_manage(t_image *ig, t_button *b, t_b_create_data *bdata, char *fn)
{
	int i;
	char name[100];

	i = 0;
	name_copy(name, fn);
	// printf("CAME INSIDE STRUCT_MANAGE NAME[%s]\n", name);
	printf("------------STRUCT MANAGE------------\n");
	while (i < BUTTON_MAX)
	{
		printf("[%3d] bname[%9s] name[%9s] cmp[%3d]\n", i, bdata[i].name, name, ft_strcmp(name, bdata[i].name));
		if(ft_strcmp(name, bdata[i].name) == 0)
		{
			// clear_button(b);
			// printf("STRUCT_MANAGE IF-- I[%d] [%s] ******\n", i, bdata[i].name);
			b[i].id		= bdata[i].id;
			b[i].type	= bdata[i].type;
			b[i].stat	= bdata[i].stat;

			ft_memcpy((b[i].view)[0], (ig[0]).img, ((ig[0]).x * (ig[0]).y) * 4);
			ft_memcpy((b[i].view)[1], (ig[1]).img, ((ig[1]).x * (ig[1]).y) * 4);
			ft_memcpy((b[i].view)[2], (ig[2]).img, ((ig[2]).x * (ig[2]).y) * 4);
			name_copy ((b[i]).name, name);
			b[i].x = (ig[0]).x;
			b[i].y = (ig[0]).y;

			b[i].o_x = bdata[i].o_x;
			b[i].o_y = bdata[i].o_y;
			ft_printf("[OK][%-2d][%-8s]: b.stat[%-2d]  - bdata.stat[%-2d]\n",i, bdata[i].name, b[i].stat, bdata[i].stat);
			ft_printf("[OK][%-2d][%-8s]: b.x   [%-2d]  - b.y   [%-2d]\n",i, bdata[i].name, b[i].x,b[i].y);
			ft_printf("[OK][%-2d][%-8s]: b.o_x [%-2d]  - b.o_y [%-2d]\n",i, bdata[i].name, b[i].o_x, b[i].o_y);
			break;
		}
		i++;
	}
	printf("------------STRUCT MANAGE END------------\n");
	// mlx_destroy_image(root.mlx, (ig[0]).img_ptr);
	// mlx_destroy_image(root.mlx, (ig[1]).img_ptr);
	// mlx_destroy_image(root.mlx, (ig[2]).img_ptr);
}
