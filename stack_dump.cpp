#include "stack.h"

void stack_dump(my_stack* box)
{
    FILE* print_fail = fopen("stack.txt", "a");

    if (box->counter == -1)
    {
        fprintf(print_fail,"%3ld [%d]- Current cell is out of stack\n", box->counter, box -> data[box->counter]);
    }
    for(int i = 0; i < num_of_elem; i++)
    {
        if (i == box->counter)
        {
            fprintf(print_fail,"%3d [%d]- Current cell\n", i, box -> data[i]);
            continue;
        }
        fprintf(print_fail,"%3d [%d]\n", i, box -> data[i]);
    }
    fclose(print_fail);
}

