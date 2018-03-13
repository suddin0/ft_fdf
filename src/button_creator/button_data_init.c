#include "button_creator.h"


// initiate button create data names
void button_data_init(t_b_create_data *b)
{
	strcpy(((b[0 ]).name), "controle");
	strcpy(((b[1 ]).name), "maps");
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
	init_bid  (b);
	init_btype(b);
	init_bstat(b);
	init_borigine (b);
}

void init_bid(t_b_create_data *b)
{
	(b[0 ]).id = 0 ; // main
	(b[1 ]).id = 1 ; // map
	(b[2 ]).id = 2 ; // info
	(b[3 ]).id = 3 ; // left
	(b[4 ]).id = 4 ; // down
	(b[5 ]).id = 5 ; // right
	(b[6 ]).id = 6 ; // up
	(b[7 ]).id = 7 ; // uzoom
	(b[8 ]).id = 8 ; // zoom
	(b[9 ]).id = 9 ; // default
	(b[10]).id = 10; // face
	(b[11]).id = 11; // side
	(b[12]).id = 12; // trans
	(b[13]).id = 13; // rotate
}

void init_btype(t_b_create_data *b)
{
	(b[0 ]).type = TP_RADIO;  // main
	(b[1 ]).type = TP_RADIO;  // map
	(b[2 ]).type = TP_RADIO;  // info
	(b[3 ]).type = TP_NORMAL; // left
	(b[4 ]).type = TP_NORMAL; // down
	(b[5 ]).type = TP_NORMAL; // right
	(b[6 ]).type = TP_NORMAL; // up
	(b[7 ]).type = TP_NORMAL; // uzoom
	(b[8 ]).type = TP_NORMAL; // zoom
	(b[9 ]).type = TP_NORMAL; // default
	(b[10]).type = TP_NORMAL; // face
	(b[11]).type = TP_NORMAL; // side
	(b[12]).type = TP_RADIO;  // trans
	(b[13]).type = TP_RADIO;  // rotate
}

void init_bstat(t_b_create_data *b)
{
	(b[0 ]).stat = 2; // main
	(b[1 ]).stat = 0; // map
	(b[2 ]).stat = 0; // info
	(b[3 ]).stat = 0; // left
	(b[4 ]).stat = 0; // down
	(b[5 ]).stat = 0; // right
	(b[6 ]).stat = 0; // up
	(b[7 ]).stat = 0; // uzoom
	(b[8 ]).stat = 0; // zoom
	(b[9 ]).stat = 0; // default
	(b[10]).stat = 0; // face
	(b[11]).stat = 0; // side
	(b[12]).stat = 2; // trans
	(b[13]).stat = 0; // rotate
}
//
// # define OX_MAIN
// # define OX_MAP
// # define OX_INFO
// # define OX_LEFT
// # define OX_DOWN
// # define OX_RIGHT
// # define OX_UP
// # define OX_UZOOM
// # define OX_ZOOM
// # define OX_DEFAULT
// # define OX_FACE
// # define OX_SIDE
// # define OX_TRANS
// # define OX_ROTATE


void init_borigine(t_b_create_data *b)
{
	(b[0 ]).o_x = OX_MAIN	; // main
	(b[1 ]).o_x = OX_MAP	; // map
	(b[2 ]).o_x = OX_INFO	; // info
	(b[3 ]).o_x = OX_LEFT	; // left
	(b[4 ]).o_x = OX_DOWN	; // down
	(b[5 ]).o_x = OX_RIGHT	; // right
	(b[6 ]).o_x = OX_UP		; // up
	(b[7 ]).o_x = OX_UZOOM	; // uzoom
	(b[8 ]).o_x = OX_ZOOM	; // zoom
	(b[9 ]).o_x = OX_DEFAULT; // default
	(b[10]).o_x = OX_FACE	; // face
	(b[11]).o_x = OX_SIDE	; // side
	(b[12]).o_x = OX_TRANS	; // trans
	(b[13]).o_x = OX_ROTATE	; // rotate

	(b[0 ]).o_y = OY_MAIN	; // main
	(b[1 ]).o_y = OY_MAP	; // map
	(b[2 ]).o_y = OY_INFO	; // info
	(b[3 ]).o_y = OY_LEFT	; // left
	(b[4 ]).o_y = OY_DOWN	; // down
	(b[5 ]).o_y = OY_RIGHT	; // right
	(b[6 ]).o_y = OY_UP		; // up
	(b[7 ]).o_y = OY_UZOOM	; // uzoom
	(b[8 ]).o_y = OY_ZOOM	; // zoom
	(b[9 ]).o_y = OY_DEFAULT; // default
	(b[10]).o_y = OY_FACE	; // face
	(b[11]).o_y = OY_SIDE	; // side
	(b[12]).o_y = OY_TRANS	; // trans
	(b[13]).o_y = OY_ROTATE	; // rotate
}
