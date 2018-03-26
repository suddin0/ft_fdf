#include "main.h"





void draw_font(t_char chr, t_image *img, int o_x, int o_y, unsigned int col)
{
	int x;
	int y;
	int k;

	if (chr.x == 0 || chr.y == 0)
		return;
	x = o_x * 4;
	y = o_y;
	k = 0;

	// target = opacity * overlay + (1 - opacity) * background

	unsigned char A = COL_A(col);
	unsigned char R = COL_R(col);
	unsigned char G = COL_G(col);
	unsigned char B = COL_B(col);


	unsigned char BGA;
	unsigned char BGR;
	unsigned char BGG;
	unsigned char BGB;

	// double opacity = (double) ((double) (A * 100) / 255) * 0.01;
	double opacity;
	double o_opacity_r; // original opacity


	opacity = (double) ((double) (A * 100) / 255) * 0.01;
	while (y < o_y + chr.y)
	{
		x = o_x * 4;
		while (x < (o_x + chr.x) * 4)
		{
			// if(x > 0 && y > 0 && (x + (y * img->x * 4)) < (img->x * img->y) * 4)
			if((x > 0 && y > 0) && (x + (y * img->x)) < (img->x * img->y) && (x < (img->x * 4) &&  y * img->y))
			{
				if((unsigned char) (chr.data)[k + 0] != 2 || (unsigned char) (chr.data)[k + 1] != 2 || (unsigned char) (chr.data)[k + 2] != 2)
				{
					o_opacity_r =   (double) (((unsigned char) (chr.data)[k + 2] * 100) / 255); // original opacity

					o_opacity_r = o_opacity_r * 0.01; // original opacity

					o_opacity_r = opacity - o_opacity_r;
					o_opacity_r = (o_opacity_r > 0 && o_opacity_r < opacity) ? o_opacity_r : 0;

					BGA = (unsigned char) ((img->img)[x + 3 + (y * (img->x * 4))]);
					BGR = (unsigned char) ((img->img)[x + 2 + (y * (img->x * 4))]);
					BGG = (unsigned char) ((img->img)[x + 1 + (y * (img->x * 4))]);
					BGB = (unsigned char) ((img->img)[x + 0 + (y * (img->x * 4))]);

					// (img->img)[x + 3 + (y * (img->x * 4))]  = ((opacity - o_opacity_r) * A + (1 - (opacity - o_opacity_r)) * BGA);	// A
					(img->img)[x + 2 + (y * (img->x * 4))]  = ((opacity - o_opacity_r) * R + (1 - (opacity - o_opacity_r)) * BGR);	// R
					(img->img)[x + 1 + (y * (img->x * 4))]  = ((opacity - o_opacity_r) * G + (1 - (opacity - o_opacity_r)) * BGG);	// G
					(img->img)[x + 0 + (y * (img->x * 4))]  = ((opacity - o_opacity_r) * B + (1 - (opacity - o_opacity_r)) * BGB);	// B

					// /* Real Colors */
					// (img->img)[x + 3 + (y * (img->x * 4))]  = (chr.data)[k + 3];	// R
					// (img->img)[x + 2 + (y * (img->x * 4))]  = (chr.data)[k + 2];	// R
					// (img->img)[x + 1 + (y * (img->x * 4))]  = (chr.data)[k + 1];	// G
					// (img->img)[x + 0 + (y * (img->x * 4))]  = (chr.data)[k + 0];	// B
				} /* End of if all white if */
			}
			k += 4;
			x += 4;
		}
		y++;
	}
}
