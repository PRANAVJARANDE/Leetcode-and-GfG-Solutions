class Solution {
  public:
    vector<int> safeNodes(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>>adj(n);
        vector<int>deg(n);
        for(auto x:edges)
        {
            deg[x[0]]++;
            adj[x[1]].push_back(x[0]);
        }
        queue<int>q1;
        vector<int>vis(n,0);
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(deg[i]==0)
            {
                ans.push_back(i);
                vis[i]=1;
                q1.push(i);
            }
        }
        while(!q1.empty())
        {
            auto in=q1.front();
            q1.pop();
            for(auto x:adj[in])
            {
                if(vis[x]==0)
                {
                    deg[x]--;
                    if(deg[x]==0)
                    {
                        q1.push(x);
                        vis[x]=1;
                        ans.push_back(x);
                    }
                }
            }
        }
        return ans;
    }
};
