class Solution {
public:

    int n,m;
    vector<int>dx{-1,1,0,0};
    vector<int>dy{0,0,1,-1};

    bool issafe(int a,int b)
    {
        return a>=0 && b>=0 && a<n && b<m;
    }

    bool canvisit(int x,int y,int tx,int ty,vector<vector<char>>&a,int bx,int by)
    {
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q1;
        q1.push({x,y});
        vis[x][y]=1;
        while(!q1.empty())
        {
            auto pr=q1.front();
            q1.pop();

            for(int z=0;z<4;z++)
            {
                int nx=pr.first+dx[z];
                int ny=pr.second+dy[z];
                if(issafe(nx,ny) && !vis[nx][ny] && a[nx][ny]!='#' && !(nx==bx && ny==by))
                {
                    vis[nx][ny]=1;
                    q1.push({nx,ny});
                }
            }
        }
        return vis[tx][ty];
    }

    int minPushBox(vector<vector<char>>&a) 
    {
        n=a.size();
        m=a[0].size();
        int sx=-1,sy=-1,tx=-1,ty=-1,bx=-1,by=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]=='S')sx=i,sy=j;
                else if(a[i][j]=='B')bx=i,by=j;
                else if(a[i][j]=='T')tx=i,ty=j;
            }
        }
        a[sx][sy]='.';
        a[tx][ty]='.';
        vector<vector<vector<vector<int>>>>dis(n,vector<vector<vector<int>>>(m,vector<vector<int>>(n,vector<int>(m,1e9))));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q1;

        for(int z=0;z<4;z++)
        {
            int px=bx-dx[z];
            int py=by-dy[z];

            int nbx=bx+dx[z];
            int nby=by+dy[z];

            if(issafe(px,py) && issafe(nbx,nby) && a[px][py]!='#' && a[nbx][nby]!='#')
            {
                if(canvisit(sx,sy,px,py,a,bx,by))
                {
                    dis[bx][by][px][py]=0;
                    q1.push({0,bx,by,px,py});
                }
            }
        }

        while(!q1.empty())
        {
            auto pr=q1.top();
            q1.pop();

            int cst=pr[0];
            int cbx=pr[1];
            int cby=pr[2];
            int csx=pr[3];
            int csy=pr[4];
            if(cst>dis[cbx][cby][csx][csy])continue;
            if(cbx==tx && cby==ty)return cst;

            for(int z=0;z<4;z++)
            {
                int px=cbx-dx[z];
                int py=cby-dy[z];

                int nbx=cbx+dx[z];
                int nby=cby+dy[z];

                if(issafe(px,py) && issafe(nbx,nby) && a[px][py]!='#' && a[nbx][nby]!='#' && canvisit(csx,csy,px,py,a,cbx,cby))
                {
                    if(dis[nbx][nby][cbx][cby]>cst+1)
                    {
                        dis[nbx][nby][cbx][cby]=cst+1;
                        q1.push({cst+1,nbx,nby,cbx,cby});
                    }
                }
            }
        }
        return -1;
    }
};
