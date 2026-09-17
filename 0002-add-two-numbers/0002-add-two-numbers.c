#include <stdio.h>
#include <stdlib.h>


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // Create a dummy node to anchor the beginning of the result list
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = NULL;

    struct ListNode* current = &dummy;
    int carry = 0;

    // Traverse both lists as long as nodes or carry remain
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int val1 = (l1 != NULL) ? l1->val : 0;
        int val2 = (l2 != NULL) ? l2->val : 0;

        int sum = val1 + val2 + carry;
        carry = sum / 10;

        // Allocate memory for the new node in the result list
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;

        current->next = newNode;
        current = current->next;

        // Advance pointers if nodes exist
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    return dummy.next;
}