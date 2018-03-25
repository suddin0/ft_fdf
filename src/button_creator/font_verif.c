#include "button_creator.h"


int font_check(int argc, char **argv)
{
	int i;

	i = 1;
	while (i != argc)
	{
		if(is_file(argv[i]) <= 0)
			return (i);
		i++;
	}
	return (0);
}


int font_verif(int argc, char **argv)
{
	int error;

	error = 0;
	if (argc < 2)
	{
		ft_printf("[!] No file was given as arguments\n");
		return (-1);
	}
	if((argc - 1) > FCHAR_MAX)
	{
		ft_printf("[-] Error MAX_BUTTON: Too much muttons, maximum limit is %d", BUTTON_MAX);
		return(-1);
	}
	if((error = font_check(argc, argv)) != 0)
	{
		ft_printf("[-] Error files: %s\n", argv[error]);
		return (-1);
	}
	return (0);
}
