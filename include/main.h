/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 07:20:50 by suddin            #+#    #+#             */
/*   Updated: 2018/03/30 05:29:02 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H


#define not_used __attribute__((unused))

# if defined(__linux__)
/**
 *	In Linux the speex of mlxloop is too fust thus we use the below define
 *	to adjust the speed
**/
// #  define SLEEP_INTER 10000
#  define SLEEP_INTER 1000
# else
#  define SLEEP_INTER 0
# endif

# include <sys/types.h>
# include <sys/stat.h>
# include <limits.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <math.h>
# include <dirent.h>
# include <stdarg.h>

# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"
# include "button_map.h"
# include "nn_mask.h"

# define DEF_ROOT_X 1600
# define DEF_ROOT_Y 950
# define ORIGINE_X 270.0f
# define ORIGINE_Y 290.0f
# define STEP 30.0f
# define MENU_X DEF_ROOT_X / 4
# define MENU_Y DEF_ROOT_Y
# define OPT_X MENU_X / 3
# define OPT_Y 95
# define FOOT_X DEF_ROOT_X - (DEF_ROOT_X / 4)
# define FOOT_Y 23
# define PREV_X DEF_ROOT_X - (DEF_ROOT_X / 4)
# define PREV_Y DEF_ROOT_Y - FOOT_Y
# define MAP_LIST_OY 60
# define BUTTON_SIZE 19000 * 4
# define CHAR_SIZE_28 20000 * 4
# define CHAR_SIZE_18 54140 * 4
# define FCHAR_MAX 98
# define BUTTON_MAX 16
# define BUTTON_STRUCT_PATH	  "res/__buttons__/button.struct"
# define FONT_24_STRUCT_PATH "res/__font__/font@24.struct"
# define FONT_18_STRUCT_PATH "res/__font__/font@18.struct"
# define FONT_11_STRUCT_PATH "res/__font__/font@11.struct"
# define MAP_PATH "maps"
# define MAX_ERROR_MSG 250
# define MENU_BG_COLOR 0x383f49
# define FOOT_BG_COLOR 0x383f49
# define PREV_BG_COLOR 0x323842
# define MAP_COLOR 0xe0e0bd
# define COL_ERROR 0xD24B4Bff
# define COL_WHITE 0xffffffff
# define COL_R(R) ((col >> 24) & 0xFF)
# define COL_G(G) ((col >> 16) & 0xFF)
# define COL_B(B) ((col >> 8 ) & 0xFF)
# define COL_A(R) (col & 0xFF);
# define USAGE_MESSAGE "Usage: ./fdf <file.fdf>\n"
# define PMOTION NN_MOTIONNOTIFY
# define KPRESS NN_KEYPRESS
# define BPRESS NN_BUTTONPRESS
# define BRELEASE NN_BUTTONRELEASE
# define KRELEASE NN_KEYRELEASE
# define VISIBL NN_VISIBILITYNOTIFY
# define DESTROY NN_DESTROYNOTIFY
# define ST_DEFAULT 0
# define ST_HOVER 1
# define ST_ACTIVE 2
# define TP_NORMAL 0
# define TP_RADIO 1
# define MV_TRANS 0
# define MV_ROTAT 1
# define PMOTION_M NN_POINTERMOTIONMASK
# define KPRESS_M NN_KEYPRESSMASK
# define BPRESS_M NN_BUTTONPRESSMASK
# define BRELEASE_M NN_BUTTONRELEASEMASK
# define KRELEASE_M NN_KEYRELEASEMASK
# define VISIBL_M NN_VISIBILITYCHANGEMASK
# define DESTROY_M NN_STRUCTURENOTIFYMASK
# define COLOR(MLX_PTR, H_COLOR) mlx_get_color_value(MLX_PTR, H_COLOR)
# define VIEW mlx_put_image_to_window
# define CLEAR(I) set_color(I.img, I.x * I.y, I.bg);
# define CAST_T_ROOT(ROT) ((t_root *) ROT)
# define MAX_EVENT_KEY 15

