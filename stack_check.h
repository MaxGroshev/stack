#if defined(DEBUG)
#define STACK_CHECK                                                                                       \
        {FILE* print_fail = fopen("stack.txt", "a");                                                      \
        fprintf(print_fail, "ERROR IN FILE %s, FUNCTION %s, LINE %d\n", __FILE__, __FUNCTION__, __LINE__);\
        fprintf(print_fail, "%d\n",box -> data[box -> counter - 1]);                                                                                                   \
        fprintf(stderr, "Error of running program, check stack.txt! \007\n");                             \
        exit(1) ;                                          \
        fclose(print_fail);                                                                               \
        }                                                                                                 \

#else
#define PRINT_FAIL ;

#endif



