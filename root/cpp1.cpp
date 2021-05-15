

    bool isSymmetric(TreeNode* root)
    {
    vector<int>v;
    Inorder(root,v);
    int l;
    l=v.size()-1;
    for(int i=0;i<(l/2);i++)
    {
        if(v[i]!=v[l-i])
        {
            return false;
            break;
        }


    }

    return true;

    }

    vector<int> Inorder(TreeNode* root,vector<int> &v)
    {
         if(root==NULL)
            return;
        isSymmetric(root->left);
        v.push_back(root->val);
        isSymmetric(root->right);

        return v;

    }
