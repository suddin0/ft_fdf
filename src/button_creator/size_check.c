#include "button_creator.h"

void size_check(char *name, int a, int  b, int size)
{
	if (((a * b) * 4) > size)
	{
		ft_printf("[-] Error size: %s is too larg to hold in stake %dmb, max size %dmb\n", name, a * b, size);
		exit(-1);
	}
}
