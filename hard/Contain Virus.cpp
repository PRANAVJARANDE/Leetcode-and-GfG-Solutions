class Solution {
public:
    int n,m;
    vector<int>dx{-1,1,0,0};
    vector<int>dy{0,0,-1,1};
    
    bool issafe(int i,int j)
    {
        return i>=0 && j>=0 && i<n && j<m;
    }

    int build_walls(int i,int j,vector<vector<int>>&a)
    {
        queue<pair<int,int>>q1;
        q1.push({i,j});
        int walls=0;
        a[i][j]=2;

        while(!q1.empty())
        {
            int i=q1.front().first;
            int j=q1.front().second;
            q1.pop();

            for(int z=0;z<4;z++)
            {
                int nx=i+dx[z];
                int ny=j+dy[z];
                if(issafe(nx,ny))
                {
                    if(a[nx][ny]==1)
                    {
                        a[nx][ny]=2;
                        q1.push({nx,ny});
                    }
                    else if(a[nx][ny]==0)
                    {
                        walls++;
                    }
                }
            }
        }
        return walls;
    }

    int count_uninfected(int i,int j,vector<vector<int>>&a,vector<vector<int>>&cvis)
    {
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q1;
        q1.push({i,j});
        cvis[i][j]=1;
        int cnt=0;

        while(!q1.empty())
        {
            int i=q1.front().first;
            int j=q1.front().second;
            q1.pop();
            for(int z=0;z<4;z++)
            {
                int nx=i+dx[z];
                int ny=j+dy[z];
                if(issafe(nx,ny))
                {
                    if(a[nx][ny]==1 && cvis[nx][ny]==0)
                    {
                        cvis[nx][ny]=1;
                        q1.push({nx,ny});
                    }
                    else if(a[nx][ny]==0 && vis[nx][ny]==0)
                    {
                        vis[nx][ny]=1;
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }

    int containVirus(vector<vector<int>>& a) 
    {
        n=a.size();
        m=a[0].size();

        int walls=0;
        while(1)
        {
            vector<vector<int>>cvis(n,vector<int>(m,0));
            int x=-1,y=-1;
            int uinf=-1;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(a[i][j]==1 && cvis[i][j]==0)
                    {
                        int cnt=count_uninfected(i,j,a,cvis);
                        if(cnt>uinf)
                        {
                            uinf=cnt;
                            x=i;
                            y=j;
                        }
                    }
                }
            }
            // cout<<uinf<<" "<<x<<" "<<y<<endl;
            if(uinf==-1)break;
            walls+=build_walls(x,y,a);

            queue<pair<int,int>>q1;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(a[i][j]==1)q1.push({i,j});
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
                    if(issafe(nx,ny) && a[nx][ny]==0)a[nx][ny]=1;
                }
            }
        }
        return walls;
    }
};
