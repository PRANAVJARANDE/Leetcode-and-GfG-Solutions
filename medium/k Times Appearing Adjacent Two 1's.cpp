#define ll long long
class Solution {
  public:
    
    const ll MOD=1e9+7;
    ll dp[1001][1001][2];
    ll n;
    ll helper(ll in,ll pv,ll k)
    {
        if(k<0)return 0;
        if(in>=n)
        {
            if(k==0)return 1;
            return 0;
        }
        if(dp[in][k][pv]!=-1)return dp[in][k][pv];
        //take 0
        ll op1=helper(in+1,0,k);
        // take 1
        ll op2=helper(in+1,1,(pv==1)? k-1 : k );
        return dp[in][k][pv]=( op1%MOD + op2%MOD )%MOD;
    }
  
    int countStrings(int n, int k) 
    {
        this->n=n;
        memset(dp,-1,sizeof(dp));
        
        return helper(0,0,k);
    }
};
