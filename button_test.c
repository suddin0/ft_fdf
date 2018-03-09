#include "main.h"



// typedef struct s_button
// {
// 	char	type;
// 	int		id;
// 	char	stat;
// 	char	view[3][BUTTON_SIZE];
// 	char	name[100];
// 	int 	x;
// 	int 	y;
// 	int		o_x;
// 	int		o_y;
// 	void 	*value;
// 	void 	(*f)(void *root);
// } t_button;
//
// type
// id
// stat
// view[3][BUTTON_SIZE]
// name[100]
// x
// y
// o_x
// o_y
// *value
// (*f)(void *root)

int main(void)
{
	t_button b[BUTTON_MAX];
	int fd = -1;

	fd = open(BUTTON_STRUCT_PATH, O_RDONLY);
	read(fd, b, sizeof(t_button) * BUTTON_MAX);

	printf("First button type 	[%d]\n", b[0].type);
	printf("First button id 	[%d]\n", b[0].id);
	printf("First button stat 	[%d]\n", b[0].stat);
	// printf("First button view[3][BUTTON_SIZE] [%s]\n", b[0].view[3][BUTTON_SIZE]);
	printf("First button name	[%s]\n", b[0].name);
	printf("First button x 		[%d]\n", b[0].x);
	printf("First button y 		[%d]\n", b[0].y);
	printf("First button o_x 	[%d]\n", b[0].o_x);
	printf("First button o_y 	[%d]\n", b[0].o_y);
}
