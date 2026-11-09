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
    ListNode* merge(ListNode* a,ListNode* b){
        ListNode* i = a;
        ListNode* j = b;

        ListNode* dummy = new  ListNode(-1);

        ListNode* k = dummy;

        while(i!=NULL and j!=NULL){
            if(i->val<=j->val){
                k->next = i;
                k=k->next;
                i=i->next;
            }else{
                k->next = j;
                k=k->next;
                j=j->next;
            }
        }
            if(i==NULL){
                k->next = j;
            }

            if(j==NULL){
                k->next = i ;
            }
            
        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& arr) {
        if(arr.size()==0)return NULL;
        
        while(arr.size()>1){
            ListNode* a  =arr[arr.size()-1];
            arr.pop_back();
            ListNode* b = arr[arr.size()-1];
            arr.pop_back();
            ListNode* c = merge(a,b);
            arr.push_back(c);
        }

        return arr[0];


        
    }
};