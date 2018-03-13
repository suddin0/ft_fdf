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


	 // printf("DRAW LINE OX[%lf] OY[%lf] -- NX[%lf] NY[%lf]\n", o.x, o.y, n.x, n.y);

	steps = ((n.x - o.x) > (n.y - o.y)) ? fabs(n.x - o.x) : fabs(n.y - o.y);
	x = o.x;
	y = o.y;

	Xincrement = (n.x - o.x) / (double) steps;
	Yincrement = (n.y - o.y) / (double) steps;
	while(steps)
	{
		x += Xincrement;
		y += Yincrement;
		put_color(map->img, (int) (x), (int)(y), color); // Normal view
		steps--;
	}
}

// void bresenham_line(t_section *s, t_uint o.x, t_uint o.y, t_uint n.x, t_uint n.y, t_color colour )

//
// void  draw_line(t_map *map, t_point o, t_point n, int color)
// {
// 	int dx;
//   	int dy;
//   	int y;
//   	int eps;
// 	int x;
//
// 		o.x = map->origine_x + (map->step * o.x);
// 		o.y = map->origine_y + (map->step * o.y);
// 		n.x = map->origine_x + (map->step * n.x);
// 		n.y = map->origine_y + (map->step * n.y);
//
// 	dx  = (int)(n.x) - (int)(o.x);
// 	dy  = (int)(n.y) - (int)(o.y);
// 	y   = (int)(o.y);
// 	eps = 0;
// 	x = o.x;
//
//   //for ( int x = o.x; x <= n.x; x++ )
//   while(x <= n.x)
//   {
// 	// section_put_color( s, x, y, colour);
// 	put_color(map->img, x, y, color);
// 	eps += dy;
// 	if ( (eps << 1) >= dx )
// 	  y++;  eps -= dx;
// 	x++;
//   }
// }


//
// void  draw_line(t_map *map, t_point o, t_point n, int color)
// // void line(int n.x, int o.y, int n.x, int n.y)
// {
//
//   int dx = abs(n.x-n.x), sx = n.x < n.x ? 1 : -1;
//   int dy = abs(n.y-o.y), sy = o.y<n.y ? 1 : -1;
//   int err = (dx>dy ? dx : -dy)/2, e2;
//
//   o.x = map->origine_x + (map->step * o.x);
//   o.y = map->origine_y + (map->step * o.y);
//   n.x = map->origine_x + (map->step * n.x);
//   n.y = map->origine_y + (map->step * n.y);
//
//   for(;;)
//   {
//     // setPixel(n.x,o.y);
// 	put_color(map->img, o.x, o.y, color);
//     if (n.x==n.x && o.y==n.y)
// 		break;
//     e2 = err;
//     if (e2 >-dx)
// 	{
// 		err -= dy;
// 		n.x += sx;
// 	}
//     if (e2 < dy)
// 	{
// 		err += dx;
// 		o.y += sy;
// 	}
//   }
// }
