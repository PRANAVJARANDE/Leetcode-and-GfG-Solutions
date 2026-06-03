#define ll long long
class Solution {
public:

    ll n,f1;
    const int MOD=1e9+7;
    ll helper(int in,vector<vector<int>>&nx,vector<ll>&dp)
    {
        if(in>=n)return 0;
        if(dp[in]!=-1)return dp[in];
        // take 1
        ll op1=0;
        if(nx[in+1][1]!=n)op1=helper(nx[in+1][1],nx,dp);
        // take 0
        ll op2=0;
        if(nx[in+1][0]!=n)op2=helper(nx[in+1][0],nx,dp);
        return dp[in]=((op1%MOD + op2%MOD + 1)%MOD);
    }

    int numberOfUniqueGoodSubsequences(string s) 
    {
        n=s.size();
        vector<vector<int>>nx(n+1,vector<int>(2,n));
        for(int i=n-1;i>=0;i--)
        {
            if(i+1<n)nx[i]=nx[i+1];
            nx[i][s[i]-'0']=i;
        }
        ll ans=0;
        f1=-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')ans=1;
            else if(f1==-1)f1=i;
        }
        if(f1==-1)return ans;
        vector<ll>dp(n,-1);
        //cout<<ans<<" "<<f1<<endl;
        ans=((ans%MOD)+(helper(f1,nx,dp)))%MOD;
        return ans;
    }
};
