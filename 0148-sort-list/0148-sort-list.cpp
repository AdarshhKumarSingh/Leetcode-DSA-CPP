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

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        ListNode* i = list1;
        ListNode* j = list2;

        ListNode* dummy = new ListNode(-1);

        ListNode* k = dummy;


        while(i!=NULL and j!=NULL){
            if(i->val>=j->val){
                k->next =  j;
                k=k->next;
                j=j->next;
            }else{
                k->next = i;
                k=k->next;
                i=i->next;
            }
        }

        if(i==NULL){
            k->next=j;
        }

        if(j==NULL){
            k->next= i;
        }

        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {

    if(head == NULL || head->next == NULL) return head;

    ListNode* temp = head;

    int length = 0;

    while(temp != NULL) {
        length++;
        temp = temp->next;
    }

    temp = head;

    for(int i = 1; i < length/2; i++) {
        temp = temp->next;
    }

    ListNode* newn = temp->next;
    temp->next = NULL;

    ListNode* temp1 = sortList(head);
    ListNode* temp2 = sortList(newn);

    return mergeTwoLists(temp1, temp2);
}
};