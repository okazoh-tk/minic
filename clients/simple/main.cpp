
#include "../common/display.h"
#include <cstdio>

int main()
{
    Display display(nullptr);

    int i = 0;

    while (display.dispatch() != -1) {
	printf("idle#%d", i++);
    }

    return 0;
}
