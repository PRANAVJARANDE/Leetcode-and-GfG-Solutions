class Solution {
public:
    vector<int> processQueries(int n, vector<vector<int>>& edg, vector<vector<int>>& queries) 
    {
        vector<vector<int>>adj(n);
        for(auto x:edg)
        {
            x[0]--;
            x[1]--;
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int>par(n,-1);
        
        for(int i=0;i<n;i++)
        {
            if(par[i]==-1)
            {
                par[i]=i;
                queue<int>q1;
                q1.push(i);
                while(!q1.empty())
                {
                    auto in=q1.front();
                    q1.pop();
                    for(auto x:adj[in])
                    {
                        if(par[x]==-1)
                        {
                            par[x]=par[in];
                            q1.push(x);
                        }
                    }
                }
            }
        }

        for(auto x:par)
        {
            cout<<x<<" ";
        }
        cout<<endl;

        map<int,set<int>>groups;
        vector<int>res;
        for(int i=0;i<n;i++)groups[par[i]].insert(i);

        for(auto x:queries)
        {
            if(x[0]==1)
            {
                int in=x[1]-1;
                if(groups[par[in]].empty())res.push_back(-1);
                else 
                {
                    if(groups[par[in]].find(in)!=groups[par[in]].end())res.push_back(in+1);
                    else res.push_back((*groups[par[in]].begin())+1);
                }
            }
            else
            {
                int in=x[1]-1;
                if(groups[par[in]].find(in)!=groups[par[in]].end())groups[par[in]].erase(in);
            }
        }
        return res;
    }
};
