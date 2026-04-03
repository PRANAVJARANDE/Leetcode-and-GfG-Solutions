#define ll long long
class Solution {
public:

    int cnt(int n)
    {
        int ans=0;
        while(n)
        {
            ans+=n%2;
            n/=2;
        }
        return ans;
    }

    long long countExcellentPairs(vector<int>& nums, int k) 
    {
        set<int>v1(nums.begin(),nums.end());

        vector<ll>dp(35,0);
        ll ans=0;
        for(auto x:v1)
        {
            ll c1=cnt(x);
            if(2*c1>=k)ans++;
            
            ll req=max(0ll,k-c1);
            for(ll i=req;i<35;i++)ans+=(2*dp[i]);
            dp[c1]++;
        }
        return ans;
    }
};
