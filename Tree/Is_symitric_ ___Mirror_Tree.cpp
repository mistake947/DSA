bool isMirror(TreeNode* root1, TreeNode * root2)
    {
        if(! root1 and !root2) return true;
        else if(! root1 and root2) return false;
        else if(root1 and ! root2) return false;
        if(root1->val!= root2->val ) return false;
        return isMirror(root1->left ,root2->right) and isMirror(root1->right ,root2->left );
        
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isMirror(root->left,root->right);
        
    }