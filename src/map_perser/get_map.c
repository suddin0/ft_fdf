#include "main.h"

static int is_space(char c)
{
	// 0x20	Space
	// 0x9	Tab
	if(c == 0x20 || c == 0x9)
		return (1);
	return (0);
}

static int is_num_hex(char c)
{
	// 0x20	Space
	// 0x9	Tab
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || \
		(c >= 'a' && c <= 'f') || (c == 'X') || (c == 'x'))
		return (1);
	return (0);
}





static long line_pnt(char *str, long line)
{
	long i;

	i = line;
	if(!str)
		return (0);
	while(str[i] && str[i] != 0xA) // 0xA = line feed (new line)
		i++;
		// printf("CAME HERE LINE_PNT i[%d]\n", i);
	if (i == line || str[i] == 0)
		return (0);	// if new line wasn't found and i was not changed because
		 			// there zas nothing to read, then we have reached the end of
					// file
	return (i);
}


t_map *get_map(char *name, t_image *img)
{
	t_map	 *map;
	t_m_data *data;
	t_m_data *data_prev;


	char	*mp;	// data from the map file
	int 	fd;		// file descitpor of the map
	int 	rd;		// return value of map;
	long 	n_line;	// contain the new line pointer position
	long 	o_line;	// contain the old line pointer position

	rd 			= 0;
	n_line 		= 0;
	o_line 		= 0;
	mp = NULL;
	map = NULL;

	if (is_file(name) == 1)
	{
		map = map_malloc(img);	// main structure
		map->file_sz = file_size(name);	// get
		if(!(mp = ft_strnew(map->file_sz)))
		{
			ft_printf("[-] Error: allocating %d bytes\n", map->file_sz);
			return (NULL);
		}
	}
	else
	{
		if(is_dir(name) == 1)
			ft_printf("[-] Error: %s is a directory and not a file\n", name);
		else
			ft_printf("[-] Error: not a valid file\n");
		exit(-1);
	}

	if ((fd = open(name, O_RDONLY)) == -1)
	{
		ft_printf("[-] Error: opening file: %s\n", name);
		free(map);
		return (NULL);
	}
	if ((rd = read(fd, mp, map->file_sz)) < map->file_sz)
	{
		free(map);
		ft_printf("[-] Error: reading. Read %d/%d\n", rd , map->file_sz);
		return (NULL);
	}
	map->origine_x = ORIGINE_X;
	map->origine_y = ORIGINE_Y;
	map->step = STEP;
	while((n_line = line_pnt(mp, o_line)) > 0)
	{
		// printf("CAME HERE WHILE GET_MAP\n");
		data = (t_m_data *) malloc(sizeof(t_m_data));
		data->next = NULL;
		data->prev = NULL;
		if((data->row = count_num(mp, o_line, n_line)) <= 0)
		{
			ft_printf("[-] Error: Invalid map (line %d)\n", map->lines + 1);
			exit(-1);
		}
		data->col = map->lines;
		data->data = get_num(mp, o_line, n_line, data->row);
		data->next = map->data; // data = 4 -- m->data = 3
		data_prev  = data;      // data_prev = 4
		map->data = data;       // m->data = 4  m->data->next = 3
		if(data->next) // set the previous
			data->next->prev = data_prev; // data->next->prev = 4
		while(data)
			data = data->next;
		map->lines++;
		o_line = n_line + 1;
	}
	close(fd);
	if(map->lines <= 0)
	{
		printf("[-] Error: map contains %d lines\n", map->lines);
		exit(-1);
	}
	data_to_array(map);
	free(mp);
	return (map);
}
