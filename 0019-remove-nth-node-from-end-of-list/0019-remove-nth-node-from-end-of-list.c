#include <stdio.h>
#include <stdlib.h>

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (head == NULL || n <= 0) {
        return head;
    }
    
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    for (int i = 0; i < n; i++) {
        if (fast == NULL) {
            printf("N is larger than the list size.\n");
            return head;
        }
        fast = fast->next;
    }
    if (fast == NULL) {
        struct ListNode *todelete = head;
        head = head->next;
        free(todelete);
        return head;
    }
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    struct ListNode *todelete = slow->next;
    slow->next = slow->next->next;
    free(todelete);
    
    return head;
}