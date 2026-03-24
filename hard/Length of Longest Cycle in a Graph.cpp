class Solution {
  public:
    
    int ans;
    void dfs(int in,int cnt,vector<vector<int>>&adj,vector<int>&vis,vector<int>&cvis)
    {
        if(cvis[in]!=-1)
        {
            ans=max(ans,cnt-cvis[in]);
            return;
        }
        vis[in]=1;
        cvis[in]=cnt;
        for(auto x:adj[in])
        {
            dfs(x,cnt+1,adj,vis,cvis);
        }
        cvis[in]=-1;
    }
  
    int longestCycle(int n, vector<vector<int>>& e) 
    {
        vector<vector<int>>adj(n);
        for(auto x:e)adj[x[0]].push_back(x[1]);
        vector<int>vis(n,0);
        ans=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                vector<int>cvis(n,-1);
                dfs(i,0,adj,vis,cvis);
            }
        }
        if(ans==INT_MIN)ans=-1;
        return ans;
    }
};
