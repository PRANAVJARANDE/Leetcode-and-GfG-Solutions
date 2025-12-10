class Solution {
  public:
    
    class dsu
    {
        public:
        
        vector<int>par;
        vector<int>sz;
        
        dsu(int n)
        {
            par=vector<int>(n,0);
            sz=vector<int>(n,1);
            for(int i=0;i<n;i++)par[i]=i;
        }
        
        int find_set(int a)
        {
            if(par[a]==a)return a;
            return par[a]=find_set(par[a]);
        }
        
        void union_set(int a,int b)
        {
            a=find_set(a);
            b=find_set(b);
            if(a==b)return;
            if(sz[a]>sz[b])
            {
                par[b]=a;
                sz[a]+=sz[b];
            }
            else
            {
                par[a]=b;
                sz[b]+=sz[a];
            }
        }
    };
    
    
    void mark_col(int in,int par,vector<vector<vector<int>>>&adj,vector<int>&col)
    {
        col[in]=0;
        for(auto x:adj[in])if(x[0]!=par)mark_col(x[0],in,adj,col);
    }
    
    int mini;
    int helper(int in,int par,vector<vector<vector<int>>>&adj,vector<vector<int>>&edges)
    {
        int n=adj.size();
        int ans=INT_MAX;
        for(auto x:adj[in])
        {
            if(x[0]!=par)
            {
                vector<int>col(n,1);
                mark_col(x[0],in,adj,col);
                int res=mini-x[1];
                for(auto x:edges)
                {
                    int u=x[1],v=x[2],w=x[0];
                    if(col[u]!=col[v])
                    {
                        if(res+w>mini)
                        {
                            ans=min(ans,res+w);
                        }
                    }
                }
                ans=min(ans,helper(x[0],in,adj,edges));
            }
        }
        return ans;
    }
        
    
    int secondMST(int n, vector<vector<int>> &edges) 
    {
        int m=edges.size();
        for(auto &x:edges)swap(x[0],x[2]);
        sort(edges.begin(),edges.end());
        
        dsu d1(n);
        vector<vector<vector<int>>>adj(n);
        mini=0;
        for(auto x:edges)
        {
            int u=x[1],v=x[2],w=x[0];
            if(d1.find_set(u)!=d1.find_set(v))
            {
                d1.union_set(u,v);
                adj[u].push_back({v,w});
                adj[v].push_back({u,w});
                mini+=w;
            }
        }
        
        //check
        for(int i=1;i<n;i++)if(d1.find_set(i)!=d1.find_set(0))return -1;
        
        int ans=helper(0,-1,adj,edges);
        if(ans==INT_MAX)ans=-1;
        return ans;
    }
};
