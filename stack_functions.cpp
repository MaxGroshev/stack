#include "stack.h"

void stack_init(stack_t* box, size_t capacity)
{
    box->data = (type_of_elem*)calloc(box->capacity, sizeof(type_of_elem));

    STACK_CHECK
}

//-------------------------------------------------------------------------------------------------------------------------------------------

void stack_push(stack_t* box, type_of_elem element)
{
    STACK_CHECK

    if (box->capacity - box->counter <= 10)
    {
        //int* stack_resize = box->data;
        if (box->counter - box->capacity <= 10)
        {
            STACK_CHECK
            box->data = (int*)realloc(box->data, (box->counter + 1) * sizeof(type_of_elem)); // nullptr
        }
       // free(stack_resize);
    }

    box->data[box->counter++] = element;

    STACK_CHECK
}

//----------------------------------------------------------------------------------------------------------------------------------------------

int stack_pop(stack_t* box)
{
    box->counter--;

    STACK_CHECK

    return box->data[box->counter];
}

//-----------------------------------------------------------------------------------------------------------------------------------------------

void stack_delete(stack_t* box)
{
    free(box->data);
}

