#include "main.h"

void draw_map(void *img_ptr, t_map *map)
{
	int l;
	int p;
	double step;
	t_point **m;

	l = 0;
	p = 0;
	m = map->map;
	while (l < map->lines)
	{
		p = 0;
		while (p  < map->line_sz[l])
		{
			if (l + 1 < map->lines && p < map->line_sz[l + 1])
				draw_line(map, m[l][p], m[l + 1][p], COLOR(img_ptr, 0xe0e0bd));
			if (p + 1 <  map->line_sz[l])
				draw_line(map, m[l][p], m[l][p + 1], COLOR(img_ptr, 0xe0e0bd));
			p += 1;
		}
		l++;
	}
}
