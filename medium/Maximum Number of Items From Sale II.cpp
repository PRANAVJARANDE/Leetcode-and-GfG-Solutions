#define ll long long
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) 
    {
        ll n=items.size();
        vector<ll>cnt(n+1,0);
        ll mini=INT_MAX;
        for(auto x:items)
        {
            cnt[x[0]]++;
            mini=min(mini,(ll)x[1]);
        }
        vector<ll>dp(n+1,0);
        for(ll i=1;i<=n;i++)
        {
            for(ll j=i;j<=n;j+=i)
            {
                dp[i]+=cnt[j];
            }
            dp[i]=max(0ll,dp[i]-1);
        }

        map<ll,ll>dp2;
        for(auto x:items)
        {
            ll f=x[0],p=x[1];
            if(p<mini*2)dp2[p]+=dp[f];
        }

        ll ans=0;
        for(auto x:dp2)
        {
            ll p=x.first,cnt=x.second;
            ll tk=min(cnt,budget/p);
            budget-=p*tk;
            ans+=tk*2;
        }
        ans+=budget/mini;
        return ans;
    }
};
