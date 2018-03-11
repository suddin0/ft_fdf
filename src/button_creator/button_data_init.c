#include "button_creator.h"


// initiate button create data names
void init_bname(t_b_create_data *b)
{
	strcpy(((b[0 ]).name), "main");
	strcpy(((b[1 ]).name), "map");
	strcpy(((b[2 ]).name), "info");
	strcpy(((b[3 ]).name), "left");
	strcpy(((b[4 ]).name), "down");
	strcpy(((b[5 ]).name), "right");
	strcpy(((b[6 ]).name), "up");
	strcpy(((b[7 ]).name), "uzoom");
	strcpy(((b[8 ]).name), "zoom");
	strcpy(((b[9 ]).name), "default");
	strcpy(((b[10]).name), "face");
	strcpy(((b[11]).name), "side");
	strcpy(((b[12]).name), "trans");
	strcpy(((b[13]).name), "rotate");
}

void init_bid(t_b_create_data *b)
{
	(b[0 ]).id = 0 ;
	(b[1 ]).id = 1 ;
	(b[2 ]).id = 2 ;
	(b[3 ]).id = 3 ;
	(b[4 ]).id = 4 ;
	(b[5 ]).id = 5 ;
	(b[6 ]).id = 6 ;
	(b[7 ]).id = 7 ;
	(b[8 ]).id = 8 ;
	(b[9 ]).id = 9 ;
	(b[10]).id = 10;
	(b[11]).id = 11;
	(b[12]).id = 12;
	(b[13]).id = 13;
}

void init_btype(t_b_create_data *b)
{
	(b[0 ]).type = 0;
	(b[1 ]).type = 0;
	(b[2 ]).type = 0;
	(b[3 ]).type = 0;
	(b[4 ]).type = 0;
	(b[5 ]).type = 0;
	(b[6 ]).type = 0;
	(b[7 ]).type = 0;
	(b[8 ]).type = 0;
	(b[9 ]).type = 0;
	(b[10]).type = 0;
	(b[11]).type = 0;
	(b[12]).type = 1;
	(b[13]).type = 1;
}

void init_bstat(t_b_create_data *b)
{
	(b[0 ]).stat = 1;
	(b[1 ]).stat = 0;
	(b[2 ]).stat = 0;
	(b[3 ]).stat = 0;
	(b[4 ]).stat = 0;
	(b[5 ]).stat = 0;
	(b[6 ]).stat = 0;
	(b[7 ]).stat = 0;
	(b[8 ]).stat = 0;
	(b[9 ]).stat = 0;
	(b[10]).stat = 0;
	(b[11]).stat = 0;
	(b[12]).stat = 1;
	(b[13]).stat = 1;
}


void init_bo_x(t_b_create_data *b)
{
	(b[0 ]).o_x = 0;
	(b[1 ]).o_x = 0;
	(b[2 ]).o_x = 0;
	(b[3 ]).o_x = 0;
	(b[4 ]).o_x = 0;
	(b[5 ]).o_x = 0;
	(b[6 ]).o_x = 0;
	(b[7 ]).o_x = 0;
	(b[8 ]).o_x = 0;
	(b[9 ]).o_x = 0;
	(b[10]).o_x = 0;
	(b[11]).o_x = 0;
	(b[12]).o_x = 0;
	(b[13]).o_x = 0;
}

void init_bo_y(t_b_create_data *b)
{
	(b[0 ]).o_y = 0;
	(b[1 ]).o_y = 0;
	(b[2 ]).o_y = 0;
	(b[3 ]).o_y = 0;
	(b[4 ]).o_y = 0;
	(b[5 ]).o_y = 0;
	(b[6 ]).o_y = 0;
	(b[7 ]).o_y = 0;
	(b[8 ]).o_y = 0;
	(b[9 ]).o_y = 0;
	(b[10]).o_y = 0;
	(b[11]).o_y = 0;
	(b[12]).o_y = 0;
	(b[13]).o_y = 0;
}
