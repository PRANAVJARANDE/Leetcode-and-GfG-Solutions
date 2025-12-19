class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) 
    {
        vector<int>vis(n,0);
        vis[0]=1;
        vis[firstPerson]=1;

        map<int,vector<pair<int,int>>>v1;
        for(auto x:meetings)v1[x[2]].push_back({x[0],x[1]});

        for(auto x:v1)
        {
            // time - x.first
            // relations - x.second

            map<int,vector<int>>adj;
            queue<int>q1;
            map<int,int>taken;
            for(auto p:x.second)
            {
                adj[p.first].push_back(p.second);
                adj[p.second].push_back(p.first);
                if(vis[p.first] && taken[p.first]==0)
                {
                    taken[p.first]=1;
                    q1.push(p.first);
                }
                if(vis[p.second] && taken[p.second]==0)
                {
                    taken[p.second]=1;
                    q1.push(p.second);
                }
            }

            // graph of connections and few elements in queue which are visited before

            while(!q1.empty())
            {
                auto in=q1.front();
                q1.pop();

                for(auto x:adj[in])
                {
                    if(vis[x]==0)
                    {
                        vis[x]=1;
                        q1.push(x);
                    }
                }
            }
        }

        vector<int>ans;
        for(int i=0;i<n;i++)if(vis[i])ans.push_back(i);
        return ans;
    }
};
