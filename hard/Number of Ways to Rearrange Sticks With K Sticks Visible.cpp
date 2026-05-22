#define ll long long
class Solution {
public:

    const ll MOD=1E9+7;
    ll helper(ll n,ll k,vector<vector<ll>>&dp)
    {
        if(k>n || k==0)return 0;
        if(n<=2)return 1;
        if(dp[n][k]!=-1)return dp[n][k];
        //take
        ll op1=helper(n-1,k-1,dp)%MOD;
        //ntake
        ll op2=(((n-1)%MOD)*(helper(n-1,k,dp)%MOD))%MOD;
        return dp[n][k]=((op1%MOD)+(op2%MOD))%MOD;
    }

    int rearrangeSticks(int n, int k) 
    {
        vector<vector<ll>>dp(n+1,vector<ll>(k+1,-1));
        return helper(n,k,dp);
    }
};
