#define ll long long
class Solution {
public:

    const int MOD=1e9+7;
    ll helper(ll in,ll steps,ll n,vector<vector<ll>>&dp)
    {
        if(steps==0)
        {
            if(in==0)return 1;
            return 0;
        }
        if(dp[in][steps]!=-1)return dp[in][steps];
        ll op1=0,op2=0,op3=0;
        if(in-1>=0)op1=helper(in-1,steps-1,n,dp)%MOD;
        if(in+1<n)op2=helper(in+1,steps-1,n,dp)%MOD;
        op3=helper(in,steps-1,n,dp)%MOD;
        return dp[in][steps]=((op1%MOD)+(op2%MOD)+(op3%MOD))%MOD;
    }

    int numWays(int steps, int arrLen) 
    {
        arrLen=min(arrLen,steps+1);
        vector<vector<ll>>dp(arrLen+10,vector<ll>(steps+1,-1));
        ll ans=helper(0,steps,arrLen,dp);
        return ans;
    }
};
