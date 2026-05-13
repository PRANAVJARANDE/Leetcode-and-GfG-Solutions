class Solution {
  public:

    void dfs(int in,vector<int>&vis,vector<vector<int>>&adj)
    {
        vis[in]=1;
        for(auto x:adj[in])
        {
            if(vis[x]==0)
            {
                dfs(x,vis,adj);
            }
        }
    }
  
    int findMotherVertex(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>>adj(n);
        for(auto x:edges)adj[x[0]].push_back(x[1]);
        int ls=-1;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                dfs(i,vis,adj);
                ls=i;
            }
        }
        vis=vector<int>(n,0);
        dfs(ls,vis,adj);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)return -1;
        }
        return ls;
    }
};
