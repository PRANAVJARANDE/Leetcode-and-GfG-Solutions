class Solution {
public:

    /*
        2 5 6 8
        segments:
        0 2
        3 5
        6 9

    
    */

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) 
    {
        vector<int>st,en;
        for(int i=0;i<n;)
        {
            int l=i;
            i++;
            while(i<n && abs(nums[i-1]-nums[i])<=maxDiff)
            {
                i++;
            }
            st.push_back(l);
            en.push_back(i-1);
        }

        vector<bool>ans;
        for(auto x:queries)
        {
            int l=min(x[1],x[0]);
            int r=max(x[1],x[0]);

            auto in=upper_bound(st.begin(),st.end(),l)-st.begin()-1;
            if(r<=en[in])ans.push_back(1);
            else ans.push_back(0);
        }
        return ans;
    }
};
