#if defined(DEBUG)
#define STACK_CHECK                                                                                       \
        if(stack_check(box) != STACK_IS_OKEY)                                                             \
        {FILE* print_fail = fopen("stack.txt", "a");                                                      \
                                                                                                          \
        fprintf(print_fail, "ERROR IN FILE %s, FUNCTION %s, LINE %d\n", __FILE__, __FUNCTION__, __LINE__);\
        fprintf(print_fail,"Current cell: %ld. Meaning of element: %d\n", box -> counter, box -> data[box -> counter]);                                                                                                   \
        fprintf(stderr, "Error of running program, check stack.txt! \007\n");                             \
                                                                                                          \
        exit(1) ;                                                                                         \
        fclose(print_fail);                                                                               \
        }                                                                                                 \

#else
#define PRINT_FAIL ;

#endif



