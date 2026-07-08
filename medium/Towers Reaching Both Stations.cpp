class Solution {
  public:
    
    int n,m;
    bool issafe(int x,int y)
    {
        return x>=0 && y>=0 && x<n && y<m;
    }
    
    vector<int>dx{-1,1,0,0};
    vector<int>dy{0,0,-1,1};
  
  
    int countCoordinates(vector<vector<int>>& a) 
    {
        n=a.size();
        m=a[0].size();
        vector<vector<int>>vis1(n,vector<int>(m,0));
        vector<vector<int>>vis2(n,vector<int>(m,0));
        queue<pair<int,int>>q1,q2;
        
        for(int i=0;i<n;i++)
        {
            if(vis1[i][0]==0)
            {
                vis1[i][0]=1;
                q1.push({i,0});
            }
            if(vis2[i][m-1]==0)
            {
                vis2[i][m-1]=1;
                q2.push({i,m-1});
            }
        }
        
        for(int i=0;i<m;i++)
        {
            if(vis1[0][i]==0)
            {
                vis1[0][i]=1;
                q1.push({0,i});
            }
            if(vis2[n-1][i]==0)
            {
                vis2[n-1][i]=1;
                q2.push({n-1,i});
            }
        }
        
        
        while(!q1.empty())
        {
            int x=q1.front().first;
            int y=q1.front().second;
            q1.pop();
            
            for(int z=0;z<4;z++)
            {
                int nx=x+dx[z];
                int ny=y+dy[z];
                if(issafe(nx,ny) && vis1[nx][ny]==0 && a[x][y]<=a[nx][ny])
                {
                    vis1[nx][ny]=1;
                    q1.push({nx,ny});
                }
            }
        }
        
        while(!q2.empty())
        {
            int x=q2.front().first;
            int y=q2.front().second;
            q2.pop();
            
            for(int z=0;z<4;z++)
            {
                int nx=x+dx[z];
                int ny=y+dy[z];
                if(issafe(nx,ny) && vis2[nx][ny]==0 && a[x][y]<=a[nx][ny])
                {
                    vis2[nx][ny]=1;
                    q2.push({nx,ny});
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis1[i][j] && vis2[i][j])
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
