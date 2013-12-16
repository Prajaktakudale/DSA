#include <memory.h>
typedef char String[256];
typedef int (*compare)(void* first, void* second);

void isort(void* base, size_t numberOfElements, size_t elementSize,
			compare comp); 