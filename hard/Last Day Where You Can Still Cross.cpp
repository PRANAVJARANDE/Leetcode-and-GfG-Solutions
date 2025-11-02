class Solution {
public:

    int n,m;
    bool issafe(int x,int y)
    {
        if(x>=0 && y>=0 && x<n && y<m)return 1;
        return 0;
    }
    vector<int>dx{-1,1,0,0};
    vector<int>dy{0,0,-1,1};

    int latestDayToCross(int nn, int mm, vector<vector<int>>& pts) 
    {
        n=nn;
        m=mm;
        vector<vector<int>>a(n,vector<int>(m,0));
        for(auto &x:pts)
        {
            x[0]--;
            x[1]--;
            a[x[0]][x[1]]=1;
        }

        vector<vector<int>>val(n,vector<int>(m,-1));
        queue<pair<int,int>>q1;

        for(int i=0;i<m;i++)
        {
            if(a[n-1][i]==0)
            {
                val[n-1][i]=1;
                q1.push({n-1,i});
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
                if(issafe(nx,ny) && a[nx][ny]==0 && val[nx][ny]==-1)
                {
                    val[nx][ny]=1;
                    q1.push({nx,ny});
                }
            }
        }

        int sz=pts.size();

        for(int i=0;i<m;i++)
        {
            if(a[0][i]==0)
            {
                if(val[0][i]==1)return sz; 
                val[0][i]=0;
                q1.push({0,i});
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
                if(issafe(nx,ny) && a[nx][ny]==0 && val[nx][ny]==-1)
                {
                    val[nx][ny]=0;
                    q1.push({nx,ny});
                }
            }
        }

        for(int i=sz-1;i>=0;i--)
        {
            int x=pts[i][0],y=pts[i][1];
            int maxi=-1;

            for(int z=0;z<4;z++)
            {
                int nx=x+dx[z];
                int ny=y+dy[z];
                if(issafe(nx,ny))maxi=max(maxi,val[nx][ny]);
            }

            if(x==0)maxi=max(maxi,0);
            if(x==n-1)maxi=max(maxi,1);

            a[x][y]=0;
            val[x][y]=maxi;

            queue<pair<int,int>>q1;
            q1.push({x,y});

            while(!q1.empty())
            {
                int cx=q1.front().first;
                int cy=q1.front().second;
                q1.pop();

                if(maxi==1 && cx==0)return i; 

                for(int z=0;z<4;z++)
                {
                    int nx=cx+dx[z];
                    int ny=cy+dy[z];
                    if(issafe(nx,ny) && a[nx][ny]==0 && val[nx][ny]!=maxi)
                    {
                        val[nx][ny] = maxi; 
                        q1.push({nx,ny});
                    }
                }
            }
        }
        return 0;
    }
};
