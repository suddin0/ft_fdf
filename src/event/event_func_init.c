#include "main.h"




void event_func_init(t_root *root)
{
	(root->evnt).pmotion[0] = pmotion_func_0;
	(root->evnt).pmotion[1] = pmotion_func_1;
	(root->evnt).pmotion[2] = pmotion_func_2;

	(root->evnt).bpress [0] = bpress_func_0;
	(root->evnt).bpress [1] = bpress_func_1;
	(root->evnt).bpress [2] = bpress_func_2;
}
