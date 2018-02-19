#include "main.h"


void print_map(t_map *map, int space)
{
	int l;
	int p;
	int num_sz;


	l = 0;
	p = 0;
	num_sz = 0;
	while (l < map->lines)
	{
		while (p < map->line_sz[l])
		{
			num_sz = ft_intlen(map->map[l][p]);
			if ((space - num_sz) > 0)
				ft_putnchar(' ', space - num_sz);
			ft_putnbr(map->map[l][p]);
			p++;
		}
		ft_putchar('\n');
		p = 0;
		l++;
	}
}
