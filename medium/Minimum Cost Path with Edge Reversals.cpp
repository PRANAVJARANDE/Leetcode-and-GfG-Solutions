#define ll long long
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) 
    {
        vector<vector<pair<ll,ll>>>adj(n),rev(n);
        for(auto x:edges)
        {
            adj[x[0]].push_back({x[1],x[2]});
            rev[x[1]].push_back({x[0],x[2]});
        }
        vector<ll>dis(n,INT_MAX);
        dis[0]=0;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q1;
        q1.push({0,0});

        while(!q1.empty())
        {
            auto pr=q1.top();
            auto cst=pr.first;
            auto in=pr.second;
            q1.pop();

            if(cst>dis[in])continue;

            for(auto x:adj[in])
            {
                if(dis[x.first]>cst+x.second)
                {
                    dis[x.first]=cst+x.second;
                    q1.push({dis[x.first],x.first});
                }
            }

            for(auto x:rev[in])
            {
                if(dis[x.first]>cst+(2*x.second))
                {
                    dis[x.first]=cst+(2*x.second);
                    q1.push({dis[x.first],x.first});
                }
            }
        }
        if(dis[n-1]==INT_MAX)return -1;
        return dis[n-1];
    }
};
