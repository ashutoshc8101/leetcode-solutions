class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;

        int length = 0;

        while (temp) {
            temp = temp->next;
            length++;
        }

        if (length == 0) return head;

        k = k % length;

        ListNode* fast = head;
        ListNode* slow = head;

        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }

        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        // cout << fast->val << " : " << slow->val << endl;
        fast->next = head;
        ListNode* returnVal = slow->next;
        slow->next = NULL;

        return returnVal;
    }
};