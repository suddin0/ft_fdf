/* *****************************************************************************

	This function return a 1 if the name given is  file else it returns a 0

***************************************************************************** */


#include "main.h"
#include <sys/stat.h>



int is_file(const char *name)
{
	struct stat st;
    stat(name, &st);
    return S_ISREG(st.st_mode);
}
