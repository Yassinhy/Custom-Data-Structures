#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct
{
    int *members;
    int length;
}Set;

// the prototypes:
Set* makeset ();
bool is_empty (Set* Set);
void insert (Set* set, int member);

// Example usage:
int main(void)
{
    // Create a new set
    Set* mySet = makeset();
    if (mySet == NULL) {
        printf("Failed to create set.\n");
        return 1;
    }

    // Check if the set is empty
    if (is_empty(mySet)) {
        printf("The set is empty.\n");
    } else {
        printf("The set is not empty.\n");
    }

    // Insert elements into the set
    printf("Inserting elements into the set:\n");
    int elements[] = {10, 20, 30, 20, 40}; // Note: 20 is duplicated
    for (int i = 0; i < 5; i++) {
        if (insert(mySet, elements[i])) {
            printf("Failed to insert %d (may already exist or memory allocation failed).\n", elements[i]);
        } else {
            printf("Inserted %d into the set.\n", elements[i]);
        }
    }

    // Check if the set is empty after insertion
    if (is_empty(mySet)) {
        printf("The set is empty.\n");
    } else {
        printf("The set is not empty.\n");
    }

    // Print the contents of the set
    printf("Contents of the set:\n");
    for (int i = 0; i < mySet->length; i++) {
        printf("%d ", mySet->members[i]);
    }
    printf("\n");

    // Try to insert an element that already exists
    if (insert(mySet, 10)) {
        printf("Failed to insert 10 (element already exists).\n");
    } else {
        printf("Inserted 10 into the set.\n");
    }

    // Free the set (not implemented in the provided code)
    // You should add a function to free the memory allocated for the set
    free(mySet->members);
    free(mySet);
    printf("Set destroyed successfully.\n");

    return 0;
}

// create a set function
Set* makeset ()
{
    Set* new_set = malloc(sizeof(Set));
    new_set -> length = 0;
    new_set -> members = NULL;
    return new_set;
}

//check if a set is empty
bool is_empty (Set* Set)
{
    return(Set -> length == 0);
}

//add a new element to a set
/*
returns false is successful

returns true in element already in the set or memory reallocation failed
*/
bool insert (Set* set, int member)
{
    for (int i = 0; i < set->length; i++)
    {
        if (set->members[i] == member)
        {
            return true;
        }
    }
    int *temp = realloc (set->members, sizeof(int) * (set->length + 1));
    if (temp == NULL){
    printf("Memory reallocation was unsuccessful\n");
    return true;
    }
    set->members = temp;
    set->members[set->length] = member; 
    set->length = set->length + 1;
    return false;
}
