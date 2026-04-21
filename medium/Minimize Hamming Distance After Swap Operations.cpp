class Solution {
public:

    class dsu
    {
        public:
        vector<int>par,sz;

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


    int minimumHammingDistance(vector<int>& a, vector<int>& b, vector<vector<int>>& v1) 
    {
        int n=a.size();
        dsu d1(n);
        for(auto x:v1)
        {
            d1.union_set(x[0],x[1]);
        }
        
        
        vector<map<int,int>>s1(n);
        for(int i=0;i<n;i++)
        {
            s1[d1.find_set(i)][a[i]]++;
            s1[d1.find_set(i)][b[i]]--;
        }

        int ans=0;
        for(auto x:s1)
        {
            for(auto y:x)
            {
                ans+=max(0,y.second);
            }
        }
        return ans;
    }
};
