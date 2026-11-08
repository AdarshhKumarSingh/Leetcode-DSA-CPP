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


    ListNode*  reverse(ListNode*  head){
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr!=NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;

    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
    // reach the left  middle(even)
        while(fast->next!=NULL and fast->next->next!=NULL){
            slow=slow->next;
            fast = fast->next->next;
        }
        ListNode* a = head;
        ListNode* b = slow->next;
        slow->next=NULL;

        b = reverse(b);

        ListNode* t1=a;
        ListNode* t2=b;

        while(t2!=NULL and t1!=NULL){
            if(t1->val != t2->val) return false;
            t1=t1->next;
            t2=t2->next;
        }
        return true;



        
    }
};