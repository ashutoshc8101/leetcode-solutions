class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return NULL;

        ListNode* fast = head->next->next;
        ListNode* slow = head->next;

        while (slow != fast) {
            if (fast == NULL || fast->next == NULL) return NULL;
            fast = fast->next->next;
            slow = slow->next;
        }

        while (head != slow) {
            head = head->next;
            slow = slow->next;
        }

        return slow;
    }
};