class Solution {
  public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) 
    {
        vector<int>m(n*n,-1);
        for(int i=0;i<lad.size();i+=2)m[lad[i]-1]=lad[i+1]-1;
        for(int i=0;i<sn.size();i+=2)m[sn[i]-1]=sn[i+1]-1;
        
        vector<int>dis(n*n,INT_MAX);
        dis[0]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q1;
        q1.push({0,0});
        
        while(!q1.empty())
        {
            auto cst=q1.top().first;
            auto in=q1.top().second;
            q1.pop();

            if(cst>dis[in])continue;

            for(int z=1;z<=6;z++)
            {
                int nx=in+z;
                if(nx<n*n)
                {
                    if(m[nx]!=-1)nx=m[nx];

                    if(dis[nx]>dis[in]+1)
                    {
                        dis[nx]=dis[in]+1;
                        q1.push({dis[in]+1,nx});
                    }
                }
            }
        }
        
        int ans=-1;
        if(dis[n*n-1]!=INT_MAX)ans=dis[n*n-1];
        return ans;
    }
};
