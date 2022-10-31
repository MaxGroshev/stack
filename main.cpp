#include "stack.h"

int main()
{
    struct my_stack box = {};

    stack_init(&box);

    stack_push(&box, 10);
    stack_push(&box, 20);
    stack_push(&box, 30);
    stack_push(&box, 40);

    int x = stack_pop(&box);
    int y = stack_pop(&box);
    int z = stack_pop(&box);
    int e = stack_pop(&box);
    printf("%d %d %d %d \n", x, y, z, e);

    stack_delete(&box);
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------------------------

void stack_init(my_stack* box)
{
    box -> counter = 0;
    box -> data = (int*)calloc(box -> counter , sizeof(int));

    if(stack_check(box) != STACK_IS_OKEY)   STACK_CHECK
}

//-------------------------------------------------------------------------------------------------------------------------------------------

void stack_push(my_stack* box, int element)
{
    if(stack_check(box) != STACK_IS_OKEY)   STACK_CHECK


    box -> data = (int*) realloc(box -> data, (box -> counter + 1) * sizeof(int));
    box -> data[box -> counter++] = element;

    if(stack_check(box) != STACK_IS_OKEY)   STACK_CHECK
}

//----------------------------------------------------------------------------------------------------------------------------------------------

int stack_pop(my_stack* box)
{
    box -> counter--;

    if(stack_check(box) != STACK_IS_OKEY)   STACK_CHECK

    return box -> data[ -> counter];
}

//----------------------------------------------------------------------------------------------------------------------------------------------

int stack_check(my_stack* box)
{
    if(box -> data == NULL)
    {
        return ERR_NULL_DATA;
    }

    if(sizeof(box -> data[box -> counter - 1]) != sizeof(int))
    {
        return WRONG_INPUT;
    }

    if(box -> counter == -1)
    {
        return OUT_OF_STACK;
    }
    return STACK_IS_OKEY;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------

void stack_delete(my_stack* box)
{
    free(box -> data );
}
