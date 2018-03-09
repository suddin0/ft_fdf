#include "main.h"


void init_prev(t_root *root, t_image *p)
{
	p->o_x = 0;
	p->o_y = 0;
	p->x = PREV_X;
	p->y = PREV_Y;
	p->bg = COLOR(root->mlx, 0x021626);

	p->img_ptr = mlx_new_image(root->mlx, p->x, p->y);
	p->img = mlx_get_data_addr(p->img_ptr, &(p->bpp), &(p->sl), &(p->end));

	set_color(p->img, p->x * p->y, p->bg);
	mlx_put_image_to_window(root->mlx, root->win, p->img_ptr, p->o_x, p->o_y);
}

void kevent_init(t_root *root)
{
	root->kevent[0]		= k_up;
	root->kevent[1]		= k_down;
	root->kevent[2]		= k_right;
	root->kevent[3]		= k_left;
	root->kevent[4]		= k_plus;
	root->kevent[5]		= k_minus;
	root->kevent[6]		= k_x;
	root->kevent[7]		= k_s;
	root->kevent[8]		= k_y;
	root->kevent[9]		= k_u;
	root->kevent[10]	= k_z;
	root->kevent[11]	= k_a;
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
	kevent_init(root);

}
