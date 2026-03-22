class Solution {
public:

    int n,m;
    vector<int>dx{-1,1,0,0};
    vector<int>dy{0,0,-1,1};

    bool issafe(int x,int y)
    {
        return x>=0 && y>=0 && x<n && y<m;
    }

    bool check(int mid,vector<vector<int>>a)
    {
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
            if(mid==0)break;
            mid--;
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
                    if(issafe(nx,ny) && a[nx][ny]==0)
                    {
                        a[nx][ny]=1;
                        q1.push({nx,ny});
                    }
                }
            }
        }
        if(a[0][0]!=0)return 0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[0][0]=1;

        queue<pair<int,int>>travel;
        travel.push({0,0});
        while(!travel.empty())
        {
            int sz=travel.size();
            while(sz--)
            {
                int px=travel.front().first;
                int py=travel.front().second;
                travel.pop();
                if(a[px][py]!=0)continue;
                for(int z=0;z<4;z++)
                {
                    int nx=px+dx[z];
                    int ny=py+dy[z];
                    if(issafe(nx,ny) && a[nx][ny]==0 && vis[nx][ny]==0)
                    {
                        vis[nx][ny]=1;
                        travel.push({nx,ny});
                    }
                }
            }

            sz=q1.size();
            while(sz--)
            {
                int x=q1.front().first;
                int y=q1.front().second;
                q1.pop();
                for(int z=0;z<4;z++)
                {
                    int nx=x+dx[z];
                    int ny=y+dy[z];
                    if(issafe(nx,ny) && a[nx][ny]==0)
                    {
                        a[nx][ny]=1;
                        q1.push({nx,ny});
                    }
                }
            }
        }
        return vis[n-1][m-1];
    }

    int maximumMinutes(vector<vector<int>>&a) 
    {
        n=a.size();
        m=a[0].size();
        int ans=-1;
        int l=0,r=1e9;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(check(mid,a))
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
    }
};
