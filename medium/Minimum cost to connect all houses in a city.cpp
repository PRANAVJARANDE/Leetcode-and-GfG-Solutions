class Solution {
  public:
    int minCost(vector<vector<int>>& houses) 
    {
        int n=houses.size();
        vector<vector<vector<int>>>adj(n);
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int dis=abs(houses[i][0]-houses[j][0])+abs(houses[i][1]-houses[j][1]);
                adj[i].push_back({j,dis});
                adj[j].push_back({i,dis});
            }
        }
        
        //find mst
        vector<int>vis(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q1;
        q1.push({0,0});
        
        int ans=0;
        
        while(!q1.empty())
        {
            auto pr=q1.top();
            q1.pop();

            int cst=pr.first;
            int in=pr.second;
            if(vis[in])continue;
            ans+=cst;
            
            vis[in]=1;
            
            for(auto x:adj[in])
            {
                if(vis[x[0]]==0)
                {
                    q1.push({x[1],x[0]});
                }
            }
        }
        return ans;
    }
};
