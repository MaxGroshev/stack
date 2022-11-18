#include "stack.h"

void add (stack_t* box)
{
    int summa = box->data[box->counter] + box->data[box->counter - 1];
    box->data[box->counter] = summa;
    STACK_CHECK
}

void mul (stack_t* box)
{
    int multip = box->data[box->counter] * box->data[box->counter - 1];
    box->data[box->counter] = multip;
    STACK_CHECK
}
