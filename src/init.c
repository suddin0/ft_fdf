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

void draw_button2(t_button button, t_image *img, int stat)
{
	int x;
	int y;
	int k;

	x = button.o_x * 4;
	y = button.o_y;
	k = 0;
	while (y < button.o_y + button.y)
	{
		x = button.o_x * 4;
		while (x < (button.o_x + button.x) * 4)
		{
			// We multiply img->x by 4 because the real size of img is 4 times bigger then it seems
			if(x > 0 && y > 0 && (x + (y * img->x * 4)) < (img->x * img->y) * 4)
			{
				(img->img)[x + 0 + (y * (img->x * 4))]  = (button.view[stat])[k + 0];
				(img->img)[x + 1 + (y * (img->x * 4))]  = (button.view[stat])[k + 1];
				(img->img)[x + 2 + (y * (img->x * 4))]  = (button.view[stat])[k + 2];
				(img->img)[x + 3 + (y * (img->x * 4))]  = (button.view[stat])[k + 3];
			}
			k += 4;
			x += 4;
		}
		y++;
	}
}

void show_image(char *img, int x, int y)
{
	int i = 0;

	while(i++ != (x * y))
			printf("image i[%d] x[%d] y[%d] img[%d]\n", i, x, y, img[i]);
}

void def_opt_init(t_root *root)
{
	opt_init(&(root->men.opt[0]), OPT_X, OPT_Y, 0		 );
	opt_init(&(root->men.opt[1]), OPT_X, OPT_Y, OPT_X	 );
	opt_init(&(root->men.opt[2]), OPT_X, OPT_Y, OPT_X * 2);

	// ctl_init(&(root->men.opt[0]), 0, 0, 0 );
}





void init_menu(t_root *root, t_image *m)
{
	int fd;
	m->o_x = 0;
	m->o_y = 0;
	m->x = MENU_X;
	m->y = MENU_Y;
	m->bg = COLOR(root->mlx, 0x1b2d3b);

	m->img_ptr = mlx_new_image(root->mlx, m->x , m->y);
	m->img = mlx_get_data_addr(m->img_ptr, &(m->bpp), &(m->sl), &(m->end));
	set_color(m->img, m->x * m->y, m->bg);

	root->men.img = m;
	// root->men.max_opt = 3;
	root->men.c_opt = 0;
	opt_init(&(root->men.opt[0]), OPT_X, OPT_Y, 0			);
	opt_init(&(root->men.opt[1]), OPT_X, OPT_Y, OPT_X		);
	opt_init(&(root->men.opt[2]), OPT_X, OPT_Y, OPT_X * 2	);

	draw_button(root->men.opt[0], m, COLOR(root->mlx, 0x88d8b0));
	draw_button(root->men.opt[1], m, COLOR(root->mlx, 0xff6f69));
	draw_button(root->men.opt[2], m, COLOR(root->mlx, 0xffeead));



	fd = open(BUTTON_STRUCT_PATH, O_RDONLY);
	read(fd, root->men.button, sizeof(t_button) * BUTTON_MAX);

	int tmp_ox = root->men.button[0].o_x;
	int tmp_oy = root->men.button[0].o_y;

	draw_button2((root->men.button)[0], m, 0);

	root->men.button[0].o_x = tmp_ox;
	root->men.button[0].o_y = tmp_oy - 102;
	draw_button2((root->men.button)[0], m, 2);

	root->men.button[0].o_x = tmp_ox - 102;
	root->men.button[0].o_y = tmp_oy;
	draw_button2((root->men.button)[0], m, 0);

	root->men.button[0].o_x = tmp_ox + 102;
	root->men.button[0].o_y = tmp_oy;
	draw_button2((root->men.button)[0], m, 0);
	// show_image(root->men.button[0].view[2], root->men.button[0].x, root->men.button[0].y);


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
