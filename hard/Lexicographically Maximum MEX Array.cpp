class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>res;
        vector<queue<int>>dp(n+2);
        for(int i=0;i<n;i++)if(nums[i]<=n)dp[nums[i]].push(i);

        int in=0;
        while(in<n)
        {
            if(dp[0].empty() || dp[0].front()<in)
            {
                res.push_back(0);
                in++;
                continue;
            }
            int mx=0,r=in;
            while(mx<=n)
            {
                while(!dp[mx].empty() && dp[mx].front()<in)dp[mx].pop();
                if(dp[mx].empty()) break;
                r=max(r,dp[mx].front());
                mx++;
            }
            res.push_back(mx);
            while(in<=r)
            {
                if(nums[in] <= n && !dp[nums[in]].empty() && dp[nums[in]].front()==in)
                    dp[nums[in]].pop();
                in++;
            }
        }
        
        return res;
    }
};
