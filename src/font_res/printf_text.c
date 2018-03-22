#include "main.h"


static char *text_itoa(long long int num)
{
	static char str[22];
	int k;
	unsigned long long n;

	k = 0;
	memset(str, 0, 22);
	if(num == 0)
	{
		str[k] = '0';
		return str;
	}
	else if(num < 0)
		str[k++] = '-';
	n = (num < 0) ? -num : num;
	while(n != 0)
	{
		str[k++] = (n % 10) + 48;
		n /= 10;
	}
	return (str);
}






// void put_text(char *str, t_root *root, int o_x, int o_y)

// put_text(t_root *root, t_image *image, char *str, int x, int y, t_font font)
int put_text(t_root *root, t_image *image, char *str, ...)
{
	int i;
	// int o_width; // origine to width;
	int o_[4]; // origine to width;
	t_font *font;
	va_list args;
	int RGBA;


	va_start(args, str);
	ft_memset(o_, 0, 4);

	i = 0;
	o_[0] = 0; // o_width
	o_[1] = va_arg(args, int); // o_x
	o_[2] = va_arg(args, int); // o_y
	// o_[3] = va_arg(args, int); // font
	font  = va_arg(args, t_font *); // Get tje font;
	// RGBA  = va_arg(args, int);	// het the RGBA color`
	RGBA = 0x00ff0000;


	// o_width = 0;
	// font = root->font_24;
	if(!str)
	{
		printf ("[-] Error: getting string pointer");
		return 0;
	}

	while (str[i])
	{
		printf("came there [%d]\n", str[i] - 32);
		draw_font(font[str[i] - 32], image, o_[1] + o_[0] + font[str[i] - 32].pad_left,  o_[2] + font[str[i] - 32].pad_top, RGBA);
		o_[0] += font[str[i] - 32].x + font[str[i] - 32].pad_right;
		i++;
	}
	va_end(args);
	return (o_[0]);
}

void printf_text(t_root *root, t_image *img, char *str, ...)
{
	int i;
	// int o_width; // origine to width;
	int RGBA;
	int o_[5]; // exta variables
	t_font *font;
	va_list args;

	va_start(args, str);
	ft_memset(o_, 0, 5);
	i = 0;
	// o_width = 0;
	font = root->font_24;
	RGBA = 0xffffffff;
	o_[0] = img->o_y; // o_width
	o_[1] = 0; // o_x
	o_[2] = 0; // o_y

	while (str[i])
	{
		printf("came there [%d]i[%c]\n", str[i] - 32, str[i]);
		if(str[i] == '%')
		{
			// put_text(t_root *root, t_image *image, char *str, int x, int y, t_font font)

			if(str[i + 1] && str[i + 1] == 's')
			{
				o_[0] += put_text(root, img, va_arg(args, char *), o_[1], o_[2], font, RGBA);
				i++;
			}
			else if(str[i + 1] && str[i + 1] == 'd')
			{
				o_[0] += put_text(root, img, text_itoa(va_arg(args, int)), o_[1], o_[2], font, RGBA);
				i++;
			}
			else if(str[i + 1] && str[i + 1] == 'f')
			{
				font = va_arg(args, t_font *);
				i++;}
			else if(str[i + 1] && str[i + 1] == 'C')
			{
				RGBA = va_arg(args, int);
				i++;
				printf("CAME IN RGBA [%x]---+++\n", RGBA);

			}
			else if(str[i + 1] && str[i + 1] == 'x')
			{
				o_[1] = va_arg(args, int);
				i++;
			}
			else if(str[i + 1] && str[i + 1] == 'y')
			{
				o_[2] = va_arg(args, int);
				i++;
			}
			else
			{
				draw_font(font[str[i] - 32], &(root->menu), o_[1] + o_[0] + font[str[i] - 32].pad_left,  o_[2] + font[str[i] - 32].pad_top, RGBA);
				o_[0] += font[str[i] - 32].x + font[str[i] - 32].pad_right;
				i++;
			}
		}
		else
		{
			draw_font(font[str[i] - 32], &(root->menu), o_[1] + o_[0] + font[str[i] - 32].pad_left,  o_[2] + font[str[i] - 32].pad_top, RGBA);
			o_[0] += font[str[i] - 32].x + font[str[i] - 32].pad_right;
			i++;

		}
	}
	va_end(args);
}
