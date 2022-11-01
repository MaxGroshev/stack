#include "stack.h"

int num_of_elem;

int main()
{
    struct my_stack box = {};

    printf("Please input amount of elements \n");
    scanf("%d", &num_of_elem);

    stack_init(&box);

    for(int i = 0; i < num_of_elem; i++)
    {
        stack_push(&box, i);
    }

    int x = stack_pop(&box);
    int y = stack_pop(&box);
    int z = stack_pop(&box);
    int e = stack_pop(&box);
    printf("%d %d %d %d \n", x, y, z, e);

    stack_dump(&box);
    stack_delete(&box);
    return 0;
}




