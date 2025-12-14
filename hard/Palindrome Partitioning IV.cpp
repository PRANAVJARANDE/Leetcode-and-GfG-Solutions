#define ll long long
class Solution {
public:

    ll n;
    bool helper(int in,int k,string&s,vector<vector<bool>>&flag,vector<vector<ll>>&dp)
    {
        if(k<0)return 0;
        if(in>=n)
        {
            if(k==0)return 1;
            return 0;
        }
        if(dp[in][k]!=-1)return dp[in][k];
        bool ans=0;
        for(int j=in;j<n;j++)
        {
            if(flag[in][j])
            {
                ll res=helper(j+1,k-1,s,flag,dp);
                ans=ans | res;
                if(res)break;
            }
        }
        return dp[in][k]=ans;
    }

    bool checkPartitioning(string s) 
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
        vector<vector<ll>>dp(n,vector<ll>(3+1,-1));
        bool res=helper(0,3,s,flag,dp);
        return res;
    }
};

