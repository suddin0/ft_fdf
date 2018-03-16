#include "main.h"

inline static int is_space(char c)
{
	if(c == 0x20 || c == 0x9)
		return (1);
	return (0);
}

long *get_num(char *str, long o_line, int n_line, int dig)
{
	int i;
	int neg; // if number is negatif this flag will be on (on = 1)
	long *num;

	i = 0;
	neg = 0;
	num = (long *) malloc(sizeof(long) * (dig + 1)); // maybe the +1 is not necessary ...
	while(str[o_line] && (o_line < n_line))
	{
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
