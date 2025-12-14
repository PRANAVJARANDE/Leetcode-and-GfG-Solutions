#define ll long long
class Solution {
public:

    ll n;
    ll helper(int in,int k,string&s,vector<vector<ll>>&mk,vector<vector<ll>>&dp)
    {
        if(k<0)return INT_MAX;
        if(in>=n)
        {
            if(k==0)return 0;
            return INT_MAX;
        }
        if(dp[in][k]!=-1)return dp[in][k];
        //take something 
        ll ans=INT_MAX;
        for(int j=in;j<n;j++)
        {
            ll res=mk[in][j]+helper(j+1,k-1,s,mk,dp);
            ans=min(ans,res);
        }
        return dp[in][k]=ans;
    }

    int palindromePartition(string s, int k) 
    {
        n=s.size();
        vector<vector<ll>>mk(n,vector<ll>(n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int l=i,r=j;
                while(l<=r)
                {
                    if(s[l]!=s[r])mk[i][j]++;
                    l++;
                    r--;
                }
            }
        }
        vector<vector<ll>>dp(n,vector<ll>(k+1,-1));
        int ans=helper(0,k,s,mk,dp);
        return ans;
        
    }
};
