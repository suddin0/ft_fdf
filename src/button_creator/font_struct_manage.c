#include "button_creator.h"




void font_struct_manage(t_font *font, t_f_create_data *fdata)
{
		int i;

		i = 0;
		while (i < 96)
		{
			font[i].pad_top = fdata[i].pad_top;
			font[i].pad_left = fdata[i].pad_left;
			font[i].pad_right = fdata[i].pad_right;
			i++;
		}
}
