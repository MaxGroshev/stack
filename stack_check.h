#if defined(DEBUG)
#define STACK_CHECK                                                                                       \
        do{                                                                                               \
        if (stack_dump(box,__FILE__, __FUNCTION__, __LINE__) != STACK_IS_OKEY)                                                                       \
        {                                                                                                 \
        exit(1);                                                                                          \
        }                                                                                                 \
        } while(0);                                                                                       \

#else
#define PRINT_FAIL ;

#endif
