class Solution {
  public:
    
    class dsu{
     public:  
     
        int n;
        vector<int>par;
        vector<int>sz;
        
        dsu(int n)
        {
            this->n=n;
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
  
    int minOperations(vector<int> &b) 
    {
        int n=b.size();
        dsu d1(n);
        for(int i=0;i<n;i++)d1.union_set(i,b[i]-1);
        
        map<int,int>par;
        for(int i=0;i<n;i++)par[d1.find_set(i)]++;
        
        int ans=1;
        for(auto x:par)
        {
            ans=(ans*x.second)/__gcd(ans,x.second);
            //ans=lcm(ans,x.second);
        }
        return ans;
    }
};
