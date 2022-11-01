#if defined(DEBUG)
#define STACK_CHECK                                                                                       \
        do{                                                                                               \
        int fault = stack_check(box);                                                                     \
        if (fault != STACK_IS_OKEY)                                                                       \
        {                                                                                                 \
        FILE* print_fail = fopen("stack.txt", "a");                                                       \
        fprintf(print_fail,"ERROR IN FILE %s, FUNCTION %s, LINE %d, CODE OF ERROR %d\n", __FILE__, __FUNCTION__, __LINE__, fault); \
        fprintf(stderr, "Error of running program, check stack.txt! \007\n");                             \
        fclose(print_fail);                                                                               \
        stack_dump(box);                                                                                  \
        exit(1);                                                                                          \
        }                                                                                                 \
        } while(0);                                                                                       \

#else
#define PRINT_FAIL ;

#endif


