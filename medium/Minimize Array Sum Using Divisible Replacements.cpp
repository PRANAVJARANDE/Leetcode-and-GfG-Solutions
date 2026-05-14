#define ll long long
class Solution {
public:
    long long minArraySum(vector<int>& nums) 
    {
        int n=nums.size();
        ll mx = 1e5+10;
        vector<ll>dp(mx,0),lm(mx,INT_MAX);
        for(auto x:nums)dp[x]++;
        if(dp[1]>=1)return n;

        for(ll i=2;i<mx;i++)
        {
            if(dp[i])
            {
                for(ll j=i;j<mx;j+=i)
                {
                    if(dp[j])lm[j]=min(lm[j],i);
                }
            }
        }

        ll ans=0;
        for(auto x:nums)ans+=lm[x];
        return ans;
    }
};