typedef unsigned char	t_uchar;
typedef unsigned int	t_uint;

typedef struct	s_point
{
	double x;
	double y;
	double z;
}				t_point;

typedef struct	s_line_var
{
	int x0;
	int y0;
	int x1;
	int y1;
	int dx;
	int sx;
	int dy;
	int sy;
	int err;
	int e2;
}				t_line_var;

typedef struct	s_font_var
{
	int				x;
	int				y;
	int				k;
	unsigned char	a;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	bga;
	unsigned char	bgr;
	unsigned char	bgg;
	unsigned char	bgb;
	double			opacity;
	double			o_opacity_r;
}				t_font_var;

typedef struct	s_map_data
{
	int					row;
	int					col;
	long int			*data;
	struct s_map_data	*next;
	struct s_map_data	*prev;
}				t_m_data;

typedef struct	s_mlx_image
{
	void	*img_ptr;
	char	*img;
	int		bpp;
	int		sl;
	int		end;
	int		o_x;
	int		o_y;
	int		x;
	int		y;
	int		bg;
}				t_image;

typedef struct	s_fdfmap
{
	char				*name;
	char				*path;
	t_image				*img;
	t_point				**map;
	long				*line_sz;
	int					file_sz;
	int					lines;
	t_m_data			*data;
	double				origine_x;
	double				origine_y;
	int					step;
	int					color;
	struct s_fdfmap		*next;
}				t_map;

typedef struct	s_button
{
	int			id;
	char		type;
	char		stat;
	char		view[3][BUTTON_SIZE];
	char		name[100];
	int			x;
	int			y;
	int			o_x;
	int			o_y;
	void		*value;
	void		(*f)(void *root);
}				t_button;

typedef struct	s_char
{
	unsigned	ascii;
	int			x;
	int			y;
	char		data[CHAR_SIZE_28];
	int			pad_top;
	int			pad_left;
	int			pad_right;
}				t_char;

typedef t_char	t_font;

typedef struct	s_map_list
{
	int		total_map;
	char	**map_name;
	int		curr_map;
	char	error;
	char	error_msg[MAX_ERROR_MSG + NAME_MAX];
	int		o_x;
	int		o_y;
	int		x;
	int		y;
	int		height;
	int		border;
	int		border_active;
}				t_map_list;

typedef struct	s_event_func
{
	int	(*pmotion[3])(int x, int y, void *rot);
	int	(*kpress[3])(int key, void *rot);
	int	(*kreleas[3])(int key, void *rot);
	int	(*bpress[3])(int key, int x, int y, void *rot);
	int	(*breleas[3])(int key, int x, int y, void *rot);
}				t_event_func;

typedef struct	s_menu
{
	t_image		*img;
	char		hover;
	char		click;
	void		(*hover_f)(void *root);
	void		(*click_f)(void *root);
	t_button	button[BUTTON_MAX];
	int			curr_opt;
	t_button	*maps;
	int			mvment;
	int			btn_hover;
	int			btn_clicked;
	t_map_list	list;
}				t_menu;

typedef struct	s_font_data
{
	t_image	*img;
	t_uint	c;
}				t_font_data;

typedef struct	s_printf_text
{
	int			i;
	t_font_data	d;
	int			o_[5];
	t_font		*font;
	va_list		args;
}				t_printf_text;

typedef struct	s_root
{
	void			*mlx;
	void			*win;
	int				sz_x;
	int				sz_y;
	char			name[NAME_MAX * 2];
	t_map			*map;
	t_image			menu;
	t_image			prev;
	t_image			foot;
	t_menu			men;
	int				key;
	int				(*(kevent[MAX_EVENT_KEY]))(struct s_root *root);
	t_event_func	evnt;
	int				key_set[MAX_EVENT_KEY];
	t_font			*font_24;
	t_font			*font_18;
	t_font			*font_11;
}				t_root;

