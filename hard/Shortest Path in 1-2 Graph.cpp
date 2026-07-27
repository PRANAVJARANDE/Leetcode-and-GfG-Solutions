class Solution {
  public:
    int shortestPath(int n, int src, int dest, vector<vector<int>> &edges) 
    {
        int sz=n;
        for(auto x:edges)if(x[2]==2)sz++;   
        vector<vector<int>>adj(sz);
        
        for(auto x:edges)
        {
            if(x[2]==1)
            {
                adj[x[1]].push_back(x[0]);
                adj[x[0]].push_back(x[1]);
            }
            else 
            {
                int in=n;
                adj[x[0]].push_back(in);
                adj[in].push_back(x[0]);
                adj[x[1]].push_back(in);
                adj[in].push_back(x[1]);
                n++;
            }
        }
        
        queue<int>q1;
        q1.push(src);
        
        
        vector<int>vis(n,-1);
        vis[src]=0;
        while(!q1.empty())
        {
            auto in=q1.front();
            q1.pop();
            
            for(auto x:adj[in])
            {
                if(vis[x]==-1)
                {
                    vis[x]=1+vis[in];
                    q1.push(x);
                }
            }
        }
        return vis[dest];
    }
};
