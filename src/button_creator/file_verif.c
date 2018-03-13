#include "button_creator.h"

// argc
// argv
// file


void size_check(char *name, int a, int  b)
{
	if ((a * b) > BUTTON_SIZE)
	{
		ft_printf("[-] Error size: %s is too larg to hold in stake %dmb, max size %dmb\n", name, a * b, BUTTON_SIZE);
		exit(-1);
	}
}


int file_check(int argc, char ***argv)
{
	int i;

	i = 0;
	while (i != argc - 1)
	{
		// printf("CAME IIN FILE_CHECK [%d] [%s] - [%s] - [%s]\n", i, argv[i][0], argv[i][1], argv[i][2]);
		if(is_file(argv[i][0]) <= 0 || is_file(argv[i][1]) <= 0 || is_file(argv[i][2]) <= 0)
			return (i + 1);
		i++;
	}
	return (0);
}


int file_verif(int argc, char **argv, char ****file)
{
	int error;

	error = 0;
	printf("GETTING IN\n");

	if (argc < 2)
	{
		ft_printf("[!] No file was given as arguments\n");
		return (-1);
	}
	if((argc - 1) > BUTTON_MAX)
	{
		ft_printf("[-] Error MAX_BUTTON: Too much muttons, maximum limit is %d", BUTTON_MAX);
		return(-1);
	}
	if (create_name(file, argc, argv) != 1)
	{
		ft_printf("[-] Error setting file name in create_name(...) function");
		return (-1);
	}
	if((error = file_check(argc, *file)) != 0)
	{
		ft_printf("[-] Error files: %s\n", argv[error]);
		free_file(*file, argc);
		return (-1);
	}
	printf("GETTING OUT\n");
	return (0);
}
