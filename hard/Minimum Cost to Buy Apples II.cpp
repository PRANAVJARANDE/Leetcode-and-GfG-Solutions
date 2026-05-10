#define ll long long
class Solution {
public:

    int n;
    vector<ll> dijkstra(ll s,vector<vector<pair<ll,ll>>>&adj)
    {
        vector<ll>dis(n,LLONG_MAX);
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q1;
        dis[s]=0;
        q1.push({0,s});
        while(!q1.empty())
        {
            auto [cst, in] = q1.top();
            q1.pop();
            if(cst>dis[in])continue;
            for(auto x:adj[in])
            {
                ll ch=x.first;
                ll w=x.second;
                if(dis[ch]>cst+w)
                {
                    dis[ch]=cst+w;
                    q1.push({dis[ch],ch});
                }
            }
        }
        return dis;
    }

    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) 
    {
        this->n=n;
        vector<vector<pair<ll,ll>>>adj1(n),adj2(n);
        for(auto x:roads)
        {
            adj1[x[0]].push_back({x[1],x[2]});
            adj1[x[1]].push_back({x[0],x[2]});
            adj2[x[0]].push_back({x[1],(ll)x[2]*x[3]});
            adj2[x[1]].push_back({x[0],(ll)x[2]*x[3]});
        }

        vector<int>ans(n,INT_MAX);
        for(int i=0;i<n;i++)
        {
            vector<ll>d1=dijkstra(i,adj1);
            vector<ll>d2=dijkstra(i,adj2);
            ll best=prices[i];
            for(int j=0;j<n;j++)
            {
                if(d1[j]!=LLONG_MAX && d2[j]!=LLONG_MAX)
                {
                    best=min(best,(ll)prices[j]+d1[j]+d2[j]);
                }
            }
            ans[i]=best;
        }
        return ans;
    }
};
