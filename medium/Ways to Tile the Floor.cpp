#define ll long long
class Solution {
  public:
    
    ll dp[100001];
    const ll MOD=1e9+7;
    ll n,m;
    ll helper(ll in)
    {
        if(in==n)return 1;
        if(dp[in]!=-1)return dp[in];
        //horizontal
        ll op1=helper(in+1);
        ll op2=0;
        if(in+m<=n)op2=helper(in+m);
        return dp[in]=((op1%MOD)+(op2%MOD))%MOD;
    }

    int countWays(int n, int m) 
    {
        this->n=n;
        this->m=m;
        memset(dp,-1,sizeof(dp));
        return helper(0);
    }
};
