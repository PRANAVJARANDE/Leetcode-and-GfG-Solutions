#define ll long long
class Solution {
  public:
    
    ll helper(ll l,ll r,vector<int>&a,vector<vector<int>>&dp)
    {
        if(l>=r)return INT_MAX;
        if(r-l==1)return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        ll ans=INT_MAX;
        for(int m=l+1;m<r;m++)
        {
            ll res=a[r]-a[l]+helper(l,m,a,dp)+helper(m,r,a,dp);
            ans=min(ans,res);
        }
        return dp[l][r]=ans;
    }
  
    int minCutCost(int n, vector<int>& cuts) 
    {
        sort(cuts.begin(),cuts.end());
        vector<int>a;
        a.push_back(0);
        for(auto x:cuts)a.push_back(x);
        a.push_back(n);
        ll sz=a.size();
        vector<vector<int>>dp(sz+1,vector<int>(sz+1,-1));
        ll ans=helper(0,sz-1,a,dp);
        return ans;
    }
};