int				gmap_is_space(char c);
int				gmap_is_num_hex(char c);
long			gmap_line_pnt(char *str, long line);
char			*gmap_name_verif(char *name, t_map **map, t_image *img);
char			*gmap_file_verif(char *name, t_map **map, t_image *img);
int				is_dot_fdf(char *str);
int				file_size(const char *name);
int				is_dir(const char *name);
int				is_file(const char *name);
t_point			**data_to_array(t_map *map);
long			*get_num(char *str, long o_line, int n_line, int dig);
int				count_num(char *str, long o_line, long n_line);
t_map			*map_malloc(t_image *img);
t_map			*get_map(char *name, t_image *img);
void			free_map(t_map *map);
void			print_map(t_map *map, int space);
int				pre_check(int argc, char **argv);
void			root_init(t_root *root, char **argv);
void			free_root(t_root *root, int exit_code);
void			put_color(t_image *img, int x, int y, int col);
void			set_color(char *img, unsigned int len, int col);
void			init_menu(t_root *root, t_image *menu);
void			init_prev(t_root *root, t_image *prev);
void			init_foot(t_root *root, t_image *f);
void			event_handler(t_root *root);
void			draw_line(t_map *map, t_point o, t_point n, int color);
void			draw_dot(t_map *img, t_point o, t_point n, int color);
void			draw_map(t_root *root, void *img_ptr, t_map *map);
void			modmatrix(t_map *map, void f(t_point *a, double val), \
		double rot);
void			rotate_x(t_point *a, double v);
void			rotate_y(t_point *a, double v);
void			rotate_z(t_point *a, double v);
void			trans_x(t_map *a, double v);
void			trans_y(t_map *a, double v);
void			zoom(t_map *a, int v);
int				k_up(t_root *root);
int				k_down(t_root *root);
int				k_right(t_root *root);
int				k_left(t_root *root);
int				k_plus(t_root *root);
int				k_minus(t_root *root);
int				k_x(t_root *root);
int				k_s(t_root *root);
int				k_y(t_root *root);
int				k_u(t_root *root);
int				k_z(t_root *root);
int				k_a(t_root *root);
int				k_esc(t_root *root);
int				is_button_area(t_button *b, int x, int y);
void			show_button(t_root *root, t_image *m);
void			draw_button(t_button button, t_image *img, int stat);
void			button_init(t_root *root, t_image *m);
int				b0(t_root *root);
int				b1(t_root *root);
int				b2(t_root *root);
int				b3(t_root *root);
int				b4(t_root *root);
int				b5(t_root *root);
int				b6(t_root *root);
int				b7(t_root *root);
int				b8(t_root *root);
int				b9(t_root *root);
int				b10(t_root *root);
int				b11(t_root *root);
int				b12(t_root *root);
int				b13(t_root *root);
int				pmotion_func_0(int x, int y, void *root);
int				pmotion_func_1(int x, int y, void *root);
int				pmotion_func_2(int x, int y, void *root);
int				bpress_func_0(int key, int x, int y, void *rot);
int				bpress_func_1(int key, int x, int y, void *rot);
int				bpress_func_2(int key, int x, int y, void *rot);
void			event_func_init(t_root *root);
void			printf_text(t_root *root, t_image *img, char *str, ...);
void			draw_font(t_char chr, t_font_data *d, int o_x, int o_y);
void			init_list(char *map_dir, t_map_list *list);
int				is_list_area(t_map_list list, int x, int y);
void			show_list(t_map_list *list, t_root *root);
void			load_map(t_root *root, t_map_list *list, int btn);
void			free_list(t_map_list *list);
int				kpress(int key, t_root *root);
int				krelease(int key, t_root *root);
int				bpress(int key, int x, int y, t_root *root);
int				pmotion(int x, int y, t_root *root);
#endif
