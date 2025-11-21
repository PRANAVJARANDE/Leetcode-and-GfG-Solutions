class Solution {
public:

    vector<vector<int>>pat;
    void build(vector<int>&v1)
    {
        if(v1.size()>=3)
        {
            pat.push_back(v1);
            return;
        }
        for(int i=0;i<3;i++)
        {
            if(!v1.empty() && v1.back()==i)continue;
            v1.push_back(i);
            build(v1);
            v1.pop_back();
        }
    }

    const int MOD=1e9 + 7;
    int helper(int in,int p1,int p2,int p3,int n,vector<vector<vector<vector<int>>>>&dp)
    {
        if(in>=n)return 1;
        if(dp[in][p1][p2][p3]!=-1)return dp[in][p1][p2][p3];
        int ans=0;
        for(auto x:pat)
        {
            if(x[0]==p1 || x[1]==p2 || x[2]==p3)continue;
            ans=((ans%MOD)+(helper(in+1,x[0],x[1],x[2],n,dp)%MOD))%MOD;
        }
        return dp[in][p1][p2][p3]=ans%MOD;
    }

    int numOfWays(int n) 
    {
        vector<int>v1;
        build(v1);
        vector<vector<vector<vector<int>>>>dp(n,vector<vector<vector<int>>>(4,vector<vector<int>>(4,vector<int>(4,-1))));
        int ans=helper(0,3,3,3,n,dp);
        return ans;
    }
};
