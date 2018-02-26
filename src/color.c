#include "main.h"


void put_color(t_image *img, int x, int y, int col)
{
	x = (x >= img->x || x < 0) ? 0 : x;
	y = (y >= img->y || y < 0) ? 0 : y;
	//if(x < img->x && x > 0 && y < img->y && (x + (y * img->x)) < img->x * img->y)
	if(x > 0 && y > 0 && (x + (y * img->x)) < img->x * img->y)
		((int *) img->img)[x + (y * img->x)]  = col;
}



void set_color(char *img, unsigned int len, int col)
{
	if (len > 8)
		while (len > 8)
		{
			((int *) img)[len--] = col;
			((int *) img)[len--] = col;
			((int *) img)[len--] = col;
			((int *) img)[len--] = col;
			((int *) img)[len--] = col;
			((int *) img)[len--] = col;
			((int *) img)[len--] = col;
			((int *) img)[len--] = col;
		}
	while (len > 0)
		((int *) img)[len--] =  col;
}
