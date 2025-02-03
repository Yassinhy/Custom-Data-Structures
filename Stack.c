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


// Example usage:
int main(void)
{
    // Create a stack with a capacity of 5
    Stack* stack = create_stack(5);
    if (stack == NULL) {
        printf("Failed to create stack.\n");
        return 1;
    }

    // Push some items onto the stack
    printf("Pushing items onto the stack:\n");
    for (int i = 1; i <= 5; i++) {
        if (push(stack, i * 10)) {
            printf("Failed to push item %d onto the stack.\n", i * 10);
        } else {
            printf("Pushed %d onto the stack.\n", i * 10);
        }
    }

    // Try to push another item onto the full stack
    if (push(stack, 60)) {
        printf("Failed to push 60 onto the stack (stack is full).\n");
    }

    // Peek at the top item
    int top_value;
    if (!peek(stack, &top_value)) {
        printf("Top item on the stack is: %d\n", top_value);
    } else {
        printf("Failed to peek at the top item (stack might be empty).\n");
    }

    // Pop items from the stack
    printf("Popping items from the stack:\n");
    while (!stack_is_empty(stack)) {
        int value;
        if (!pop(stack, &value)) {
            printf("Popped %d from the stack.\n", value);
        } else {
            printf("Failed to pop an item from the stack.\n");
        }
    }

    // Try to pop from an empty stack
    int value;
    if (pop(stack, &value)) {
        printf("Failed to pop from the stack (stack is empty).\n");
    }

    // Destroy the stack
    if (destroy_stack(stack)) {
        printf("Stack destroyed successfully.\n");
    } else {
        printf("Failed to destroy the stack.\n");
    }

    return 0;
}


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
