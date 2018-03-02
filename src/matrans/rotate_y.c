#include "main.h"

void rotate_y(t_point *a, double v)
{
	double x;
	double y;
	double z;

	x = a->x;
	y = a->y;
	z = a->z;

	printf("++ rotate_y DEG[%lf]\n", v);
	// printf("++ rotate_x BEFOR X[%lf] Y[%lf] Z[%lf]\n", x, y, z);


	a->x = (x *  cos(v))  + (y * 0) + (z *  sin(v));
	a->y = (x *       0)  + (y * 1) + (z *       0);
	a->z = (x * -sin(v))  + (y * 0) + (z *  cos(v));
	// printf("-- rotate_x AFTER X[%lf] Y[%lf] Z[%lf]\n", a->x, a->y, a->z);

}
