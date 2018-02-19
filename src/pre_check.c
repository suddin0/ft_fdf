#include "main.h"


static inline int is_dot_fdf(char *str)
{
	int i;

	i = ft_strlen(str);
	if (ft_strcmp(&(str[ft_strlen(str) - 4]), ".fdf") == 0)
		return (1);
	else
		return (0);
}

int					pre_check(int argc, char **argv)
{
	if(argc < 2)
	{
		ft_putstr("[-] Error: Not enough argument\n");
		return (0);
	}
	else if(argc > 2)
	{
		ft_putstr("[-] Error: Tooo much arguments\n");
		return (0);
	}
	else if(ft_strlen(argv[1]) > NAME_MAX)
	{
		ft_putstr("[-] Error: File name Too long\n");
		return (0);
	}
	else if(is_dot_fdf(argv[1]) == 0)
	{
		ft_putstr("[-] Error: File do not have .fdf extention\n");
		return (0);
	}
	else
		return (1);
}
