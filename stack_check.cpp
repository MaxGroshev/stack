#include "stack.h"

int stack_check(my_stack* box)
{
    if (box->data == NULL)
    {
        return ERR_NULL_DATA;
    }

    if (sizeof(box->data[box->counter - 1]) != sizeof(int))
    {
        return WRONG_INPUT;
    }

    if(box->counter == -1)
    {
        retur OUT_OF_STACK;
    }
    return STACK_IS_OKEY;
}
