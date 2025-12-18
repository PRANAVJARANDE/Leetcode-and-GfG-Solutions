#define ll long long
class Solution 
{
public:

    ll n;
    ll dp[100002][2];
    ll helper(ll in,bool op,vector<ll>&p,vector<int>&s,ll k)
    {
        if(in>=n)return 0;
        if(dp[in][op]!=-1)return dp[in][op];
        // Dont use the operation
        ll op1=((p[in]-((in-1>=0)? p[in-1]:0))*s[in])+helper(in+1,op,p,s,k);

        // Use operation
        ll op2=LLONG_MIN/4;
        if(op==0 && in<=n-k)
        {
            ll profit=p[in+k-1]-p[in-1+(k/2)];
            op2=profit+helper(in+k,1,p,s,k);
        }
        return dp[in][op]=max(op1,op2);
    }

    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        n=prices.size();
        vector<ll>psum(n,0);
        psum[0]=prices[0];
        for(int i=1;i<n;i++)psum[i]=psum[i-1]+prices[i];
        memset(dp,-1,sizeof(dp));
        return helper(0,0,psum,strategy,k);
    }
};
