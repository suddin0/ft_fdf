#include "main.h"

void  draw_line(t_map *map, t_point o, t_point n, int color)
{
	unsigned steps;
	double	x;
	double	y;
	double Xincrement;
	double Yincrement;

	o.x = map->origine_x + (map->step * o.x);
	o.y = map->origine_y + (map->step * o.y);
	n.x = map->origine_x + (map->step * n.x);
	n.y = map->origine_y + (map->step * n.y);


	 printf("DRAW LINE OX[%lf] OY[%lf] -- NX[%lf] NY[%lf]\n", o.x, o.y, n.x, n.y);

	steps = ((n.x - o.x) > (n.y - o.y)) ? fabs(n.x - o.x) : fabs(n.y - o.y);
	x = o.x;
	y = o.y;

	Xincrement = (n.x - o.x) / (double) steps;
	Yincrement = (n.y - o.y) / (double) steps;
	while(steps)
	{
		x += Xincrement;
		y += Yincrement;
		put_color(map->img, x, y, color); // Normal view
		steps--;
	}
}
