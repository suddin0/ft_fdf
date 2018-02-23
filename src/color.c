#include "main.h"

t_color	  get_col(int r, int g, int b, int a)
{
	t_color	col;

	col.b = b;
	col.g = g;
	col.r = r;
	col.a = a;
	return (col);
}


void put_color(t_img *img, int x, int y, t_color col)
{
	x = (x >= img->x || x < 0) ? 0 : x;
	y = (y >= img->y || y < 0) ? 0 : y;
	//if(x < img->x && x > 0 && y < img->y && (x + (y * img->x)) < img->x * img->y)
	if(x > 0 && y > 0 && (x + (y * img->x)) < img->x * img->y)
		((t_color *) img->img)[x + (y * img->x)]  = col;
}


void set_color(char *img, unsigned int len, t_color col)
{
	int i;

	i = 0;
	printf("LEN [%d]\n", len);
	while (i != len)
		((t_color *) img)[i++] =  col;
}
