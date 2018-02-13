#include "main.c"

void  section_put_color(t_section *s, int x, int y, t_color color)
{
	  x = (x > s->width) ? 0 : x;
		y = (y > s->height) ? 0 : y;
		  if(x <= s->width && x > 0 && y <= s->height)
				  ((t_color *) s->img)[x + (y * s->width)]  = color;
}
