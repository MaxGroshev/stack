#include "stack.h"

int main()
{
    struct stack_t box = {};

    printf("Please input amount of elements \n");
    scanf("%ld", &box.capacity);

    stack_init(&box, box.capacity);
    int elem = 0;
    while (elem < box.capacity)
    {
        stack_push (&box, elem);
        elem++;
    }
    /*stack_push(&box, 30);

    int x = stack_pop (&box);
    int y = stack_pop (&box);
    int z = stack_pop (&box);
    int e = stack_pop (&box);
    printf("%d %d %d %d \n", x, y, z, e);*/

    FILE* num_com = fopen ("test.code", "r");
    int code_of_com = 0;
    while (code_of_com != HLT)
    {
        fscanf (num_com, "%d", &code_of_com);
        //printf("%d\n", code_of_com);
        switch (code_of_com)
        {
            case PUSH:
                fscanf (num_com, "%d", &elem);
                stack_push (&box, elem);
                break;

            case ADD:
                //stack_add (&box);
                elem = stack_pop (&box);
                elem += stack_pop (&box);
                stack_push (&box, elem);
                printf("%d\n", elem);
                //STACK_CHECK
                break;

            case MUL:
                //stack_mul (&box);
                elem = stack_pop (&box);
                elem *= stack_pop (&box);
                stack_push (&box, elem);
                //STACK_CHECK
                break;

            case OUT:
                elem = stack_pop (&box);
                printf("%d\n", elem);
                break;

            case HLT:
                break;
        }
    }
    stack_dump(&box, __FILE__, __FUNCTION__, __LINE__, 1);
    stack_delete(&box);
    return 0;
}



