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

void put_color2(t_image *img, int x, int y, char col)
{
	x = (x >= img->x || x < 0) ? 0 : x;
	y = (y >= img->y || y < 0) ? 0 : y;
	//if(x < img->x && x > 0 && y < img->y && (x + (y * img->x)) < img->x * img->y)
	if(x > 0 && y > 0 && (x + (y * img->x)) < img->x * img->y)
		((char *) img->img)[x + (y * img->x)]  = col;
}


// void put_color(t_image *img, int x, int y, int col)
// {
// 	x = (x >= img->x || x < 0) ? 0 : x;
// 	y = (y >= img->y || y < 0) ? 0 : y;
// 	//if(x < img->x && x > 0 && y < img->y && (x + (y * img->x)) < img->x * img->y)
// 	if(x > 0 && y > 0 && (x + (y * img->x)) < img->x * img->y)
// 		((int *) img->img)[x + (y * img->x)]  = col;
// }

void draw_button2(t_button button, t_image *img)
{
	int i = button.o_x;
	int j = button.o_y;
	int k = 0; // char itarator

	ft_printf("BUTTON[%s] O_X[%d] O_Y[%d]  button.x[%d] - button.y[%d]\n", button.name, i, j, button.x, button.y);

	while(j != button.o_y + button.y)
	{
		i = button.o_x;
		while (i++ != (button.o_x + button.x))
		{
			printf("Came here BUTTON2 i[%d] j[%d] k[%d] btn[%d]\n", i, j, k, button.view[2][k]);
			put_color2(img, i, j, (button.view[1])[k++]);
		}
		j++;
	}
	printf("EXiTING BUTTON 2\n");
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

	// fd = open(BUTTON_STRUCT_PATH, O_RDONLY);
	// read(fd, root->men.button, sizeof(t_button) * BUTTON_MAX);

	// show_image(root->men.button[0].view[2], root->men.button[0].x, root->men.button[0].y);


	// draw_button2((root->men.button)[0], m);
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
