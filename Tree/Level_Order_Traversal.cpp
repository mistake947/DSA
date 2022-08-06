vector<int> Level_Order(TreeNode* root) {
        if(!root) return {};
        vector<int>ans;
        queue<TreeNode* >q;
        q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
               TreeNode*  curr=q.front();
                q.pop();
                // if(i==sz-1)
                // ans.push_back(curr->val);
                //  Yaha kuch karna hai
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
        }
        return ans;
    }