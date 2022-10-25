#include <malloc.h>
#include <string.h>

void *Realloc(void *, size_t);

int main() {
    return 0;
}

void *Realloc(void *ptr, size_t size) {
    void *new_ptr = malloc(sizeof(void *) * size);
    size_t old_size = malloc_usable_size(ptr);
    memcpy(new_ptr, ptr, old_size);
    free(ptr);
    return new_ptr;
}
