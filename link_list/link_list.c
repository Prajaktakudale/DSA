#include "link_list.h"
#include <stdlib.h>

DLL* create_list() {
        DLL* list = calloc(1,sizeof(DLL));
        list->start = NULL;
		list->size = 0;
        return list;
};