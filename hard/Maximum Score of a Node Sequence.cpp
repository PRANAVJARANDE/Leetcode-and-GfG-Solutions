class Solution {
public:

    int maximumScore(vector<int>& score, vector<vector<int>>& edges) 
    {
        int n=score.size();
        vector<vector<pair<int,int>>>adj(n);
        for(auto x:edges)
        {
            adj[x[0]].push_back({score[x[1]],x[1]});
            adj[x[1]].push_back({score[x[0]],x[0]});
        }
        for(auto &x:adj)
        {
            sort(x.begin(),x.end(),greater<pair<int,int>>());
            while(x.size()>4)x.pop_back();
        }
        
        int ans=-1;
        for(auto e:edges)
        {
            int x=e[0];
            int y=e[1];
            for(auto [s1,nx]:adj[x])
            {
                if(nx==x || nx==y)continue;
                for(auto [s2,ny]:adj[y])
                {
                    if(ny==x || ny==y || ny==nx)continue;
                    ans=max(ans,score[x]+score[y]+s1+s2);
                }
            }
        }
        return ans;
    }
};
