#include "main.h"


t_map *map_malloc(t_image *img)
{
	t_map *map;

	map = NULL;
	map = (t_map *) malloc(sizeof(t_map));	// main structure
	map->name = NULL;
	map->path = NULL;
	map->img = img;
	map->map = NULL;
	map->line_sz = NULL;
	map->file_sz = 0;
	map->lines = 0;
	map->data = NULL;
	map->next = NULL;
	map->origine_x = 0.0f;
	map->origine_y = 0.0f;
	map->step = STEP;
	map->color = COLOR(img->img_ptr, 0xFF3399);
	return (map);
}
