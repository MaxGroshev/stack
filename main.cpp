#include "stack.h"

int main()
{
    struct my_stack box = {};
    int num_of_elem = 0;
    stack_init(&box);

    printf("Please input amount of elements \n");
    scanf("%d", &num_of_elem);
    for(int i = 0; i < num_of_elem; i++)
    {
        stack_push(&box, i);
    }

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

    /*if(stack_check(box) != STACK_IS_OKEY)*/  STACK_CHECK
}

//-------------------------------------------------------------------------------------------------------------------------------------------

void stack_push(my_stack* box, int element)
{
    /*if(stack_check(box) != STACK_IS_OKEY)*/   STACK_CHECK


    box -> data = (int*) realloc(box -> data, (box -> counter + 1) * sizeof(int));
    box -> data[box -> counter++] = element;

    /*if(stack_check(box) != STACK_IS_OKEY)*/   STACK_CHECK
}

//----------------------------------------------------------------------------------------------------------------------------------------------

int stack_pop(my_stack* box)
{
    box -> counter--;

    /*if(stack_check(box) != STACK_IS_OKEY)*/   STACK_CHECK

    return box -> data[box -> counter];
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
