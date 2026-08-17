class Solution {
  public:
    vector<int> maxDistance(int n, int src, vector<vector<int>> &edges) 
    {
       vector<int>dis(n,INT_MIN);
       dis[src]=0;
       vector<int>deg(n,0);
       vector<vector<vector<int>>>adj(n);
       for(auto x:edges)
       {
            adj[x[0]].push_back({x[1],x[2]});
            deg[x[1]]++;
       }
       queue<int>q1;
       for(int i=0;i<n;i++)if(deg[i]==0)q1.push(i);
       
       while(!q1.empty())
       {
           auto in=q1.front();
           q1.pop();
           for(auto x:adj[in])
           {
                if(dis[in]!=INT_MIN)
                dis[x[0]]=max(dis[x[0]],dis[in]+x[1]);
                deg[x[0]]--;
                if(deg[x[0]]==0)q1.push(x[0]);
           }
       }
       return dis;
       
        
    }
};
