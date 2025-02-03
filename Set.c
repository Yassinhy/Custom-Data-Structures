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
