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
// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         ListNode* i = head;
//         ListNode* j = head;

//        while(j!=NULL){
//         if(i->val!=j->val){
//             i->next=j;
//             i=j;
//         }
//         j=j->next;
//        }
//        if (i != NULL) {
//             i->next = NULL;
//         }
//        return head;
//     }
// };



// Two pointers use karo: ek unique elements track karega aur doosra LL traverse karega.
// j se LL traverse karke har element ko check karo.
// Jab bhi koi naya unique element mile, use i ke next connect kar do.
// Duplicate elements ko skip karte jao.
// End mein last unique node ko NULL se connect kar do.



class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
       ListNode* i=head;
       ListNode* j=head;

       while(j!=NULL){
            if(i->val!=j->val){
                i->next=j;
                i=j;
            }
            j=j->next;
       }
       if(i!=NULL){
        i->next=NULL;
       }
       return head;
    }
};