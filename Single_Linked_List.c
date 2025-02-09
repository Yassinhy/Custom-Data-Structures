#include <stdio.h>
#include <stdlib.h>

// Define the MyLinkedList structure
typedef struct MyLinkedList {
    int value;
    struct MyLinkedList *next;
} MyLinkedList;

// Function prototypes
MyLinkedList* myLinkedListCreate();
int myLinkedListGet(MyLinkedList* obj, int index);
void myLinkedListAddAtHead(MyLinkedList* obj, int val);
void myLinkedListAddAtTail(MyLinkedList* obj, int val);
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val);
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index);
void myLinkedListFree(MyLinkedList* obj);

int main() {
    // Create a new linked list
    MyLinkedList* list = myLinkedListCreate();
    if (list == NULL) {
        printf("Failed to create linked list.\n");
        return 1;
    }

    // Add elements at the head
    myLinkedListAddAtHead(list, 10);
    myLinkedListAddAtHead(list, 20);
    myLinkedListAddAtHead(list, 30);

    // Add elements at the tail
    myLinkedListAddAtTail(list, 40);
    myLinkedListAddAtTail(list, 50);

    // Add an element at a specific index
    myLinkedListAddAtIndex(list, 2, 25);  // Adds 25 at index 2

    // Print the linked list
    printf("Linked List after additions:\n");
    for (int i = 0; i < 6; i++) {
        printf("Index %d: %d\n", i, myLinkedListGet(list, i));
    }

    // Delete an element at a specific index
    myLinkedListDeleteAtIndex(list, 3);  // Deletes element at index 3

    // Print the linked list after deletion
    printf("\nLinked List after deletion at index 3:\n");
    for (int i = 0; i < 5; i++) {
        printf("Index %d: %d\n", i, myLinkedListGet(list, i));
    }

    // Free the linked list
    myLinkedListFree(list);

    return 0;
}

// Implement the linked list functions here (as provided in your original code)
MyLinkedList* myLinkedListCreate() {
    MyLinkedList *dummy = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    if (dummy == NULL) return NULL;
    dummy -> next = NULL;
    return dummy;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0) return -1;
    MyLinkedList *curr = obj -> next; 
    for (int i = 0; i < index; i++)
    {
        if (curr == NULL) return -1;
        curr = curr -> next;
    }
    if (curr == NULL) return -1;
    return curr -> value;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList *New_Node = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    if (!New_Node) return;
    New_Node -> value = val;
    New_Node -> next = obj -> next;
    obj -> next = New_Node;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList* new = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    new -> value = val;
    new -> next = NULL;

    MyLinkedList* tmp = obj;

    while (tmp -> next != NULL)
    {
        tmp = tmp -> next;
    }

    tmp -> next = new;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0) return;
    MyLinkedList *tmp = obj;
    int i = 0;
    while (i < index)
    {
        if (!tmp -> next) return;
        tmp = tmp -> next;
        i++;
    }
    if (!tmp) return;
    MyLinkedList *New_Node = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    if (!New_Node) return;

    New_Node -> value = val;
    New_Node -> next = tmp -> next;
    tmp -> next = New_Node;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || !obj->next) return;

    MyLinkedList *tmp = obj;

    for (int i = 0; i < index; i++)
    {
        if (!tmp -> next) return;
        tmp = tmp -> next;
    }
    if (!tmp -> next) return;
    MyLinkedList *tmp2 = tmp -> next;
    tmp -> next = tmp2 -> next;
    free(tmp2);
}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList *tmp = obj, *next;
    while (tmp != NULL)
    {
        next = tmp -> next;
        free(tmp);
        tmp = next;
    }
}
