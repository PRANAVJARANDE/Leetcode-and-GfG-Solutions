#define ll long long
class Solution {
public:

    ll n;
    ll dp[1001][1001][3];
    ll helper(ll in,ll k,ll buy,vector<int>&a)
    {
        if(k<0)return INT_MIN;
        if(in>=n)
        {
            if(buy==0)return 0;
            return INT_MIN;
        }
        if(dp[in][k][buy]!=-1)return dp[in][k][buy];
        ll ans=helper(in+1,k,buy,a);
        if(buy==0)
        {
            ans=max(ans,-a[in]+helper(in+1,k,1,a));
            ans=max(ans,a[in]+helper(in+1,k,2,a));
        }
        else if(buy==1)ans=max(ans,a[in]+helper(in+1,k-1,0,a));
        else ans=max(ans,-a[in]+helper(in+1,k-1,0,a));
        return dp[in][k][buy]=ans;
    }

    ll maximumProfit(vector<int>& a, int k) 
    {
        n=a.size();
        memset(dp,-1,sizeof(dp));
        return helper(0,k,0,a);
    }
};
