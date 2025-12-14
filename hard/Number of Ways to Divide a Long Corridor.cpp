#define ll long long
class Solution {
public:

    const int MOD=1e9+7;
    ll n;
    ll helper(int in,int pv,string&s,vector<vector<ll>>&dp)
    {
        if(in>=n)
        {
            if(pv==2)return 1;
            return 0;
        }
        if(dp[in][pv]!=-1)return dp[in][pv];
        ll op1=0,op2=0;
        if(s[in]=='P')
        {
            if(pv==2)op1=helper(in+1,0,s,dp);
            op2=helper(in+1,pv,s,dp);
        }
        else
        {
            if(pv!=2)op1=helper(in+1,pv+1,s,dp);
            else op2=helper(in+1,1,s,dp);
        }
        return dp[in][pv]=((op1%MOD)+(op2%MOD))%MOD;
    }

    int numberOfWays(string s) 
    {
        n=s.size();
        vector<vector<ll>>dp(n,vector<ll>(4,-1));
        return helper(0,0,s,dp);
    }
};
