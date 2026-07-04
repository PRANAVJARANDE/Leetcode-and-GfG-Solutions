class Solution {
public:


    int minScore(int n, vector<vector<int>>& roads) 
    {
        vector<vector<pair<int,int>>>adj(n);
        for(auto x:roads)
        {
            int u=x[0]-1,v=x[1]-1,d=x[2];
            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }

        vector<int>vis(n,0);
        queue<int>q1;
        q1.push(0);
        vis[0]=1;

        int ans=INT_MAX;
        while(!q1.empty())
        {
            auto in=q1.front();
            q1.pop();

            for(auto x:adj[in])
            {
                ans=min(ans,x.second);
                if(vis[x.first]==0)
                {
                    vis[x.first]=1;
                    q1.push(x.first);
                }
            }
        }
        return ans;
    }
};
