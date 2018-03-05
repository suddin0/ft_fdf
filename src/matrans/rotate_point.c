#include "main.h"


void rotate_x(t_point *a, double v)
{
	double x;
	double y;
	double z;

	x = a->x;
	y = a->y;
	z = a->z;
	// printf("++ rotate_x BEFOR X[%lf] Y[%lf] Z[%lf]\n", x, y, z);
	// printf("++ rotate_x DEG[%lf]\n", v);

	a->x = (x * 1)  + (y *       0) + (z *       0);
	a->y = (x * 0)  + (y *  cos(v)) + (z * -sin(v));
	a->z = (x * 0)  + (y *  sin(v)) + (z *  cos(v));
	// printf("-- rotate_x AFTER X[%lf] Y[%lf] Z[%lf]\n", a->x, a->y, a->z);
}

void rotate_y(t_point *a, double v)
{
	double x;
	double y;
	double z;

	x = a->x;
	y = a->y;
	z = a->z;

	// printf("++ rotate_y DEG[%lf]\n", v);
	// printf("++ rotate_x BEFOR X[%lf] Y[%lf] Z[%lf]\n", x, y, z);

	a->x = (x *  cos(v))  + (y * 0) + (z *  sin(v));
	a->y = (x *       0)  + (y * 1) + (z *       0);
	a->z = (x * -sin(v))  + (y * 0) + (z *  cos(v));
}

void rotate_z(t_point *a, double v)
{
	double x;
	double y;
	double z;

	x = a->x;
	y = a->y;
	z = a->z;
	// printf("++ rotate_x BEFOR X[%lf] Y[%lf] Z[%lf]\n", x, y, z);
	// printf("++ rotate_z DEG[%lf]\n", v);

	a->x = (x * cos(v))  + (y * -sin(v)) + (z * 0);
	a->y = (x * sin(v))  + (y *  cos(v)) + (z * 0);
	a->z = (x *      0)  + (y *       0) + (z * 1);
}
