#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int capacity; // max number of items that can be stored
    int* collection; // array of the integers that are currently stacked (can be any data type)
    int size; // number of  items stored

}Stack;

//Prototypes:
Stack* create_stack (int capacity);
bool destroy_stack (Stack* stack);
bool stack_is_full (Stack *stack);
bool stack_is_empty (Stack *stack);
bool pop (Stack *stack, int *value);
bool push (Stack *stack, int item);
bool peek (Stack* stack, int *value);

// create a stack with input capacity
Stack* create_stack (int capacity)
{
    if (capacity <= 0)
    {
        return NULL;
    }

    Stack *stack = malloc(sizeof(Stack));
    if (stack  == NULL)
    {
        return NULL;
    }
    stack -> capacity = capacity;
    stack -> size = 0;
    stack -> collection = malloc(sizeof(int) * capacity);
    if (stack -> collection == NULL)
    {
        free(stack);
        return NULL;
    }
    return stack;
    
}

// correctly free a stack
bool destroy_stack (Stack* stack)
{
    free(stack -> collection);
    free(stack);
}

// check if a stack is full
bool stack_is_full (Stack *stack)
{
    if (stack -> size == stack -> capacity)
    {
        return true;
    }
    return false;
}

// check if a stack is empty
bool stack_is_empty (Stack *stack)
{
    if (stack -> size == 0)
    {
        return true;
    }
    return false;
}

// remove a book out of the stack and store it in the "value" pointer
//returns true if failed to pop
bool pop (Stack *stack, int *value)
{
    if (stack_is_empty (stack))  return true;
    stack -> size--; 
    *value = stack -> collection[stack -> size];
    return false;
}

// add an item to a stack
bool push (Stack *stack, int item)
{
    if (stack_is_full (stack))  return true;
    stack -> collection[stack -> size] = item;
    stack -> size++;
    return false;
}

// see what is on the top of the stack
bool peek (Stack* stack, int *value)
{
    if (stack_is_full (stack))  return true;
    *value = stack -> collection[stack -> size--];
}
