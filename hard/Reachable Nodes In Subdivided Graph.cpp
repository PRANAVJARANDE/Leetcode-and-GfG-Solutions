class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxi, int n) 
    {
        vector<vector<int>>dp(n,vector<int>(n,0));

        vector<vector<vector<int>>>adj(n);
        for(auto x:edges)
        {
            adj[x[0]].push_back({x[1],x[2]+1});
            adj[x[1]].push_back({x[0],x[2]+1});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q1;
        q1.push({0,0});
        vector<int>dis(n,INT_MAX);
        dis[0]=0;
        while(!q1.empty())
        {
            auto cst=q1.top().first;
            auto in=q1.top().second;
            q1.pop();   
            if(dis[in]<cst)continue;
            for(auto x:adj[in])
            {
                int ncst=cst+x[1];
                if(dis[x[0]]>cst+x[1])
                {
                    dis[x[0]]=cst+x[1];
                    q1.push({dis[x[0]],x[0]});
                }
            }
        }

        int ans=0;
        for(int i=0;i<n;i++)if(dis[i]<=maxi)ans++;

        for(auto x:edges)
        {
            int u=x[0],v=x[1];
            int c1=max(0,maxi-dis[u]);
            int c2=max(0,maxi-dis[v]);
            ans+=min(x[2],c1+c2);
        }
        return ans;
    }
};
