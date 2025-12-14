#define ll long long
class Solution {
public:

    ll n;
    ll helper(int in,string&s,vector<vector<bool>>&flag,vector<ll>&dp)
    {
        if(in>=n)return 0;
        if(dp[in]!=-1)return dp[in];
        ll ans=INT_MAX;
        for(int j=in;j<n;j++)
        {
            if(flag[in][j])
            {
                ll res=1+helper(j+1,s,flag,dp);
                ans=min(ans,res);
            }
        }
        return dp[in]=ans;
    }

    int minCut(string s)
    {
        n=s.size();
        vector<vector<bool>>flag(n,vector<bool>(n,0));

        for(int i=0;i<n;i++)
        {
            int l=i,r=i;
            while(l>=0 && r<n && s[l]==s[r])
            {
                flag[l][r]=1;
                l--;
                r++;
            }
            l=i,r=i+1;
            while(l>=0 && r<n && s[l]==s[r])
            {
                flag[l][r]=1;
                l--;
                r++;
            }
        }
        vector<ll>dp(n,-1);
        return helper(0,s,flag,dp)-1;
    }
};
