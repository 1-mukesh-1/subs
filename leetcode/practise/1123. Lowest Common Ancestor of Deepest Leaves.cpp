class Solution {
public:
    TreeNode* lca(TreeNode* root,TreeNode* p,TreeNode* q){
        if(p==q){
            return p;
        }
        if(root==nullptr){
            return nullptr;
        }
        if(root==p || root==q) return root;
        TreeNode* left=lca(root->left,p,q);
        TreeNode* right=lca(root->right,p,q);
        if(left!=nullptr && right!=nullptr) return root;
        return left?left:right;
    }
    TreeNode* bfs(TreeNode* root){
        queue<TreeNode*> st;
        map<TreeNode*,int> dist;
        dist[root]=0;
        st.push(root);
        int maxi=INT_MIN;
        while(st.size()!=0){
            TreeNode* curr=st.front();
            st.pop();
            if(curr->left!=nullptr){
                st.push(curr->left);
                dist[curr->left]=dist[curr]+1;
                maxi=max(maxi,dist[curr->left]);
            }
            if(curr->right!=nullptr){
                st.push(curr->right);
                dist[curr->right]=dist[curr]+1;
                maxi=max(maxi,dist[curr->right]);
            }
        }
        vector<TreeNode*> leaves;
        for(auto x:dist){
            if(x.second==maxi){
                leaves.push_back(x.first);
            }
        }
        if(leaves.size()==0){
            return root;
        }
        if(leaves.size()==1){
            return leaves[0];
        }
        TreeNode* start=leaves[0];
        for(int i=0;i<leaves.size();i++){
            start=lca(root,start,leaves[i]);
        }
        return start;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        TreeNode* ans=bfs(root);
        // cout<<ans->val<<endl;
        return ans;
    }
};
