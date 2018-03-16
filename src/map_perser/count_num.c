#include "main.h"

inline static int is_space(char c)
{
	// 0x20	Space
	// 0x9	Tab
	if(c == 0x20 || c == 0x9)
		return (1);
	return (0);
}

inline static int is_num_hex(char c)
{
	// 0x20	Space
	// 0x9	Tab
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || \
		(c >= 'a' && c <= 'f') || (c == 'X') || (c == 'x'))
		return (1);
	return (0);
}

int count_num(char *str, long o_line, long n_line)
{
	int i;
	int signe;
	int count;

	i = 0;
	signe = 0;
	count = 0;
	while (str[o_line] && (o_line != n_line))
	{
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
