/* *****************************************************************************

	This function return a 1 if the name given is  directory else it returns a 0

***************************************************************************** */


#include "main.h"


int is_dir(const char *name)
{
	struct stat st;
    stat(name, &st);
    return (S_ISDIR(st.st_mode));
}
