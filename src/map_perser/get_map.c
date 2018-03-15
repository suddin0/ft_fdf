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
	// printf("CAME HERE LINE_PNT\n");
	return (i);
}



static int count_num(char *str, long o_line, long n_line)
{
	int i;
	int signe;
	int count;

	i = 0;
	signe = 0;
	count = 0;
	while (str[o_line] && (o_line != n_line))
	{
		// printf("CAME INSIDE THE EHILE STR[%d][%d]\n", o_line, str[o_line]);
		//printf("str[%d][%c] \n",str[o_line], str[o_line]  );
		if (is_space(str[o_line]) && !signe)
			i = 0;
		else if (ft_isdigit(str[o_line]))
		{
			if (i == 0)
				count++;
			i = 1;
			signe = 0;
		}
		else if(((str[o_line] == '+') || (str[o_line] == '-')) && ((o_line + 1) != n_line))
			signe = 1;
		else if ((str[o_line] == ',') && ((o_line + 1) < n_line))
		{
			o_line++;
			while(str[o_line] && is_num_hex(str[o_line]) && o_line < n_line)
				o_line++;
			continue;
		}
		else
		{
			printf("[-] Error: unsupported value at %ld\n", o_line);
			return (-1);
		}
		o_line++;
	}
	return (count);
}





//
// static int count_num(char *str, long o_line, long n_line)
// {
// 	int i;
// 	int signe;
// 	int count;
//
// 	i = 0;
// 	signe = 0;
// 	count = 0;
// 	while (str[o_line] && (o_line != n_line))
// 	{
// 		//printf("str[%d][%c] \n",str[o_line], str[o_line]  );
// 		if (is_space(str[o_line]) && !signe)
// 			i = 0;
// 		else if (is_num_hex(str[o_line]))
// 		{
// 			if (i == 0)
// 				count++;
// 			i = 1;
// 			signe = 0;
// 		}
// 		else if(((str[o_line] == '+') || (str[o_line] == '-') || \
// 		 		(str[o_line] == ',')) && ((o_line + 1) != n_line))
// 			signe = 1;
// 		//else if(str[o_line])
// 		//	printf("str[%ld][%d][%c]  n_line[%ld] \n", o_line, str[o_line], str[o_line], n_line);
// 		else
// 		{
// 			printf("[-] Error: unsupported value at %d\n", o_line);
// 			return (-1);
// 		}
// 		o_line++;
// 	}
// 	return (count);
// }



static long *get_num(char *str, long o_line, int n_line, int dig)
{
	int i;
	int neg; // if number is negatif this flag will be on (on = 1)
	long *num;

	i = 0;
	neg = 0;
	num = (long *) malloc(sizeof(long) * (dig + 1)); // maybe the +1 is not necessary ...

	while(str[o_line] && (o_line < n_line))
	{
		// printf("o_line[%3d] - n_line[%3d] dig[%3d]\n", o_line, n_line, dig);
		num[i] = 0;
		while(is_space(str[o_line]) &&( o_line != n_line))
			o_line += 1;
		if(str[o_line] == ',')
		{
			while(str[o_line] && !is_space(str[o_line]) && o_line < n_line)
				o_line++;
			continue;
		}
		if((str[o_line] == '-') || (str[o_line] == '+'))
		{
			if(((o_line + 1) == n_line))
			{
				printf("[-] Error: get_number: bad map at [%ld][%c]\n", o_line, str[o_line]);
				exit(-1);
			}
			if(str[o_line] == '-')
				neg = 1;
			o_line++;
		}
		while(str[o_line] && ft_isdigit(str[o_line]) && o_line < n_line)
			num[i] = (num[i] * 10L) + (str[o_line++] - 48);
		if(neg)
			num[i] *= -1;
		i++;
		neg = 0;
	}
	return num;
}


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


t_map *get_map(char *name, t_image *img)
{
	t_map *map;
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
			ft_printf("[-] Error : %s is a directory and not a file\n", name);
		else
			ft_printf("[-] Error : not a valid file\n");
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

	printf("map->origine_x [%lf]\n", map->origine_x);
	printf("map->origine_y [%lf]\n", map->origine_y);
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
