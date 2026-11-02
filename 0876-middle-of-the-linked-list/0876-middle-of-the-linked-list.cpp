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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        long long idx = 0;

        while(temp != NULL){
            idx++;
            temp = temp->next;  // Missing
        }

        temp = head;  // Reset temp to head

        for(int i=0; i<idx/2; i++){
            temp = temp->next;
        }

        return temp;
    }
};