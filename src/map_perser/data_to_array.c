#include "main.h"

t_point  **data_to_array(t_map *map)
{
	t_m_data *data;
	int i;
	float x;
	float y;

	if(!map)
		return (NULL);
	data = map->data;
	map->line_sz = (long *) malloc(sizeof(long) * map->lines);
	map->map = (t_point **) malloc(sizeof(t_point *) * (map->lines + 1));
	ft_memset(map->map, 0, map->lines + 1);
	i = 0;
	x = 0;
	y = 0;
	while(data && data->next)
		data = data->next;
	while(data)
	{
		i = 0;
		map->line_sz[data->col] = data->row;
		map->map[data->col] = (t_point *) malloc(sizeof(t_point) * data->row);
		while (i != data->row)
		{
			(map->map)[data->col][i].x = x;
			(map->map)[data->col][i].y = y;
			(map->map)[data->col][i].z = ((data->data)[i] == 0) ? 0.10 : (data->data)[i]; // The 0.91 determines the height (z) step. It's a controle mecanisme
			i++;
			x ++;
		}
		y++;
		x = 0;
		data = data->prev;
	}
	return (map->map);
}
