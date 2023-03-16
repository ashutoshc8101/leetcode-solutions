class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL;
        ListNode* temp = NULL;

        vector<ListNode*> indexes(lists.size());

        while (true) {
            int minVal = INT_MAX;
            int minIndex = -1;

            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] != nullptr && minVal > lists[i]->val) {
                    minVal = lists[i]->val;
                    minIndex = i;
                }
            }

            if (minIndex == -1) break;

            if (head == NULL) {
                head = new ListNode(minVal);
                temp = head;
            } else {
                temp->next = new ListNode(minVal);
                temp = temp->next;
            }

            lists[minIndex] = lists[minIndex]->next;
        }

        return head;
    }
};