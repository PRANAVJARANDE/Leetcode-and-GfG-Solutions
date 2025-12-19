class Solution {
public:

    int n;
    vector<vector<int>>adj;

    //precompute
    int build(int in,string&s,vector<int>&dp)
    {
        int res=1;
        for(auto x:adj[in])
        {
            build(x,s,dp);
            if(s[x]!=s[in])res=max(res,1+dp[x]);
        }
        return dp[in]=res;
    }

    int dfs(int in,int extra,string&s,vector<int>&dp)
    {
        int ans=dp[in]+extra;
        int m1=0,m2=0;
        for(auto x:adj[in])
        {
            if(s[x]==s[in])continue;
            if(dp[x]>=m1)
            {
                m2=m1;
                m1=dp[x];
            }
            else if(dp[x]>=m2)
            {
                m2=dp[x];
            }
        }

        for(auto x:adj[in])
        {
            int next_extra;
            if(s[in]==s[x])next_extra=0;
            else
            {
                next_extra=extra+1;
                if(dp[x]==m1)next_extra=max(next_extra,m2+1);
                else next_extra=max(next_extra,m1+1);
            }
            int res=dfs(x,next_extra,s,dp);
            ans=max(ans,res);
        }
        return ans;
    }

    int longestPath(vector<int>& parent, string s) 
    {
        n=parent.size();
        adj=vector<vector<int>>(n);
        for(int i=1;i<n;i++)adj[parent[i]].push_back(i);
        
        vector<int>dp(n,0);
        build(0,s,dp);
        return dfs(0,0,s,dp);
    }
};
