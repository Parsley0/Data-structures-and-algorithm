#include <stdio.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *createListNode(int val) {
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void addListNode(struct ListNode **head, struct ListNode *node) {
    node->next = *head;
    *head = node;
}

bool hasCycle(struct ListNode *head) {
    struct ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {  // A cycle exists
            return true;
        }
    }
    return false;  // No cycle found
}

int main() {
    struct ListNode *head = NULL;

    addListNode(&head, createListNode(1));
    addListNode(&head, createListNode(2));
    addListNode(&head, createListNode(3));
    addListNode(&head, createListNode(4));
    head->next->next->next->next = head->next;

    printf("Example : %s\n", hasCycle(head) ? "True" : "False");

    return 0;
}
