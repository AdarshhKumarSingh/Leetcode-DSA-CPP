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
    ListNode* partition(ListNode* head, int x) {
        ListNode* d1 = new ListNode(-1);
        ListNode* d2 = new ListNode(-1);
        ListNode* temp = head;

        ListNode* temp1=d1;
        ListNode* temp2=d2;

        while(temp!=NULL){
            if(temp->val<x){
                temp1->next = temp;
                temp1 = temp;
                
            }else if(temp->val >= x){
                temp2->next  = temp;
                temp2=temp;
            }
            temp=temp->next;
        }

    temp1->next =  NULL;
    temp2->next = NULL;

    temp1->next = d2->next;
    return d1->next;
        
    }
};