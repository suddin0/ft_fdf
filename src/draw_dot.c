#include "main.h"

void  draw_dot(t_image *img, t_point o, t_point n, int color)
{
	unsigned steps;
	double	x;
	double	y;
	double Xincrement;
	double Yincrement;


	// o.x *= 20;
	// o.y *= 20;
	// n.x *= 20;
	// n.y *= 20;

	o.x /= (o.z);
	o.y /= (o.z);
	n.x /= (n.z);
	n.y /= (n.z);

	 printf("DRAW DOT OX[%lf] OY[%lf] -- NX[%lf] NY[%lf]\n", o.x, o.y, n.x, n.y);

	steps = ((n.x - o.x) > (n.y - o.y)) ? fabs(n.x - o.x) : fabs(n.y - o.y);
	x = o.x;
	y = o.y;

	Xincrement = (n.x - o.x) / (double) steps;
	Yincrement = (n.y - o.y) / (double) steps;
	put_color(img, x, y, color);

	x += (Xincrement * (steps / 2.5));
	y += (Yincrement * (steps / 2.5));

	put_color(img, x, y, color);

	x += (Xincrement * steps);
	y += (Yincrement * steps);


	put_color(img, x, y, color);
}
