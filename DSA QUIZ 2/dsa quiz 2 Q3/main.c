#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to reverse a linked list
struct Node* reverseList(struct Node* head) {
    struct Node *prev, *curr, *next_node;
    prev = NULL;
    curr = head;

    // Iterate through the linked list
    while (curr != NULL) {
        // Store the next node
        next_node = curr->next;

        // Update the next pointer of the current node
        curr->next = prev;

        // Move to the next pair of nodes
        prev = curr;
        curr = next_node;
    }

    // Return the new head of the reversed list
    return prev;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to test the reverseList function
int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> NULL
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 2;
    head->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->data = 3;
    head->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->next->data = 4;
    head->next->next->next->next = NULL;

    // Print the original linked list
    printf("Original Linked List: ");
    printList(head);


    head = reverseList(head);

    // Print the reversed linked list
    printf("Reversed Linked List: ");
    printList(head);

    return 0;
}
