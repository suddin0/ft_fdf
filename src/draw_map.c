#include "main.h"

void draw_map(void *img_ptr, t_map *map)
// void draw_map(void *img_ptr, t_map *map, t_image *img)
{
	int l;
	int p;
	double step;
	t_point **m;
	t_point a;
	t_point b;

	l = 0;
	p = 0;
	m = map->map;
	while (l < map->lines)
	{
		// printf("CAME HERE draw_map\n");
		p = 0;
		while (p  < map->line_sz[l])
		{
			// printf("CAME HERE draw_map WHILE p < map->line_sz\n");
			if (l + 1 < map->lines && p < map->line_sz[l + 1])
				// draw_line(img, m[l][p], m[l + 1][p], COLOR(img_ptr, 0x99a1a8));
				// draw_line(img, m[l][p], m[l + 1][p], COLOR(img_ptr, 0xDAEDCF));
				// draw_line(img, m[l][p], m[l + 1][p], COLOR(img_ptr, 0xff8000));
				draw_line(map, m[l][p], m[l + 1][p], COLOR(img_ptr, 0xe0e0bd)); // --

				// draw_dot(img, m[l][p], m[l + 1][p], COLOR(img_ptr, 0xe0e0bd));

			if (p + 1 <  map->line_sz[l])
				// draw_line(img, m[l][p], m[l][p + 1], COLOR(img_ptr, 0xff8000));
				// draw_line(img, m[l][p], m[l][p + 1], COLOR(img_ptr, 0xDAEDCF));
				draw_line(map, m[l][p], m[l][p + 1], COLOR(img_ptr, 0xe0e0bd)); //--

				// draw_dot(img, m[l][p], m[l][p + 1], COLOR(img_ptr, 0xe0e0bd));

			p += 1;
		}
		l++;
	}
}
