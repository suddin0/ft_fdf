#include "button_creator.h"



void struct_manage(t_image *ig, t_button *b, t_b_create_data *bdata, char *fn)
{
	int i;
	char name[100];

	i = 0;
	name_copy(name, fn);
	printf("CAME INSIDE STRUCT_MANAGE NAME[%s]\n", name);
	while (i < BUTTON_MAX)
	{
		// printf("STRUCT_MANAGE MAIN I[%d] bname[%s] name[%s] cmp[%d]\n", i, bdata[i].name, name, ft_strcmp(name, bdata[i].name));
		if(ft_strcmp(name, bdata[i].name) == 0)
		{
			printf("STRUCT_MANAGE IF-- I[%d] [%s] ******\n", i, bdata[i].name);
			b[i].id = bdata[i].id;
			b[i].type = bdata[i].type;
			b[i].stat = bdata[i].stat;
			ft_memcpy((b[i].view)[0], (ig[0]).img, ((ig[0]).x * (ig[0]).y) * 4);
			ft_memcpy((b[i].view)[1], (ig[1]).img, ((ig[1]).x * (ig[1]).y) * 4);
			ft_memcpy((b[i].view)[2], (ig[2]).img, ((ig[2]).x * (ig[2]).y) * 4);
			name_copy ((b[i]).name, name);
			b[i].x = (ig[0]).x;
			b[i].y = (ig[0]).y;
			b[i].o_x = bdata[i].o_x;
			b[i].o_y = bdata[i].o_y;

			break;
		}
		i++;
	}
	// mlx_destroy_image(root.mlx, (ig[0]).img_ptr);
	// mlx_destroy_image(root.mlx, (ig[1]).img_ptr);
	// mlx_destroy_image(root.mlx, (ig[2]).img_ptr);
}
