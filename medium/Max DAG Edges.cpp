class Solution {
  public:
    int maxEdgesToAdd(int n, vector<vector<int>>& e) 
    {
        vector<int>deg(n);
        vector<vector<int>>adj(n);
        for(auto x:e)
        {
            adj[x[0]].push_back(x[1]);
            deg[x[1]]++;
        }
        
        int ans=0;
        queue<int>q1;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(deg[i]==0)
            {
                vis[i]=1;
                q1.push(i);
            }
        }
        
        int rem=n-1;
        while(!q1.empty())
        {
            auto in=q1.front();
            q1.pop();
            
            ans+=max(0,(rem-(int)adj[in].size()));
            rem--;
            
            for(auto x:adj[in])
            {
                if(vis[x])continue;
                deg[x]--;
                if(deg[x]==0)
                {
                    vis[x]=1;
                    q1.push(x);
                }
            }
        }
        return ans;
    }
};
