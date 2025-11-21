class Solution {
  public:
    int minConnect(int n, vector<vector<int>>& edges) {
        int sz=edges.size();
        if(sz<n-1)return -1;
        
        vector<vector<int>>adj(n);
        for(auto x:edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        int cnt=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                cnt++;
                queue<int>q1;
                q1.push(i);
                vis[i]=1;
                while(!q1.empty())
                {
                    auto in=q1.front();
                    q1.pop();
                    for(auto x:adj[in])
                    {
                        if(vis[x]==0)
                        {
                            vis[x]=1;
                            q1.push(x);
                        }
                    }
                }
            }
        }
        return cnt-1;
    }
};
