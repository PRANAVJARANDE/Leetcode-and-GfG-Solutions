class Solution {
  public:
    
    class dsu{
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
            if(a==par[a])return a;
            return par[a]=find_set(par[a]);
        }
        
        void union_set(int a,int b)
        {
            a=find_set(a);
            b=find_set(b);
            if(a==b)return;
            if(sz[a]>sz[b])
            {
                sz[a]+=sz[b];
                par[b]=a;
            }
            else
            {
                sz[b]+=sz[a];
                par[a]=b;
            }
        }
        
    };
  
    int minEdgesReq(int n, vector<vector<int>>& edges) 
    {
        dsu d1(n);
        int cnt=0;
        for(auto x:edges)
        {
            int u=x[0],v=x[1];
            if(d1.find_set(u)==d1.find_set(v))cnt++;
            d1.union_set(u,v);
        }
        
        set<int>s1;
        for(int i=0;i<n;i++)s1.insert(d1.find_set(i));
        
        int sz=s1.size()-1;
        
        if(cnt<sz)return -1;
        return sz;
    }
};
