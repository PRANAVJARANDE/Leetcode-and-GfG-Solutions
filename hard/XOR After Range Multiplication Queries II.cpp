#define ll long long
class Solution {
public:

    const int MOD=1e9+7;
    ll mod_pow(ll a,ll b)
    {
        if(b==0)return 1;
        a=a%MOD;
        ll ans=1;
        while(b)
        {
            if(b%2)ans=((ans%MOD)*(a%MOD))%MOD;
            a=((a%MOD)*(a%MOD))%MOD;
            b/=2;
        }
        return ans;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& q) 
    {
        ll n=nums.size();
        ll sq=sqrtl(n);
        
        vector<vector<vector<int>>>m(n+1);
        for(auto x:q)
        {
            int l=x[0],r=x[1],k=x[2],v=x[3];
            if(k<=sq)m[k].push_back({l,r,v});
            else for(int i=l;i<=r;i+=k)nums[i]=(((ll)nums[i]%MOD)*(v%MOD))%MOD;
        }

        for(int k=1;k<=n;k++)
        {
            if(m[k].empty())continue;
            vector<ll>dp(n+1,1);
            for(auto z:m[k])
            {
                ll l=z[0],r=z[1],v=z[2];
                dp[l]=((dp[l]%MOD)*(v%MOD))%MOD;
                ll ls=(r-l+1)/k;
                if((r-l+1)%k)ls++;
                ls=(ls*k);
                ls+=l;
                if(ls<=n)dp[ls]=((dp[ls]%MOD)*(mod_pow(v,MOD-2)%MOD))%MOD;
            }
            for(int i=k;i<n;i++)dp[i]=((dp[i]%MOD)*(dp[i-k]%MOD))%MOD;
            for(int i=0;i<n;i++)nums[i]=((nums[i]%MOD)*(dp[i]%MOD))%MOD;
        }
        ll ans=0;
        for(auto x:nums)ans^=x;
        return ans;
    }
};
