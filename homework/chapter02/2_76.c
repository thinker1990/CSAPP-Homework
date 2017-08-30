#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *calloc(size_t nmemb, size_t size)
{
    if (nmemb == 0 || size == 0) {
        return NULL;
    }

    size_t required_size = nmemb * size;
    if (nmemb != required_size / size) {
        return NULL;
    }

    void *result = malloc(required_size);
    if (result == NULL) {
        return NULL;
    }

    memset(result, 0, required_size);

    return result;
}
