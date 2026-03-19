class Solution {
public:

    const int MOD=1e9+7;
    int limit;
    int helper(int zc,int oc,int tk,vector<vector<vector<int>>>&dp)
    {
        if(zc==0 && oc==0)return 1;
        if(zc<0 || oc<0)return 0;
       
        if(dp[zc][oc][tk]!=-1)return dp[zc][oc][tk];
        int ans=0;
        if(tk==0)
        {
            ans=((ans%MOD)+(helper(zc-1,oc,0,dp)%MOD)+(helper(zc-1,oc,1,dp)%MOD))%MOD;
            if(zc-1-limit>=0)ans=((ans%MOD)-(helper(zc-1-limit,oc,1,dp)%MOD)+MOD)%MOD;
        }
        else
        {
            ans=((ans%MOD)+(helper(zc,oc-1,0,dp)%MOD)+(helper(zc,oc-1,1,dp)%MOD))%MOD;
            if(oc-1-limit>=0)ans=((ans%MOD)-(helper(zc,oc-1-limit,0,dp)%MOD)+MOD)%MOD;
        }
        return dp[zc][oc][tk]=ans;
    }

    int numberOfStableArrays(int zc, int oc, int l) 
    {
        limit=l;
        vector<vector<vector<int>>>dp(zc+1,vector<vector<int>>(oc+1,vector<int>(2,-1)));
        for(int i=1;i<=min(zc,limit);i++)dp[i][0][0]=1;
        for(int j=1;j<=min(oc,limit);j++)dp[0][j][1]=1;

        int ans=(helper(zc,oc,0,dp)%MOD+helper(zc,oc,1,dp)%MOD)%MOD;
        return ans;
    }
};
