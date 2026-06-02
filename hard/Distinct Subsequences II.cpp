#define ll long long
class Solution {
public:

    int n;
    const int MOD=1e9+7;
    ll helper(int in,vector<vector<int>>&nx,vector<ll>&dp)
    {
        if(in>=n)return 1;
        if(dp[in]!=-1)return dp[in];
        ll ans=1;
        for(int j=0;j<26;j++)
        {
            if(nx[in][j]!=n)
            {
                ans=((ans%MOD)+(helper(nx[in][j]+1,nx,dp)%MOD))%MOD;
            }
        }
        return dp[in]=ans;
    }


    int distinctSubseqII(string s) 
    {
        n=s.size();
        vector<vector<int>>nx(n,vector<int>(26,n));
        for(int i=n-1;i>=0;i--)
        {
            if(i+1<n)nx[i]=nx[i+1];
            nx[i][s[i]-'a']=i;
        }
        vector<ll>dp(n,-1);
        return (helper(0,nx,dp)-1+MOD)%MOD;
    }
};
