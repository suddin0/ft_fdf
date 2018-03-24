#include "main.h"


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
	root->kevent[12]	= k_esc;
	root->kevent[13]	= k_esc;
}

void key_set_init(int *set)
{
	set[0] = BTN_UP;
	set[1] = BTN_DOWN;
	set[2] = BTN_RIGT;
	set[3] = BTN_LEFT;
	set[4] = BTN_PLUS;
	set[5] = BTN_MINUS;
	set[6] = BTN_X;
	set[7] = BTN_S;
	set[8] = BTN_Y;
	set[9] = BTN_U;
	set[10] = BTN_Z;
	set[11] = BTN_A;
	set[12] = BTN_Q;
	set[13] = BTN_ESC;
}

inline static void init_var(t_map_list *list)
{
	list->total_map = 0;
	list->curr_map = -1;
	list->map_name = NULL;
	list->error = 0; // no rror
	list->o_x = 0;
	list->o_y = MAP_LIST_OY;
	list->x = MENU_X;
	list->y = MENU_Y + list->o_y;
	list->height = 90;
	list->border = 1;
	list->border_active = 2;
}

void init_menu(t_root *root, t_image *m)
{
	int fd;
	m->o_x = 0;
	m->o_y = 0;
	m->x = MENU_X;
	m->y = MENU_Y;
	m->bg = COLOR(root->mlx, MENU_BG_COLOR);

	m->img_ptr = mlx_new_image(root->mlx, m->x , m->y);
	m->img = mlx_get_data_addr(m->img_ptr, &(m->bpp), &(m->sl), &(m->end));
	set_color(m->img, m->x * m->y, m->bg);
	root->men.curr_opt = 0;
	button_init(root, m);
	init_var(&(root->men.list));
	mlx_put_image_to_window(root->mlx, root->win, m->img_ptr, m->o_x, m->o_y);
}


void init_prev(t_root *root, t_image *p)
{
	p->o_x = MENU_X;
	p->o_y = 0;
	p->x = PREV_X;
	p->y = PREV_Y;
	p->bg = COLOR(root->mlx, PREV_BG_COLOR);

	p->img_ptr = mlx_new_image(root->mlx, p->x, p->y);
	p->img = mlx_get_data_addr(p->img_ptr, &(p->bpp), &(p->sl), &(p->end));

	set_color(p->img, p->x * p->y, p->bg);
	mlx_put_image_to_window(root->mlx, root->win, p->img_ptr, p->o_x, p->o_y);

	kevent_init(root);
	key_set_init(root->key_set);
}

void init_foot(t_root *root, t_image *f)
{
	f->o_x = MENU_X;
	f->o_y = PREV_Y;
	f->x = FOOT_X;
	f->y = FOOT_Y;
	f->bg = COLOR(root->mlx, FOOT_BG_COLOR);

	f->img_ptr = mlx_new_image(root->mlx, f->x, f->y);
	f->img = mlx_get_data_addr(f->img_ptr, &(f->bpp), &(f->sl), &(f->end));

	set_color(f->img, f->x * f->y, f->bg);
	mlx_put_image_to_window(root->mlx, root->win, f->img_ptr, f->o_x, f->o_y);
}
