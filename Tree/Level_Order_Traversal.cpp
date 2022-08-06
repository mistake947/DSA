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


    //
    class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> levels;
        level(root, 0, levels);
        return levels;
    }
private:
    void level(TreeNode* root, int l, vector<vector<int>>& levels) {
        if (!root) {
            return;
        }
        if (levels.size() <= l) {
            levels.push_back({});
        }
        levels[l].push_back(root -> val);
        level(root -> left, l + 1, levels);
        level(root -> right, l + 1, levels);
    }
};