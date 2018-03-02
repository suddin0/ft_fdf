#include "main.h"

void rotate_z(t_point *a, double v)
{
	double x;
	double y;
	double z;

	x = a->x;
	y = a->y;
	z = a->z;
	// printf("++ rotate_x BEFOR X[%lf] Y[%lf] Z[%lf]\n", x, y, z);
	printf("++ rotate_z DEG[%lf]\n", v);



	a->x = (x * cos(v))  + (y * -sin(v)) + (z * 0);
	a->y = (x * sin(v))  + (y *  cos(v)) + (z * 0);
	a->z = (x *      0)  + (y *       0) + (z * 1);
	// printf("-- rotate_x AFTER X[%lf] Y[%lf] Z[%lf]\n", a->x, a->y, a->z);
}
