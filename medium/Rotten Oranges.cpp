class Solution {
  public:
    
    vector<int>dx{-1,1,0,0};
    vector<int>dy{0,0,-1,1};
    
    int n,m;
    bool issafe(int x,int y)
    {
        return x>=0 && y>=0 && x<n && y<m;
    }
    
    int orangesRot(vector<vector<int>>& a) 
    {
        n=a.size();
        m=a[0].size();
        
        queue<pair<int,int>>q1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==2)
                {
                    q1.push({i,j});
                }
            }
        }
        
        int ans=0;
        while(!q1.empty())
        {
            int sz=q1.size();
            while(sz--)
            {
                int x=q1.front().first;
                int y=q1.front().second;
                q1.pop();
                
                for(int z=0;z<4;z++)
                {
                    int nx=x+dx[z];
                    int ny=y+dy[z];
                    if(issafe(nx,ny) && a[nx][ny]==1)
                    {
                        a[nx][ny]=2;
                        q1.push({nx,ny});
                    }
                }
            }
            ans++;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==1)return -1;
            }
        }
        return max(0,ans-1);
    }
};
