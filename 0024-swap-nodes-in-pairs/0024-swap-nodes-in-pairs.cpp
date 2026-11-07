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
    
    ListNode* swapPairs(ListNode* head) {

        if(head == NULL || head->next == NULL) return head;
        
        ListNode* odd  =  new ListNode(-1);
        ListNode* even = new ListNode(-1);


        ListNode* temp = head;
        ListNode* temp1=odd;
        ListNode* temp2=even;


        int idx = 1;
        while(temp!=NULL){
            if(idx%2 == 1){
                temp1->next = temp;
                temp1=temp;
            }else{
                temp2->next = temp;
                temp2=temp;
            }
            temp=temp->next;
            idx++;
        }
        
        ListNode* i = even->next;
        ListNode* j = odd->next;

        ListNode* dummy = new ListNode(-1);
        ListNode* k = dummy;

        while(i!=NULL and j!=NULL){
            k->next=i;
            k=i;
            i = i->next;

            k->next = j;
            k=j;
            j=j->next;
        }

        k->next = i;

        return dummy->next;
             
        
    }
};