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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head->next == NULL) return head;

        ListNode* temp = head;

        int count = 0;
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }

        k = k % count;
        if(k == 0) return head;

        temp = head;

        for(int i = 1; i < count-k; i++) {
            temp = temp->next;
        }

        ListNode* a = temp;
        ListNode* newHead = temp->next;

        a->next = NULL;

        ListNode* b = newHead;

        while(b->next != NULL) {
            b = b->next;
        }

        b->next = head;

        return newHead;
    }
};