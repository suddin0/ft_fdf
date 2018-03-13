#include "main.h"

void draw_button(t_button button, t_image *img, int stat)
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
			// printf("x[%3d] - y[%3d] b.x[%3d] b,y[%3d]\n", x + 0, y, button.x, button.y);
			// printf("x[%3d] - y[%3d] b.x[%3d] b,y[%3d]\n", x + 1, y, button.x, button.y);
			// printf("x[%3d] - y[%3d] b.x[%3d] b,y[%3d]\n", x + 2, y, button.x, button.y);
			// printf("x[%3d] - y[%3d] b.x[%3d] b,y[%3d]\n", x + 3, y, button.x, button.y);
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
