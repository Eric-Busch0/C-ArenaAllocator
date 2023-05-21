#ifndef ARENA_ALLOC_H
#define ARENA_ALLOC_H
#include <stddef.h>

typedef struct
{
    void *start;
    size_t idx;
    size_t size;
} arena_t;

int arena_create(arena_t *arena, size_t arena_size);
void *arena_alloc(arena_t *arena, size_t size);
void arena_free(arena_t *arena);
#endif