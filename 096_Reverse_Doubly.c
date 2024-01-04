#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


struct Node* reverseDoublyLinkedList(struct Node* head) {
    struct Node *temp = NULL, *current = head;

    while (current != NULL) {
       
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        
        current = current->prev;
    }


    if (temp != NULL) {
        head = temp->prev;
    }

    return head;
}


void displayList(struct Node* head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->prev = head;
    head->next->next = createNode(3);
    head->next->next->prev = head->next;

    printf("Doubly Linked List before reversal:\n");
    displayList(head);


    head = reverseDoublyLinkedList(head);

    printf("Doubly Linked List after reversal:\n");
    displayList(head);

    return 0;
}
