class Solution {
  public:
    bool canFinish(int n, vector<vector<int>>&a) 
    {
        vector<vector<int>>adj(n);
        vector<int>deg(n,0);
        for(auto x:a)
        {
            adj[x[1]].push_back(x[0]);
            deg[x[0]]++;
        }
        
        queue<int>q1;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(deg[i]==0)
            {
                q1.push(i);
                vis[i]=1;
            }
        }
        
        while(!q1.empty())
        {
            auto in=q1.front();
            q1.pop();
            for(auto x:adj[in])
            {
                deg[x]--;
                if(deg[x]==0)
                {
                    vis[x]=1;
                    q1.push(x);
                }
            }
        }
        for(auto x:vis)if(x==0)return 0;
        return 1;
    }
};
