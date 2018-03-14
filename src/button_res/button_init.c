#include "main.h"


void show_button(t_root *root, t_image *m)
{
	draw_button((root->men.button)[0 ], m, (root->men.button)[0 ].stat);
	draw_button((root->men.button)[1 ], m, (root->men.button)[1 ].stat);
	draw_button((root->men.button)[2 ], m, (root->men.button)[2 ].stat);
	draw_button((root->men.button)[3 ], m, (root->men.button)[3 ].stat);
	// draw_button((root->men.button)[3 ], m, (root->men.button)[3 ].stat);
	draw_button((root->men.button)[4 ], m, (root->men.button)[4 ].stat);
	draw_button((root->men.button)[5 ], m, (root->men.button)[5 ].stat);
	draw_button((root->men.button)[6 ], m, (root->men.button)[6 ].stat);
	draw_button((root->men.button)[7 ], m, (root->men.button)[7 ].stat);
	draw_button((root->men.button)[8 ], m, (root->men.button)[8 ].stat);
	draw_button((root->men.button)[9 ], m, (root->men.button)[9 ].stat);
	draw_button((root->men.button)[10], m, (root->men.button)[10].stat);
	draw_button((root->men.button)[10], m, (root->men.button)[10].stat);
	draw_button((root->men.button)[11], m, (root->men.button)[11].stat);
	draw_button((root->men.button)[12], m, (root->men.button)[12].stat);
	draw_button((root->men.button)[13], m, (root->men.button)[13].stat);
}

void button_func_init(t_button *button)
{
	button[3 ].f = (void *) &b3;
	button[4 ].f = (void *) &b4;
	button[5 ].f = (void *) &b5;
	button[6 ].f = (void *) &b6;
	button[7 ].f = (void *) &b7;
	button[8 ].f = (void *) &b8;
	button[12].f = (void *) &b12;
	button[13].f = (void *) &b13;
}

void button_init(t_root *root, t_image *m)
{
	int fd;

	fd = 0;
	root->men.img = m;
	root->men.mvment = 0;
	// root->men.c_opt = 0;
	root->men.btn_hover = -1;
	root->men.btn_clicked = -1;
	if((fd = open(BUTTON_STRUCT_PATH, O_RDONLY)) < 0)
	{
		ft_printf("[-] Error: opening %s\n", BUTTON_STRUCT_PATH);
		perror("Details");
		exit(-1);
	}
	read(fd, root->men.button, sizeof(t_button) * BUTTON_MAX);
	close (fd);
	button_func_init(root->men.button);
	show_button(root, m);
}
