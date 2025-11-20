class Solution {
  public:
    int minCost(string &s, string &f, vector<vector<char>> &t, vector<int> &cost) 
    {
        vector<vector<int>>dis(26,vector<int>(26,INT_MAX));
        for(int i=0;i<26;i++)dis[i][i]=0;
        
        int sz=cost.size();
        for(int i=0;i<sz;i++)dis[t[i][0]-'a'][t[i][1]-'a']=min(dis[t[i][0]-'a'][t[i][1]-'a'],cost[i]);
        
        for(int k=0;k<26;k++)
            for(int i=0;i<26;i++)
                for(int j=0;j<26;j++)
                    if(dis[i][k]!=INT_MAX && dis[k][j]!=INT_MAX)
                        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        
        int n=s.size();    
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int c1=s[i]-'a';
            int c2=f[i]-'a';
            int res=INT_MAX;
            for(int mk=0;mk<26;mk++)
            {
                if(dis[c1][mk]==INT_MAX || dis[c2][mk]==INT_MAX)continue;
                int cst=dis[c1][mk]+dis[c2][mk];
                res=min(res,cst);
            }
            if(res==INT_MAX)return -1;
            ans+=res;
        }
        return ans;
    }
};
