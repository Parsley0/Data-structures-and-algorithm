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

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {  // A cycle exists
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;  // Return the node where the cycle begins
        }
    }
    return NULL;  // No cycle found
}

int main() {
    struct ListNode *head = NULL;
    addListNode(&head, createListNode(1));
    addListNode(&head, createListNode(0));
    addListNode(&head, createListNode(4));
    addListNode(&head, createListNode(3));
    head->next->next->next->next = head->next;

    struct ListNode *cycleStart = detectCycle(head);
    printf("Example : %s\n", cycleStart ? "Cycle begins at node with value: " : "No cycle");
    if (cycleStart) {
        printf("%d\n", cycleStart->val);
    }


    return 0;
}
