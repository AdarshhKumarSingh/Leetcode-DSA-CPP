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
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;

        if(root->left == NULL && root->right == NULL) {
            return (sum == root->val);
        }

        return hasPathSum(root->left, sum - root->val) ||
               hasPathSum(root->right, sum - root->val);
    }
};

// Agar root NULL hai toh false return karo.
// Check karo ki current node leaf node hai ya nahi (dono children NULL).
// Agar leaf node hai toh sum == root->val check karo.
// Current node ki value sum se subtract karke left aur right subtree mein recursively search karo.
// Kisi bhi ek path ka sum match hua toh true.