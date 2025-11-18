#define ll long long
class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& edges) 
    {
        vector<vector<vector<int>>>adj(n);
        for(auto x:edges)
        {
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        
        vector<ll>dis(n,INT_MAX);
        vector<ll>cnt(n,0);
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q1;
        q1.push({0,0});
        dis[0]=0;
        cnt[0]=1;
        
        while(!q1.empty())
        {
            auto cst=q1.top().first;
            auto in=q1.top().second;
            q1.pop();
            if(cst>dis[in])continue;
            for(auto x:adj[in])
            {
                int ncst=cst+x[1];
                if(dis[x[0]]>ncst)
                {
                    dis[x[0]]=ncst;
                    q1.push({ncst,x[0]});
                    cnt[x[0]]=cnt[in];
                }
                else if(dis[x[0]]==ncst)
                {
                    cnt[x[0]]+=cnt[in];
                }
            }
        }
        return cnt[n-1];
    }
};
