#include "arena_alloc.h"
#include <stdlib.h>

int arena_create(arena_t *arena, size_t arena_size)
{
    arena->start = malloc(arena_size);
    arena->idx = 0;
    arena->size = arena_size;

    return arena->start == NULL ? -1 : 0;
}
void *arena_alloc(arena_t *arena, size_t size)
{

    if (arena->idx >= arena->size)
    {
        return NULL;
    }

    void *mem = arena->start + arena->idx;

    arena->idx += size;

    return mem;
}
void arena_free(arena_t *arena)
{
    free(arena->start);
    arena->start = NULL;
}