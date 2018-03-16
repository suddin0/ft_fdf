#include "button_creator.h"


void name_copy(char *dest, char *src)
{
	int len;
	int start;
	int end;
	int i;

	if(!dest || !src)
		return;
	start = 0;
	i = 0;
	len = ft_strlen(src);
	while(len-- && src[len] != '/');
	start = (len == 0) ? len : len + 1;
	end =  ft_strlen(&(src[start])) - 6;
	while (i != end && src[start])
		dest[i++] = src[start++];
	dest[i] = 0;
}

int name_to_num(char *name)
{
	char tmp[100];

	name_copy(tmp, name);
	return (atoi(tmp));
}
