#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int capacity; // max number of items that can be stored
    char* collection; // array of the chars that are currently stacked
    int size; // number of items stored
} Stack;

// Prototypes:
Stack* create_stack(int capacity);
bool destroy_stack(Stack* stack);
bool stack_is_full(Stack* stack);
bool stack_is_empty(Stack* stack);
bool pop(Stack* stack, char* value);
bool push(Stack* stack, char item);
bool peek(Stack* stack, char* value);

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
    for (char c = 'A'; c <= 'E'; c++) {
        if (push(stack, c)) {
            printf("Failed to push item %c onto the stack.\n", c);
        } else {
            printf("Pushed %c onto the stack.\n", c);
        }
    }

    // Try to push another item onto the full stack
    if (push(stack, 'F')) {
        printf("Failed to push F onto the stack (stack is full).\n");
    }

    // Peek at the top item
    char top_value;
    if (!peek(stack, &top_value)) {
        printf("Top item on the stack is: %c\n", top_value);
    } else {
        printf("Failed to peek at the top item (stack might be empty).\n");
    }

    // Pop items from the stack
    printf("Popping items from the stack:\n");
    while (!stack_is_empty(stack)) {
        char value;
        if (!pop(stack, &value)) {
            printf("Popped %c from the stack.\n", value);
        } else {
            printf("Failed to pop an item from the stack.\n");
        }
    }

    // Try to pop from an empty stack
    char value;
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

// Create a stack with input capacity
Stack* create_stack(int capacity)
{
    if (capacity <= 0)
    {
        return NULL;
    }

    Stack* stack = malloc(sizeof(Stack));
    if (stack == NULL)
    {
        return NULL;
    }
    stack->capacity = capacity;
    stack->size = 0;
    stack->collection = malloc(capacity * sizeof(char));
    if (stack->collection == NULL)
    {
        free(stack);
        return NULL;
    }
    return stack;
}

// Correctly free a stack
bool destroy_stack(Stack* stack)
{
    if (stack == NULL) {
        return false;
    }
    free(stack->collection);
    free(stack);
    return true;
}

// Check if a stack is full
bool stack_is_full(Stack* stack)
{
    return stack->size == stack->capacity;
}

// Check if a stack is empty
bool stack_is_empty(Stack* stack)
{
    return stack->size == 0;
}

// Remove an item from the stack and store it in the "value" pointer
// Returns true if failed to pop
bool pop(Stack* stack, char* value)
{
    if (stack_is_empty(stack)) return true;
    stack->size--;
    *value = stack->collection[stack->size];
    return false;
}

// Add an item to a stack
bool push(Stack* stack, char item)
{
    if (stack_is_full(stack)) return true;
    stack->collection[stack->size] = item;
    stack->size++;
    return false;
}

// See what is on the top of the stack
bool peek(Stack* stack, char* value)
{
    if (stack_is_empty(stack)) return true;
    *value = stack->collection[stack->size - 1];
    return false;
}
