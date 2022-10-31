#include "stack.h"

void stack_init(my_stack* box)
{
    box->counter = 0;
    box->data = (int*)calloc(box->counter, sizeof(int));

    STACK_CHECK
}

//-------------------------------------------------------------------------------------------------------------------------------------------

void stack_push(my_stack* box, int element)
{
    STACK_CHECK

    box->data = (int*) realloc(box->data, (box->counter + 1) * sizeof(int));
    box->data[box->counter++] = element;

    STACK_CHECK
}

//----------------------------------------------------------------------------------------------------------------------------------------------

int stack_pop(my_stack* box)
{
    box->counter--;

    STACK_CHECK

    return box->data[box->counter];
}

//-----------------------------------------------------------------------------------------------------------------------------------------------

void stack_delete(my_stack* box)
{
    free(box->data);
}
