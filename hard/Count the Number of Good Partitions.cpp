#define ll long long
class Solution {
public:

    ll mod_pow(ll a,ll b,ll m) 
    {
        ll res=1;
        while(b>0)
        {
            if(b&1)res=(res*a)%m;
            a=(a*a)%m;
            b/=2;
        }
        return res;
    }

    int numberOfGoodPartitions(vector<int>& nums) 
    {
        int n=nums.size();
        set<int>s1;
        for(auto x:nums)s1.insert(x);
        map<int,int>m;
        int in=0;
        for(auto x:s1)m[x]=in++;
        for(auto &x:nums)x=m[x];

        vector<int>fs(in,-1),ls(in,-1);
        for(int i=0;i<n;i++)
        {
            if(fs[nums[i]]==-1)fs[nums[i]]=i;
            ls[nums[i]]=i;
        }

        vector<int>dp(n,0);
        for(int j=0;j<in;j++)
        {
            dp[fs[j]]++;
            dp[ls[j]]--;
        }
        ll cnt=0;
        for(int i=1;i<n;i++)
        {
            dp[i]+=dp[i-1];
            if(dp[i]==0)cnt++;
        }
        if(dp[0]==0)cnt++;
        ll ans=mod_pow(2,cnt-1,1e9+7);
        return ans;
    }
};
