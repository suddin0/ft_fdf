#include "main.h"

int is_button_area(t_button *b, int x, int y)
{
	int i;

	i = 0;
	while(i < BUTTON_MAX)
	{
		if(x > (b[i]).o_x && x < (b[i]).o_x + (b[i]).x && y > (b[i]).o_y && y < (b[i]).o_y + (b[i]).y)
			return (i);
		i++;
	}
	return(-1);

}

int is_list_area(t_map_list list, int x, int y)
{
	int i;
	int j;

	i = 1; // it is multiplied to get the size, if mult by 0 then the result is 0
	j = 0;
	while(j < list.total_map)
	{
		if(x > (list.o_x *  i) && x < (list.o_x) + MENU_X && y > (list.o_y * i) && y < (list.o_y) + (list.height * i))
			return (i - 1);
		i++;
		j++;
	}
	return (-1);
}
