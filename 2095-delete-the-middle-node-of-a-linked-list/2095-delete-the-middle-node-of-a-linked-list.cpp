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
ListNode* deleteMiddle(ListNode* head) {


  if(head->next==NULL) return NULL;

  ListNode* temp=head;
  int length = 0;

  while(temp!=NULL){
    length++;
    temp=temp->next;
  }

  temp=head;

  for(int i=0;i<length/2-1;i++){
    temp=temp->next;
  }

  ListNode* dele = temp->next;
  temp->next = temp->next->next;
  delete dele;

  return head;
}


};
