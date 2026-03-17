class Solution {
public:

    const int MOD=1e9+7;

    int limit;
    int helper(int zc,int oc,int pv,vector<vector<vector<int>>>&dp)
    {
        if(zc==0)
        {
            if(oc>limit)return 0;
            return 1;
        }
        if(oc==0)
        {
            if(zc>limit)return 0;
            return 1;
        }
        if(dp[zc][oc][pv]!=-1)return dp[zc][oc][pv];
        int ans=0;
        if(pv==0 || pv==2)
        {
            for(int c=1;c<=min(oc,limit);c++)ans=((ans%MOD)+(helper(zc,oc-c,1,dp)%MOD))%MOD;
        }

        if(pv==1 || pv==2)
        {
            for(int c=1;c<=min(zc,limit);c++)ans=((ans%MOD)+(helper(zc-c,oc,0,dp)%MOD))%MOD;
        }
        return dp[zc][oc][pv]=ans;
    }

    int numberOfStableArrays(int zc, int oc, int l) 
    {
        limit=l;
        vector<vector<vector<int>>>dp(zc+1,vector<vector<int>>(oc+1,vector<int>(3,-1)));
        int ans=helper(zc,oc,2,dp);
        return ans;
    }
};
