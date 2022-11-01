#pragma once
#define DEBUG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_check.h"

extern int num_of_elem; // was allowed by ded

//=================================================================================================================================

enum code_of_fails
{
    OUT_OF_STACK  = -3,
    WRONG_INPUT   = -2,
    ERR_NULL_DATA = -1,
    STACK_IS_OKEY =  0,
};

//---------------------------------------------------------------------------------------------------------------------------------

struct my_stack
{
    int*   data;
    size_t counter;
};

//-----------------------------------------------------------------------------------------------------------------------------------

void stack_init  (my_stack* box);
void stack_push  (my_stack* box, int element);
int  stack_pop   (my_stack* box);
int  stack_check (my_stack* box);
void stack_delete(my_stack* box);
void stack_dump  (my_stack* box);

