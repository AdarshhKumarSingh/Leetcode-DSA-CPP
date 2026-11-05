/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//  // Method 1
// //  Right subtree ko invert() karke mirror bana do.
// // isSameTree() se left aur inverted right subtree compare karo.
// // Dono same hain toh tree symmetric hai, otherwise nahi.
// class Solution {
// public:
//     void invert(TreeNode* root){
//         if(root==NULL)return;
//         TreeNode* temp = root->left;
//         root->left = root->right;
//         root->right = temp;
//         invert(root->left);
//         invert(root->right);

//     }
//     bool isSameTree(TreeNode*p , TreeNode* q){
//         if(p==NULL and q==NULL){
//             return true;
//         }
//         if(p==NULL or q==NULL){
//             return false;
//         }
//         if(p->val!=q->val){
//             return false;
//         }
//         return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
//     }
//     bool isSymmetric(TreeNode* root) {
//         invert(root->right);
//         return isSameTree(root->left,root->right);
        
//     }
// };





//  Method 2

class Solution{
    public:
    bool isInvert(TreeNode* p,TreeNode* q){
        if(p==NULL and q==NULL) {
            return true;
        }
        if(p==NULL or q==NULL){
            return false;    
        }
        if(p->val!=q->val){
            return false;
        }
        return isInvert(p->left,q->right) && isInvert(p->right,q->left);
    }

     bool isSymmetric(TreeNode* root){
        if(root==NULL){
            return true;
        }
        return isInvert(root->left,root->right);

     }

};