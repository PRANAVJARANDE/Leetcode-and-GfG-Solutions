class Solution {
  public:
  
    int n,m;
    bool issafe(int a,int b)
    {
        return a>=0 && b>=0 && a<n && b<m;
    }
    
    vector<int>dx{-1,1,0,0};
    vector<int>dy{0,0,-1,1};
 
    int cntOnes(vector<vector<int>>& a) 
    {
        n=a.size(),m=a[0].size();
        queue<pair<int,int>>q1;
        for(int i=0;i<n;i++)
        {
            if(a[i][0]==1)
            {
                a[i][0]=0;
                q1.push({i,0});
            }
            if(a[i][m-1]==1)
            {
                a[i][m-1]=0;
                q1.push({i,m-1});
            }
        }
        
        for(int i=0;i<m;i++)
        {
            if(a[0][i]==1)
            {
                a[0][i]=0;
                q1.push({0,i});
            }
            if(a[n-1][i]==1)
            {
                a[n-1][i]=0;
                q1.push({n-1,i});
            }
        }
        
        while(!q1.empty())
        {
            int i=q1.front().first;
            int j=q1.front().second;
            q1.pop();
            
            for(int z=0;z<4;z++)
            {
                int nx=i+dx[z];
                int ny=j+dy[z];
                
                if(issafe(nx,ny) && a[nx][ny]==1)
                {
                    a[nx][ny]=0;
                    q1.push({nx,ny});
                }
            }
        }
        int ans=0;
        for(auto x:a)for(auto y:x)ans+=y;
        return ans;
    }
};
