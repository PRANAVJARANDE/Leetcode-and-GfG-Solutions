#define ll long long
class Solution {
  public:
    
    ll helper(ll l,ll r,ll k,vector<int>&a,vector<vector<int>>&dp)
    {
        ll sz=r-l+1;
        if(l>=r)return 0;
        
        if(dp[l][r]!=-1)return dp[l][r];
        
        ll cs=a[r];
        if(l-1>=0)cs-=a[l-1];
        
        
        // sz > k
        
        ll ans=INT_MAX;
        for(int m=l;m<r;m+=(k-1))
        {
            ll res=helper(l,m,k,a,dp)+helper(m+1,r,k,a,dp);
            ans=min(ans,res);
        }
        if((sz-1)%(k-1)==0)ans+=cs;
        return dp[l][r]=ans;
    }
  
    int mergeStones(vector<int> &a, int k) 
    {
        int n=a.size();
        if((n-1)%(k-1)!=0)return -1;
        
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=1;i<n;i++)a[i]+=a[i-1];
        
        return helper(0,n-1,k,a,dp);
        
    }
};
