#define ll long long
class Solution {
public:

    ll n;
    ll helper(ll k,ll mask,vector<int>&jobs,vector<vector<int>>&dp)
    {
        if(mask==((1<<n)-1))return 0;
        if(k<=0)return INT_MAX;
        if(dp[k][mask]!=-1)return dp[k][mask];
        vector<int>v1;
        for(int b=0;b<n;b++)if(!(mask & (1<<b)))v1.push_back(b);
        ll ans=INT_MAX;
        ll sz=v1.size();
        for(int b=0;b<(1<<sz);b++)
        {
            ll nmask=mask;
            ll sum=0;
            for(ll i=0;i<sz;i++)
            {
                if((b & (1<<i)))
                {
                    nmask=nmask | (1<<v1[i]);
                    sum+=jobs[v1[i]];
                }
            }
            sum=max(sum,helper(k-1,nmask,jobs,dp));
            ans=min(ans,sum);
        }
        return dp[k][mask]=ans;
    }


    int minimumTimeRequired(vector<int>& jobs, int k) 
    {
        n=jobs.size();
        vector<vector<int>>dp(k+1,vector<int>((1<<n),-1));
        return helper(k,0,jobs,dp);
    }
};
