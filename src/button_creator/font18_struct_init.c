#include "button_creator.h"

static void pad_left_init(t_f_create_data *fdata)
{
	int i;

	i = 0;
	fdata[i++].pad_left = 10; // space
	while (i < 96) // 96 becuse space is not counted in files
	{
		fdata[i].pad_left = 3;
		i++;
	}
}


static void pad_right_init(t_f_create_data *fdata)
{
	int i;

	i = 0;
	fdata[i++].pad_right = 10; // space
	while (i < 96) // 96 becuse space is not counted in files
	{
		fdata[i].pad_right = 3;
		i++;
	}

}

static void pad_top_init(t_f_create_data *fdata)
{
	int i;

	i = 0;
	while (i < 96) // 96 becuse space is not counted in files
	{
		fdata[i].pad_top = 0;
		i++;
	}

	fdata['+' - 32].pad_top = FONT_18_SMALL_PAD_TOP;
	fdata[',' - 32].pad_top = FONT_18_SMALL_SMALL_PAD_TOP;
	fdata['-' - 32].pad_top = FONT_18_SMALL_MIDLE_PAD_TOP;
	fdata['.' - 32].pad_top = FONT_18_SMALL_SMALL_PAD_TOP;
	fdata[':' - 32].pad_top = FONT_18_SMALL_PAD_TOP;
	fdata[';' - 32].pad_top = FONT_18_SMALL_PAD_TOP;
	fdata['<' - 32].pad_top = FONT_18_SMALL_PAD_TOP;
	fdata['=' - 32].pad_top = FONT_18_SMALL_EQUAL_PAD_TOP;
	fdata['>' - 32].pad_top = FONT_18_SMALL_PAD_TOP;
	fdata['@' - 32].pad_top = FONT_18_SMALL_AT_PAD_TOP;
	fdata['_' - 32].pad_top = FONT_18_SMALL_UNDER_PAD_TOP;
	fdata['a' - 32].pad_top = FONT_18_SMALL_PAD_TOP;
	fdata['c' - 32].pad_top = FONT_18_SMALL_PAD_TOP;
	fdata['e' - 32].pad_top = FONT_18_SMALL_PAD_TOP;
	fdata['g' - 32].pad_top = FONT_18_SMALL_PAD_TOP;
	fdata['m' - 32].pad_top = FONT_18_SMALL_PAD_TOP;
	fdata['n' - 32].pad_top = FONT_18_SMALL_PAD_TOP;
	fdata['o' - 32].pad_top = FONT_18_SMALL_PAD_TOP;
	fdata['p' - 32].pad_top = FONT_18_SMALL_PAD_TOP;
	fdata['q' - 32].pad_top = FONT_18_SMALL_PAD_TOP;
	fdata['r' - 32].pad_top = FONT_18_SMALL_PAD_TOP;
	fdata['s' - 32].pad_top = FONT_18_SMALL_PAD_TOP;
	fdata['u' - 32].pad_top = FONT_18_SMALL_PAD_TOP;
	fdata['v' - 32].pad_top = FONT_18_SMALL_PAD_TOP;
	fdata['w' - 32].pad_top = FONT_18_SMALL_PAD_TOP;
	fdata['x' - 32].pad_top = FONT_18_SMALL_PAD_TOP;
	fdata['y' - 32].pad_top = FONT_18_SMALL_PAD_TOP;
	fdata['z' - 32].pad_top = FONT_18_SMALL_PAD_TOP;
	fdata['~' - 32].pad_top = FONT_18_SMALL_PAD_TOP;

}

void font18_struct_init(t_f_create_data *fdata)
{
	pad_left_init(fdata);
	pad_right_init(fdata);
	pad_top_init(fdata);

}
