#include "main.h"


void init_menu(t_root *root, t_image *m)
{
	m->o_x = 0;
	m->o_y = 0;
	m->x = MENU_X;
	m->y = MENU_Y;
	m->bg = COLOR(root->mlx, 0x1b2d3b);

	m->img_ptr = mlx_new_image(root->mlx, m->x , m->y);
	m->img = mlx_get_data_addr(m->img_ptr, &(m->bpp), &(m->sl), &(m->end));
	set_color(m->img, m->x * m->y, m->bg);
	mlx_put_image_to_window(root->mlx, root->win, m->img_ptr, m->o_x, m->o_y);
}


void init_prev(t_root *root, t_image *p)
{
	p->o_x = MENU_X;
	p->o_y = 0;
	p->x = PREV_X;
	p->y = PREV_Y;
	p->bg = COLOR(root->mlx, 0x021626);

	p->img_ptr = mlx_new_image(root->mlx, p->x, p->y);
	p->img = mlx_get_data_addr(p->img_ptr, &(p->bpp), &(p->sl), &(p->end));

	set_color(p->img, p->x * p->y, p->bg);
	mlx_put_image_to_window(root->mlx, root->win, p->img_ptr, p->o_x, p->o_y);
}

void init_foot(t_root *root, t_image *f)
{
	f->o_x = MENU_X;
	f->o_y = PREV_Y;
	f->x = FOOT_X;
	f->y = FOOT_Y;
	f->bg = COLOR(root->mlx, 0x1b2d3b);

	f->img_ptr = mlx_new_image(root->mlx, f->x, f->y);
	f->img = mlx_get_data_addr(f->img_ptr, &(f->bpp), &(f->sl), &(f->end));

	set_color(f->img, f->x * f->y, f->bg);
	mlx_put_image_to_window(root->mlx, root->win, f->img_ptr, f->o_x, f->o_y);
}
