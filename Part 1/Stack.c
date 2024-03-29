//
// Created by Assylkhanov Aslan on 28.08.2019.
//

#include <stdio.h>
#include "stack.h"

void setStackToFreshValues(Stack *stk) {
    stk->values = (int*) calloc(5, sizeof(int));
    stk->array_size = 5;
    stk->stack_size = 0;
}

Stack* create_stack() {
    Stack *stk = (Stack*) malloc(sizeof(Stack));
    setStackToFreshValues(stk);
}

// Destroys the stack, and frees up its memory
void destroy_stack(Stack *stk) {
    free(stk->values);
    free(stk);
}

// Adds the value val to the top of the stack
void push(Stack *stk, int val) {
    int indexToPut = stk->stack_size;
    if (indexToPut == stk->array_size) {
        int *newArray = calloc(stk->array_size * 2, sizeof(int));
        for (int i = 0; i < stk->array_size; ++i) {
            newArray[i] = stk->values[i];
        }
        free(stk->values);
        stk->values = newArray;
        stk->array_size *= 2;
    }
    stk->values[indexToPut] = val;
    stk->stack_size++;
}

// Removes and returns the topmost item of the stack
int pop(Stack *stk) {
    if (stk->stack_size == 0) {
        return -1;
    }
    int itemIndex = stk->stack_size - 1;
    int topItem = stk->values[itemIndex];
    stk->values[itemIndex] = 0;
    stk->stack_size--;
    return topItem;
}

// Returns the topmost item of the stack, without changing the stack
int peek_top(Stack *stk) {
    if (stk->stack_size == 0) {
        return -1;
    }
    int itemIndex = stk->stack_size - 1;
    int topItem = stk->values[itemIndex];
    return topItem;
}

// Returns the number of items on the stack
size_t stack_size(Stack *stk) {
    return stk->stack_size;
}

// Removes all of the items from the stack
void clear_stack(Stack *stk) {
    free(stk->values);
    setStackToFreshValues(stk);
}

// Outputs the items in the stack to the console window
void print_stack(Stack *stk) {
    int i;
    printf("Stack bottom [");
    for (i = 0; i < stk->stack_size; i++) {
        printf("%d ", stk->values[i]);
    }
    printf("\n");
}

