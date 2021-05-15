class Solution {
public:
    int summ=0;
    void util(TreeNode* root){
        if(root==nullptr) return;
        if(root->left!=nullptr && root->left->left==nullptr && root->left->right==nullptr){
            summ+=root->left->val;
        }
        util(root->left);
        util(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        summ=0;
        util(root);
        return summ;
    }
};
