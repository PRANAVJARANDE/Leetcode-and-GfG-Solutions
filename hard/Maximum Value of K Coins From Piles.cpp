class Solution {
public:

    int helper(int in,int k,vector<vector<int>>&a,vector<vector<int>>&dp)
    {
        if(k==0 || in>=a.size())return 0;
        if(dp[in][k]!=-1)return dp[in][k];

        int ans=helper(in+1,k,a,dp);
        for(int i=0;i<min(k,(int)a[in].size());i++)
        {
            ans=max(ans,a[in][i]+helper(in+1,k-i-1,a,dp));
        }
        return dp[in][k]=ans;
    }

    int maxValueOfCoins(vector<vector<int>>& a, int k) 
    {
        for(auto &x:a)
        {
            for(int i=1;i<x.size();i++)
            {
                x[i]+=x[i-1];
            }
        }
        vector<vector<int>>dp((int)a.size(),vector<int>(k+1,-1));
        return helper(0,k,a,dp);
    }
};
