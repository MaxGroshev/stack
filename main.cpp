#include "stack.h"

int main()
{
    struct stack_t box = {};

    printf("Please input amount of elements \n");
    scanf("%ld", &box.capacity);

    stack_init(&box, box.capacity);

    for(int i = 0; i < box.capacity; i++)
    {
        stack_push(&box, i);
    }

    int x = stack_pop(&box);
    int y = stack_pop(&box);
    int z = stack_pop(&box);
    int e = stack_pop(&box);
    printf("%d %d %d %d \n", x, y, z, e);

    stack_dump(&box, __FILE__, __FUNCTION__, __LINE__ );
    stack_delete(&box);
    return 0;
}



