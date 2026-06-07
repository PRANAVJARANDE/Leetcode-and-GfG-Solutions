#define ll long long
class Solution {
public:

    ll mini,n;
    const ll INF=1e15;
    ll helper(int in,ll budget,vector<vector<int>>&items,vector<vector<ll>>&dp)
    {
        if(budget<0)return -INF;
        if(in>=n)return budget/mini;
        if(dp[in][budget]!=-1)return dp[in][budget];
        ll op1=helper(in+1,budget,items,dp);
        ll op2=items[in][0]+helper(in+1,budget-items[in][1],items,dp);
        return dp[in][budget]=max(op1,op2);
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) 
    {
        int MX=2000;
        n=items.size();
        vector<ll>cnt(MX,0);
        mini=INT_MAX;
        for(auto x:items)
        {
            cnt[x[0]]++;
            mini=min(mini,(ll)x[1]);
        }
        vector<ll>dp(MX,0);
        for(ll i=1;i<MX;i++)
        {
            for(ll j=i;j<MX;j+=i)
            {
                dp[i]+=cnt[j];
            }
        }

        for(auto &x:items)x[0]=dp[x[0]];
        vector<vector<ll>>dp2(n,vector<ll>(budget+1,-1));
        return helper(0,budget,items,dp2);
    }
};
