#include "main.h"

static void free_data(t_m_data *data)
{
	t_m_data *tmp;

	tmp = data;
	while(tmp)
	{
		free(data->data);
		data = data->next;
		free(tmp);
		tmp = data;
	}
}
void free_map(t_map *map)
{
	t_map *tmp_map;

	tmp_map = map;
	if(!map)
		return ;
	while(tmp_map)
	{
		if (tmp_map->map)
			free(tmp_map->map);
		free(tmp_map->line_sz);
		if(tmp_map->data)
			free_data(tmp_map->data);
		map = map->next;
		free(tmp_map);
		tmp_map = NULL;
		tmp_map = map;
	}
}
