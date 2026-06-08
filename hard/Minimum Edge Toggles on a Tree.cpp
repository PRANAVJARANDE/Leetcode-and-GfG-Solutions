class Solution {
public:
    vector<int> minimumFlips(int n,vector<vector<int>>&edges,string s,string t) 
    {
        vector<vector<int>>adj(n);
        map<pair<int,int>,int>m;
        vector<int>deg(n);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0],v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
            m[{min(u,v),max(u,v)}]=i;
        }

        queue<int>q1;
        for(int i=0;i<n;i++)
        {
            if(deg[i]==1)
            {
                q1.push(i);
            }
        }
        vector<int>ans;
        while(!q1.empty())
        {
            int in=q1.front();
            q1.pop();
            if(deg[in]!=1)continue;
            int par=-1;
            for(auto x:adj[in])
            {
                if(deg[x]>0)
                {
                    par=x;
                    break;
                }
            }
            if(par==-1)continue;
            if(s[in]!=t[in])
            {
                s[in]=t[in];
                s[par]=(s[par]=='1'?'0':'1');
                ans.push_back(m[{min(in,par),max(in,par)}]);
            }
            deg[in]=0;
            deg[par]--;
            if(deg[par]==1)q1.push(par);
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]!=t[i])return {-1};
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
