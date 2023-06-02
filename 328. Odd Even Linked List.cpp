/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return NULL;

        if (!head->next) return head;

        ListNode* oddStart = head;
        ListNode* evenStart = head->next;

        ListNode* temp1 = oddStart;
        ListNode* temp2 = evenStart;

        while (temp1->next && temp2->next) {
            ListNode* oddNext = temp2->next;
            ListNode* evenNext = oddNext->next;

            temp1->next = oddNext;
            temp2->next = evenNext;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        temp1->next = evenStart;

        return oddStart;
    }
};