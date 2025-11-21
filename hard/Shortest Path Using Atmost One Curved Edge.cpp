class Solution {
  public:
    int shortestPath(int n, int a, int b, vector<vector<int>> &edges) 
    {
        vector<vector<vector<int>>>adj1(n),adj2(n);
        for(auto x:edges)
        {
            adj1[x[0]].push_back({x[1],x[2]});
            adj1[x[1]].push_back({x[0],x[2]});
            adj2[x[0]].push_back({x[1],x[3]});
            adj2[x[1]].push_back({x[0],x[3]});
        }
        
        vector<vector<int>>dis(n,vector<int>(2,INT_MAX));
        dis[a][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q1;
        q1.push({0,{a,0}});
        
        
        while(!q1.empty())
        {
            auto pr=q1.top();
            q1.pop();
            auto cst=pr.first;
            auto in=pr.second.first;
            auto taken=pr.second.second;
            
            if(dis[in][taken]<cst)continue;
            
            for(auto x:adj1[in])
            {
                int ncst=cst+x[1];
                if(dis[x[0]][taken]>ncst)
                {
                    dis[x[0]][taken]=ncst;
                    q1.push({ncst,{x[0],taken}});
                }
            }
            
            if(taken==0)
            {
                for(auto x:adj2[in])
                {
                    int ncst=cst+x[1];
                    if(dis[x[0]][1]>ncst)
                    {
                        dis[x[0]][1]=ncst;
                        q1.push({ncst,{x[0],1}});
                    }
                }
            }
        }
        
        int ans=min(dis[b][0],dis[b][1]);
        if(ans==INT_MAX)ans=-1;
        return ans;
    }
};
