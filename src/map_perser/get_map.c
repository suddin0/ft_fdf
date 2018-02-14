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
	while(str[i] && str[i] != 0xA) // 0xA = line feed (new line)
		i++;
	if (i == line)
		return (0);	// if new line wasn't found and i was not changed because
		 			// there zas nothing to read, then we have reached the end of
					// file
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
		// printf("str[%d][%c] \n",str[o_line], str[o_line]  ); 
		if (is_space(str[o_line]) && !signe)
			i = 0;
		else if (is_num_hex(str[o_line]))
		{
			if (i == 0)
				count++;
			i = 1;
			signe = 0;
		}
		else if(((str[o_line] == '+') || (str[o_line] == '-') || \
		 		(str[o_line] == ',')) && ((o_line + 1) != n_line))
			signe = 1;
		else if(str[o_line])
			printf("str[%ld][%d][%c]  n_line[%ld] \n", o_line, str[o_line], str[o_line], n_line);
		else
			return (-1);
		o_line++;
	}
	return (count);
}



static long *get_num(char *str, long o_line, int n_line, int dig)
{
	int i;
	int neg; // if number is negatif this flag will be on (on = 1)
	long *num;

	i = 0;
	neg = 0;

	num = (long *) malloc(sizeof(long) * dig + 1); // maybe the +1 is not necessary ...

	while(str[o_line] && (o_line < n_line))
	{
		num[i] = 0;
		//pass all the spaces
		while(is_space(str[o_line]) &&( o_line != n_line))
			o_line += 1;
		// ignore the color. If later want to get the color modify here
		if(str[o_line] == ',')
			while(!is_space(str[o_line]))
				o_line++;
		// small verifiacation of signe and conversion
		if((str[o_line] == '-') || (str[o_line] == '+'))
		{
			if(((o_line + 1) == n_line))
				printf("[-] Error: get_number: bad map \n");
			if(str[o_line] == '-')
				neg = 1;
			o_line++;
		}
		// recover the number
		while(ft_isdigit(str[o_line]))
		{
			num[i] = (num[i] * 10) + (str[o_line++] - 48);
			// o_line++;
		}
		if(neg)
			num[i] *= -1;
		i++;
		neg = 0;
	}
	return num;
}

long **data_to_array(T_MAP *map)
{
	T_M_DATA *data;

	data = map->data;
	map->line_sz = (long *) malloc(sizeof(long) * map->lines);
	map->map = (long **) malloc(sizeof(long *) * map->lines);

	while(data)
	{
		map->line_sz[data->col] = data->row;
		map->map[data->col] = data->data;
		data = data->next;
	}

	return (map->map);
}

T_MAP *get_map(char *name)
{
	T_MAP *map;
	T_M_DATA *data;

	char	*mp;	// data from the map file
	int 	fd;		// file descitpor of the map
	int 	rd;		// return value of map;
	long 	n_line;	// contain the new line pointer position
	long 	o_line;	// contain the old line pointer position

	rd 			= 0;
	n_line 		= 0;
	o_line 		= 0;

	// check befor preparing the file opening
	if (is_file(name) == 1)
	{
		map = (T_MAP *) malloc(sizeof(T_MAP));	// main structure
		map->file_sz = file_size(name);	// get
		mp = ft_strnew(map->file_sz);
	}
	else
	{
		printf("[-] Error : not a valid file type\n");
		return (NULL);
	}

	if ((fd = open(name, O_RDONLY)) == -1)
	{
		printf("[-] Error: opening file: %s\n", name);
		return (NULL);
	}
	if ((rd = read(fd, mp, map->file_sz)) < map->file_sz)
	{
		printf("[-] Error: reading. Read %d/%d\n", rd , map->file_sz);
		return (NULL);
	}

	while((n_line = line_pnt(mp, o_line)) > 0) // Get the newline (`\n`) pointer
	{
		data = (T_M_DATA *) malloc(sizeof(T_M_DATA));
		if((data->row = count_num(mp, o_line, n_line)) <= 0)
			printf("[-] Error: Invalid map (line %d)\n", map->lines);
		// printf("DATA->row [%d] \n", data->row); // This part needs ro be debugged as it mess with memory
		data->col = map->lines;
		data->data = get_num(mp, o_line, n_line, data->row);
		data->next = map->data;
		map->data = data;
		while(data)
			data = data->next;
		map->lines++; // conts the number of lines red
		o_line = n_line + 1; // the +1 is to go to the next position of `\n`
	}
	printf("NAME[%s] - IS_FILE RET[%d]\n", name, is_file(name));
	data_to_array(map);
	free(mp);
	return (map);



}
