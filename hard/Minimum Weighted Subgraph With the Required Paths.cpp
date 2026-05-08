#define ll long long
class Solution {
public:

    void dijkstra(int s,vector<vector<vector<ll>>>&adj,vector<ll>&dis)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q1;
        q1.push({0,s});
        dis[s]=0;
        while(!q1.empty())
        {
            auto pr=q1.top();
            q1.pop();
            ll cst=pr.first;
            ll in=pr.second;
            if(cst>dis[in])continue;
            for(auto x:adj[in])
            {
                int to=x[0];
                int w=x[1];

                if(dis[to]>dis[in]+w)
                {
                    dis[to]=dis[in]+w;
                    q1.push({dis[to],to});
                }
            }
        }
    }

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) 
    {
        vector<vector<vector<ll>>>adj(n),adj1(n);

        for(auto x:edges)
        {
            adj[x[0]].push_back({x[1],x[2]});
            adj1[x[1]].push_back({x[0],x[2]});
        }

        vector<ll>d1(n,LLONG_MAX),d2(n,LLONG_MAX),d3(n,LLONG_MAX);
        dijkstra(src1,adj,d1);
        dijkstra(src2,adj,d2);
        dijkstra(dest,adj1,d3);
        ll ans=LLONG_MAX;
        for(int i=0;i<n;i++)
        {
            if(d1[i]!=LLONG_MAX && d2[i]!=LLONG_MAX && d3[i]!=LLONG_MAX)
            {
                ans=min(ans,d1[i]+d2[i]+d3[i]);
            }
        }
        if(ans==LLONG_MAX)ans=-1;
        return ans;
    }
};
