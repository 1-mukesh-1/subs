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
    int util(TreeNode* root){
        if(root==nullptr) return 0;
        if(root->left==nullptr){
            return 1+util(root->right);
        }
        if(root->right==nullptr){
            return 1+util(root->left);
        }
        return 1+min(util(root->left),util(root->right));
    }
    int minDepth(TreeNode* root) {
        return util(root);
    }
};
