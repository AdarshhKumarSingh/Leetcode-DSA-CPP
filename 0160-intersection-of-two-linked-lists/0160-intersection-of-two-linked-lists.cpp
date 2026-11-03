/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;

        int len1=0;
        while(a!=NULL){
            len1++;
            a=a->next;
        }
        a=headA;
        
        ListNode* b = headB;
        int len2=0;
        while(b!=NULL){
            len2++;
            b=b->next;
        }
        b = headB;

        int diff = abs(len1-len2);

        if(len1>len2){
            for(int i=0;i<diff;i++){
                a=a->next;
            }
        }else{
            for(int i=0;i<diff;i++){
                b=b->next;
            }
        }

        while(a!=b){
            a=a->next;
            b=b->next;
        }

        return a;


        
    }
};