class Solution {
public:
    unordered_map<int, int> ump;
    int index = 0;
    Solution(ListNode* head) {
        ListNode* temp = head;
        while (temp) {
            ump[index++] = temp->val;
            temp = temp->next;
        }
    }

    int getRandom() {
        return ump[rand() % (index)];
    }
};
