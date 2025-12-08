#define ll long long
class Solution {
  public:
    
    ll n;
    ll helper(int in,int pv,vector<vector<pair<int,int>>>&v1,vector<vector<int>>&dp)
    {
        if(in>=n)return 0;
        if(dp[in][pv]!=-1)return dp[in][pv];
        int sz=v1[0].size();
        
        ll pcol=-1;
        if(in!=0)pcol=v1[in-1][pv].second;
        
        ll ans=INT_MAX;
        for(int i=0;i<sz;i++)
        {
            if(v1[in][i].second!=pcol)
            {
                ll op=v1[in][i].first+helper(in+1,i,v1,dp);
                ans=min(ans,op);
            }
        }
        return dp[in][pv]=ans;
    }
  
    int minCost(vector<vector<int>>&a) 
    {
        n=a.size();
        int m=a[0].size();
        vector<vector<pair<int,int>>>v1;
        for(auto x:a)
        {
            priority_queue<pair<int,int>>q1;
            for(int i=0;i<m;i++)
            {
                q1.push({x[i],i});
                if(q1.size()>3)q1.pop();
            }
            vector<pair<int,int>>temp;
            while(!q1.empty())
            {
                temp.push_back(q1.top());
                q1.pop();
            }
            v1.push_back(temp);
        }
        
        vector<vector<int>>dp(n,vector<int>(4,-1));
        ll ans=helper(0,3,v1,dp);
        if(ans==INT_MAX)ans=-1;
        return ans;
    }
};
