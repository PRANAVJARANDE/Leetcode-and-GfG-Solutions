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

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edg, vector<vector<int>>& q) 
    {
        int sz=q.size();
        vector<vector<int>>v1(sz,vector<int>(2,0));
        for(int i=0;i<sz;i++)
        {
            v1[i][0]=q[i][2];
            v1[i][1]=i;
        }
        sort(v1.begin(),v1.end());
        for(auto &x:edg)swap(x[0],x[2]);
        sort(edg.begin(),edg.end());

        dsu d1(n);

        int ein=0;
        vector<bool>ans(sz);
        for(auto x:v1)
        {
            int limit=x[0];
            int in=x[1];

            while(ein<edg.size() && edg[ein][0]<limit)
            {
                d1.union_set(edg[ein][1],edg[ein][2]);
                ein++;
            }

            if(d1.find_set(q[in][0])==d1.find_set(q[in][1]))ans[in]=1;
            else ans[in]=0;
        }
        return ans;
    }
};
