#include "button_creator.h"


void write_struct(t_button b[], char *path)
{
	int fd;

	fd = open(path, O_WRONLY | O_CREAT, 0644);
	write(fd, b, sizeof(t_button) * BUTTON_MAX);
	close(fd);
}

void write_struct_font(t_char b[], char *path)
{
	int fd;

	fd = open(path, O_WRONLY | O_CREAT, 0644);
	write(fd, b, sizeof(t_char) * FCHAR_MAX);
	close(fd);
}
// abwzp
