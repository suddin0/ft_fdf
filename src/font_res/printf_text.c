#include "main.h"


static char *text_itoa(long int num)
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
		str[0] = '-';
	n = (num < 0) ? -num : num;
	while(n != 0)
	{
		str[k] = (n % 10) + 48;
		n /= 10;
		k++;
	}
	ft_strrev(str);
	printf("%s\n", str);
	return (str);
}



// void put_text(char *str, t_root *root, int o_x, int o_y)

// put_text(t_root *root, t_image *image, char *str, int x, int y, t_font font)
int put_text(t_root *root, t_image *img, char *str, ...)
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
	o_[0] = va_arg(args, int); // o_x
	o_[1] = va_arg(args, int); // o_y
	font  = va_arg(args, t_font *); // Get tje font;
	RGBA = va_arg(args, int);
	if(!str)
		return 0;
	while (str[i])
	{
		if(!ft_isprint(str[i]))
			str[i] = 125;
		draw_font(font[str[i] - 32], img, o_[0] + font[str[i] - 32].pad_left, o_[1] + font[str[i] - 32].pad_top, RGBA);
		o_[0] +=  font[str[i] - 32].x + font[str[i] - 32].pad_right;
		i++;
	}
	va_end(args);
	return (o_[0]);
}

void printf_text(t_root *root, t_image *img, char *str, ...)
{
	int i;
	int RGBA;
	int o_[5]; // exta variables
	t_font *font;
	va_list args;

	va_start(args, str);
	ft_memset(o_, 0, 5);
	i = 0;
	font = root->font_18;
	RGBA = 0xffffffff;
	o_[0] = 10; // o_x
	o_[1] = 10; // o_y

	while (str[i])
	{
		printf("came there [%d]i[%c]\n", str[i] - 32, str[i]);
		if(!ft_isprint(str[i]))
			str[i] = 127;
		if(str[i] == '%')
		{
			if(str[i + 1] && str[i + 1] == 'C')
			{
				RGBA = va_arg(args, int);
				i += 2;
				continue;
			}
			if(str[i + 1] && str[i + 1] == 's')
			{
				o_[0] = put_text(root, img, va_arg(args, char *), o_[0], o_[1], font, RGBA);
				i += 2;
				continue;
			}
			if(str[i + 1] && str[i + 1] == 'd')
			{
				o_[0] = put_text(root, img, text_itoa(va_arg(args, int)), o_[0], o_[1], font, RGBA);
				i += 2;
				continue;
			}
			if(str[i + 1] && str[i + 1] == 'x')
			{
				o_[0] = va_arg(args, int);
				i += 2;
				continue;
			}
			if(str[i + 1] && str[i + 1] == 'y')
			{
				o_[1] = va_arg(args, int);
				i += 2;
				continue;
			}
			if(str[i + 1] && str[i + 1] == 'f')
			{
				font  = va_arg(args, t_font *);
				i += 2;
				continue;
			}
			else
			{
				draw_font(font[str[i] - 32], img, o_[0] + font[str[i] - 32].pad_left,  o_[1] + font[str[i] - 32].pad_top, RGBA);
				o_[0] += font[str[i] - 32].x + font[str[i] - 32].pad_right;

			}

		}
		else
		{
			draw_font(font[str[i] - 32], img, o_[0] + font[str[i] - 32].pad_left,  o_[1] + font[str[i] - 32].pad_top, RGBA);
			o_[0] += font[str[i] - 32].x + font[str[i] - 32].pad_right;
		}
		i++;
	}
	va_end(args);
}
