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

 // isme buus pop push hoga mark nhi krna 
class Solution {
public:

    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr!=NULL){
            ListNode* next = curr->next;
            curr->next = prev;

            prev  =curr;
            curr = next;
        }

        return prev;
        
    }    
    ListNode* removeNodes(ListNode* head) {

        ListNode* temp = head;

        stack<ListNode*> st;

        

        while(temp!=NULL){
            // pop (apne se chote) push
            while(st.size()> 0  && (st.top())->val < temp->val){
                st.pop();
            }
            st.push(temp);
            temp = temp->next;

    }

    ListNode* dummy = new ListNode(-1);

    ListNode* temp1 = dummy;

    while(st.size()>0){
        ListNode* top = st.top();
        st.pop();
        temp1->next = top;
        temp1= top;
    }

    temp1->next = NULL; // very very important
    return reverse(dummy->next);


    }
};