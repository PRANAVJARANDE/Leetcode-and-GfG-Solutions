#define ll long long
class Solution {
public:

    const int MOD=1E9+7;
    int helper(int in,int mask,vector<vector<int>>&col,vector<vector<int>>&dp)
    {
        if(mask==0)return 1;
        if(in>=40)return 0;
        if(dp[in][mask]!=-1)return dp[in][mask];

        int ans=helper(in+1,mask,col,dp)%MOD;
        for(auto x:col[in])
        {
            if(mask & (1<<x))
            {
                ans=((ans%MOD)+(helper(in+1,mask ^ (1ll<<x),col,dp)%MOD))%MOD;
            }
        }
        return dp[in][mask]=ans%MOD;
    }

    int numberWays(vector<vector<int>>& hats) 
    {
        int n=hats.size(); 
        vector<vector<int>>col(40);
        for(int i=0;i<n;i++)for(auto x:hats[i])col[x-1].push_back(i);
        vector<vector<int>>dp(40,vector<int>((1<<n),-1));
        return helper(0,(1<<n)-1,col,dp);   
    }
};
