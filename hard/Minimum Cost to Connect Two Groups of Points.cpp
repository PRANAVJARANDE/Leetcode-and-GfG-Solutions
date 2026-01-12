#define ll long long
class Solution {
public:

    ll n,m;
    ll helper(ll in,ll mask,vector<vector<int>>&a,vector<vector<ll>>&dp,vector<int>&mini)
    {   
        if(in>=n)
        {
            ll res=0;
            for(int j=0;j<m;j++)if(!(mask & (1ll<<j)))res+=mini[j];
            return res;
        }

        if(dp[in][mask]!=-1)return dp[in][mask];

        ll ans=INT_MAX;
        for(int j=0;j<m;j++)
        {
            ll res=a[in][j]+helper(in+1,mask | (1<<j),a,dp,mini);
            ans=min(ans,res);
        }
        return dp[in][mask]=ans;
    }

    int connectTwoGroups(vector<vector<int>>& a) 
    {
        n=a.size();
        m=a[0].size();
        ll mx=(1ll<<m);
        vector<int>mini(m,INT_MAX);
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)mini[j]=min(mini[j],a[i][j]);
        vector<vector<ll>>dp(n,vector<ll>(mx,-1));
        return helper(0,0,a,dp,mini);
    }
};
