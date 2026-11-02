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

//  // Method 1 (Brute force approach)
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         ListNode* temp = head;
//         long long idx = 0;

//         while(temp != NULL){
//             idx++;
//             temp = temp->next; 
//         }

//         temp = head;  // Reset temp to head

//         for(int i=0; i<idx/2; i++){
//             temp = temp->next;
//         }

//         return temp;
//     }
// };



// method 2(slow fast approach)
class Solution {
public:
    ListNode* middleNode(ListNode* head){
        ListNode* slow=head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast = fast->next->next;
        }
        return slow;

    }
};