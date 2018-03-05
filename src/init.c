#include "main.h"

void opt_init(t_button *button, int width, int height, int o_x)
{
	button->type = 1;
	button->stat = 0;
	// button->view = {NULL, NULL, NULL};
	button->x = width;
	button->y = height;
	button->o_x = o_x;
	button->o_y = 0;
	button->f = NULL;
}

void draw_button(t_button button, t_image *img, int color)
{
	int i = button.o_x;
	int j = button.o_y;

	while(j != button.o_y + button.y)
	{
		i = button.o_x;
		while (i++ != (button.o_x + button.x))
			put_color(img, i, j, color);
		j++;
	}
}

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

	root->men.img = m;
	root->men.max_opt = 3;
	opt_init(&(root->men.opt[0]), 133, 95, 0  );
	opt_init(&(root->men.opt[1]), 133, 95, 133);
	opt_init(&(root->men.opt[2]), 133, 95, 266);

	draw_button(root->men.opt[0], m, COLOR(root->mlx, 0x88d8b0));
	draw_button(root->men.opt[1], m, COLOR(root->mlx, 0xff6f69));
	draw_button(root->men.opt[2], m, COLOR(root->mlx, 0xffeead));

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
