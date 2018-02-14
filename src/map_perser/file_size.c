/* *****************************************************************************

	This function return a 1 if the name given is  directory else it returns a 0

***************************************************************************** */


#include "main.h"



int file_size(const char *name)
{
	struct stat st;

	if(is_file(name) == 0)
		return (-1);
	stat(name, &st);
	return (st.st_size);
}
