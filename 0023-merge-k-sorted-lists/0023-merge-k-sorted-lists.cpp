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
// // method 1
//     ListNode* mergeKLists(vector<ListNode*>& arr) {
//         if(arr.size()==0)return NULL;

//         while(arr.size()>1){
//             ListNode* a  =arr[arr.size()-1];
//             arr.pop_back();
//             ListNode* b = arr[arr.size()-1];
//             arr.pop_back();
//             ListNode* c = merge(a,b);
//             arr.push_back(c);
//         }

//         return arr[0];
        
//     }
// };


// Agar arr empty hai toh NULL return karo.
// Jab tak vector mein 1 se zyada linked lists hain:- Last list ko a mein nikalo.
// - Usse pehle wali list ko b mein nikalo.
// - merge(a,b) se dono sorted lists merge karo.
// - Merged list ko wapas vector mein push karo.

// Finally arr[0] return kar do.


//iski TC = O(k square hai)


// method 2

ListNode* mergeKLists(vector<ListNode*>& arr){
    if(arr.size()==0)return NULL;
    vector<ListNode*> temp;
    while(arr.size()+temp.size()>1){
    while(arr.size()>1){
        ListNode* a = arr[arr.size()-1];
        arr.pop_back();
        ListNode* b = arr[arr.size()-1];
        arr.pop_back();
        ListNode* c = merge(a,b);
        temp.push_back(c);
    }

    while(temp.size()>1){
        ListNode*  a = temp[temp.size()-1];
        temp.pop_back();
        ListNode* b =  temp[temp.size()-1];
        temp.pop_back();
        ListNode* c = merge(a,b);
        arr.push_back(c);
    }
    if(arr.size()==1 and temp.size()==1){
        temp.push_back(arr[0]);
        arr.pop_back();
    }
    }
    return(arr.size()!=0)?arr[0]:temp[0];

}
};
// TC = (log with (base 2) k * nk)