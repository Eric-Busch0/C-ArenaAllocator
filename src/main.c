#include "arena_alloc.h"
#include <stdio.h>

int main()
{

    arena_t arena;

    arena_create(&arena, sizeof(int));

    int *a =  arena_alloc(&arena, sizeof(int));


    if(a == NULL)
    {
        printf("Couldnt get memory!");
    }
    else
    {
        *a = 3;
        printf("A %d\n", *a);
    }


    // Lose reference to the original memory, but the arena will allow it to be freed!
    a =  arena_alloc(&arena, sizeof(int));

    if(a == NULL)
    {
        printf("Couldnt get memory!\n");
    }
    else
    {
        *a = 5;
        printf("A %d\n", *a);
    }
    arena_free(&arena);
}