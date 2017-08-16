#include <stdio.h>
#include <string.h>

void copy_int(int val, void *buf, int maxbytes)
{
    if ((unsigned)maxbytes > sizeof(val)) {
        memcpy(buf, (void *)&val, sizeof(val));
    }
}
