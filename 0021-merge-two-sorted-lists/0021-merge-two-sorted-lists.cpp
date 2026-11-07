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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* i = list1;
        ListNode* j = list2;

        ListNode* dummy = new ListNode(-1);

        ListNode* k = dummy;

        while(i!=NULL and j!=NULL){
            if(i->val <= j->val){
                k->next = i; 
                k=k->next;
                i=i->next;   
            }
            else if(j->val < i->val){
                k->next = j;
                k=k->next;
                j=j->next;
            }
        }

    if(j==NULL){
        k->next = i;
    }

    if(i==NULL){
        k->next = j;
    }

      return dummy->next;  
    }
};



// Dono sorted LL ke liye i aur j pointers banao.
// Dummy node banao aur k ko us par rakho.
// Dono lists mein se jo value chhoti ho, use k->next se connect karo.
// Selected list ka pointer aage badhao.
// Jab koi ek list khatam ho jaaye, doosri list ko directly attach kar do.