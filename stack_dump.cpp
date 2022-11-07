#include "stack.h"

int stack_dump(stack_t* box, const char* DUR_FILE, const char* FUNCTION, int LINE)
{
    int print_stack = 0;
    int status = stack_check(box);
    FILE* print_fail = fopen("stack.txt", "a");
    if (status != 0)
    {
        fprintf(stderr, "Error of running program, check stack.txt! \007\n");
        fprintf(print_fail,"ERROR IN FILE %s, FUNCTION %s, LINE %d\n", DUR_FILE, FUNCTION, LINE);
        switch (status)
        {
            case OUT_OF_STACK:
                fprintf(print_fail,"ERROR: Request to cell thar does not belong to stack\n");
                fprintf(print_fail,"%3ld [%d]- Current cell is out of stack\n", box->counter, box->data[box->counter]);
                print_stack = 1;
                break;

            case WRONG_INPUT:
                fprintf(print_fail,"ERRO: Was input wrong data\n");
                print_stack = 1;
                break;

            case ERR_NULL_DATA:
                fprintf(print_fail,"ERROR: Memomy pointer point to NULL\n");
                break;
        }
    }

    for(int i = 0; i < box->capacity && print_stack == 1; i++)
    {
        if (i == box->counter)
        {
            fprintf(print_fail,"%3d [%d]- Current cell\n", i, box->data[i]);
            continue;
        }
        fprintf(print_fail,"%3d [%d]\n", i, box->data[i]);
    }
    fclose(print_fail);
    return status;
}

