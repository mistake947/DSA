 vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<nums.size();i++)
        {
            while(!st.empty() and nums[st.top()]<nums[i])   //Greater Mai current elenment nums[i]
                                                             // ko greter rakhenge ,smaller hota to
                                                            //nums[i] ko small rakahte
            {
                int idx=st.top();
                st.pop();           // right ke liye yaha calculate hota hai
                ans[idx]=nums[i];
            }
            st.push(i);     // left k liye yaha calculate hota hai
        }
        return ans;