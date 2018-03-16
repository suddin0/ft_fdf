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
