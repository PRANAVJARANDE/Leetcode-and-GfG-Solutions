class Solution {
  public:
    
    int n,m;
    vector<int>dx{-1,1,0,0};
    vector<int>dy{0,0,-1,1};
    
    bool issafe(int x,int y)
    {
        return x>=0 && y>=0 && x<n && y<m;
    }
    
    int minCostPath(vector<vector<int>>& a) 
    {
        n=a.size();
        m=a[0].size();
        
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        dis[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q1;
        q1.push({0,{0,0}});  // {dis,node}
        
        while(!q1.empty())
        {
            auto pr=q1.top();
            q1.pop();
            
            int cst=pr.first;
            int x=pr.second.first;
            int y=pr.second.second;
            
            if(dis[x][y]>cst)continue;
            
            for(int z=0;z<4;z++)
            {
                int nx=x+dx[z];
                int ny=y+dy[z];
                if(issafe(nx,ny) && dis[nx][ny]>max(cst,abs(a[x][y]-a[nx][ny])))
                {
                    dis[nx][ny]=max(cst,abs(a[x][y]-a[nx][ny]));
                    q1.push({max(cst,abs(a[x][y]-a[nx][ny])),{nx,ny}});
                }
            }
        }
        return dis[n-1][m-1];
    }
};
