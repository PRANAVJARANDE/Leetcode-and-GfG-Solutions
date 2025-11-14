class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& a) 
    {
        int n=a.size();
        vector<vector<vector<int>>>adj(n);
        sort(edges.begin(),edges.end());
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0],v=edges[i][1],w=edges[i][2];
            if(i-1>=0 && edges[i-1][0]==u && edges[i-1][1]==v)continue;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q1;
        q1.push({a[0],{0,0}});   
        //cst time in

        vector<vector<int>>dis(n,vector<int>(maxTime+2,INT_MAX));
        dis[0][0]=a[0];
        int ans=INT_MAX;
        while(!q1.empty())
        {
            auto pr=q1.top();
            auto cst=pr.first;
            auto tm=pr.second.first;
            auto in=pr.second.second;
            q1.pop();
            if(dis[in][tm]<cst)continue;

            if(in==n-1)return cst;
            for(auto x:adj[in])
            {
                int ndis=cst+a[x[0]];
                if(tm+x[1]<=maxTime && dis[x[0]][tm+x[1]]>ndis)
                {
                    dis[x[0]][tm+x[1]]=ndis;
                    q1.push({ndis,{tm+x[1],x[0]}});
                }
            }
        }
        return -1;
    }
};
