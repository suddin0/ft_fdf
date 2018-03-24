#include "main.h"

void free_list(t_map_list *list)
{
	int i;

	i = 0;
	while (i < list->total_map)
		free(list->map_name[i++]);
	free(list->map_name);
	list->map_name = NULL;
}
