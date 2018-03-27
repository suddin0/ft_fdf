#include "main.h"

inline static void	show_data(t_root *root, t_map *map)
{
	int color;

	color = 0xc0c5ce60;
	CLEAR(root->foot);
	printf_text(root, &(root->foot), "%C%f%x%yX: %d  Y: %d", 0xc0c5ce60,\
			root->font_11, 20, 5, (int) map->origine_x, (int) map->origine_y);
	if (map->step <= 0)
		color = COL_ERROR;
	printf_text(root, &(root->foot), "%C%f%x%yZoom: %C%d", 0xc0c5ce60, \
			root->font_11, root->foot.x - 130, 5, color, map->step);
	VIEW(root->mlx, root->win, root->foot.img_ptr, root->foot.o_x,\
			root->foot.o_y);
}

void				draw_map(t_root *root, void *img_ptr, t_map *map)
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
		p = 0;
		while (p  < map->line_sz[l])
		{
			if (l + 1 < map->lines && p < map->line_sz[l + 1])
				draw_line(map, m[l][p], m[l + 1][p], COLOR(img_ptr, MAP_COLOR));
			if (p + 1 <  map->line_sz[l])
				draw_line(map, m[l][p], m[l][p + 1], COLOR(img_ptr, MAP_COLOR));
			p += 1;
		}
		l++;
	}
	show_data(root, map);
}
