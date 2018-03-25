#include "main.h"

inline static int dir_file_count_list(char *map_dir)
{
	DIR *dir;
	struct dirent *ep;
	int file;
	char *tmp_file;

	dir = opendir(map_dir);
	file = 0;
	if (dir != NULL)
  	{
		while ((ep = readdir(dir)))
		{
			tmp_file = (char *) malloc(sizeof(char) * ((ft_strlen(map_dir)\
			+ ft_strlen(ep->d_name) + 5)));
			ft_strcpy(tmp_file, map_dir);
			ft_strcat(tmp_file, "/");
			ft_strcat(tmp_file, ep->d_name);
			if(is_file(tmp_file) == 1 && is_dot_fdf(ep->d_name))
				file++;
			free(tmp_file);
		}
		closedir(dir);
  	}
	else
		return (-1);
	return (file);
}

inline static void set_error_message(t_map_list *list, char *map_dir,  int error_no)
{
	if (error_no == 1)
	{
		list->error = 1;
  		ft_strcpy(list->error_msg, "[-] Error: directory ");
  		ft_strcat(list->error_msg, map_dir);
  		ft_strcat(list->error_msg, " might be empty (read 0 files)");
	}
	else if(error_no == 2)
	{
		list->error = 2;
		ft_strcpy(list->error_msg, "[-] Error: directory ");
		ft_strcat(list->error_msg, map_dir);
		ft_strcat(list->error_msg, " could not been open");
	}
	else if(error_no == 3)
	{
		list->error = 3;
		ft_strcpy(list->error_msg, "[-] Error: Can not access ");
		ft_strcat(list->error_msg, map_dir);
		ft_strcat(list->error_msg, ". (Path might nit access)");
	}
}

// inline static void init_var(t_map_list *list)
// {
// 	list->total_map = 0;
// 	list->curr_map = -1;
// 	list->error = 0; // no rror
// 	list->o_x = 10;
// 	list->o_y = 90;
// 	list->x = MENU_X;
// 	list->y = MENU_Y + list->o_y;
// }

inline static void set_name(DIR *dir, t_map_list *list, char *map_dir)
{
	char *tmp_file;
	struct dirent *ep;
	int i = 0;

	tmp_file = NULL;
	while ((ep = readdir(dir)))
	{
		tmp_file = (char *) malloc(sizeof(char) * ((ft_strlen(map_dir) + \
		ft_strlen(ep->d_name) + 5)));
		ft_strcpy(tmp_file, map_dir);
		ft_strcat(tmp_file, "/");
		ft_strcat(tmp_file, ep->d_name);
		if(is_file(tmp_file))
			if(is_dot_fdf(ep->d_name))
				list->map_name[i++] = ft_strdup(tmp_file);  // MUST BE FREED
		free(tmp_file);
	}
}
void init_list(char *map_dir, t_map_list *list)
{
	DIR *dir;
	struct dirent *ep;
	int file;
	char *tmp_file;

	// init_var(list);
	if(!is_dir(map_dir))
	{
		set_error_message(list, map_dir, 3);
		return ;
	}
	if((list->total_map = dir_file_count_list(map_dir)) == 0)
		set_error_message(list, map_dir, 1);
	dir = opendir(map_dir);
	if (dir != NULL || list->total_map == -1)
  	{
		list->map_name = (char **) malloc(sizeof(char *) * list->total_map); // MUST BE FREED
		set_name(dir, list, map_dir);
		closedir(dir);
  	}
	else
		set_error_message(list, map_dir, 1);
}
