#if defined(DEBUG)
#define STACK_CHECK                                                                                       \
        do{ int fault = stack_check(box);                                                                 \
        if (fault != STACK_IS_OKEY)                                                                       \
        {                                                                                                 \
        FILE* print_fail = fopen("stack.txt", "a");                                                       \
                                                                                                          \
        fprintf(print_fail,"ERROR IN FILE %s, FUNCTION %s, LINE %d, CODE OF ERROR %d\n", __FILE__, __FUNCTION__, __LINE__, fault); \
        fprintf(print_fail,"Current cell: %ld. [%d]\n", box -> counter, box -> data[box -> counter]);\
        fprintf(print_fail,"Previous cell: %ld. Value of element: %d\n", box -> counter , box -> data[box -> counter]);\
        fprintf(stderr, "Error of running program, check stack.txt! \007\n");                             \
                                                                                                          \
        exit(1) ;                                                                                         \
        fclose(print_fail);                                                                               \
        }                                                                                                 \
        } while(0);                                                                                       \

#else
#define PRINT_FAIL ;

#endif


