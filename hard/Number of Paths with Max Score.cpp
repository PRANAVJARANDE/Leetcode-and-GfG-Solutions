class Solution {
public:

    int n,m;
    bool issafe(int i,int j)
    {
        return i>=0 && j>=0 && i<n && j<m;
    }

    vector<int>dx{-1,0,-1};
    vector<int>dy{0,-1,-1};

    const int MOD=1e9+7;

    vector<int> pathsWithMaxScore(vector<string>& a) 
    {
        n=a.size();
        m=a[0].size();

        a[0][0]='0';
        a[n-1][m-1]='0';

        vector<vector<int>>cnt(n,vector<int>(m,0));
        vector<vector<int>>dis(n,vector<int>(m,-1));
        dis[n-1][m-1]=0;
        cnt[n-1][m-1]=1;

        queue<pair<int,pair<int,int>>>q1;
        q1.push({0,{n-1,m-1}});

        while(!q1.empty())
        {
            auto tp=q1.front();
            q1.pop();

            int cst=tp.first;
            int x=tp.second.first;
            int y=tp.second.second;

            for(int z=0;z<3;z++)
            {
                int nx=x+dx[z];
                int ny=y+dy[z];

                if(issafe(nx,ny) && a[nx][ny]!='X')
                {
                    int ncst=cst+a[nx][ny]-'0';
                    if(dis[nx][ny]<ncst)
                    {
                        dis[nx][ny]=ncst;
                        cnt[nx][ny]=cnt[x][y];
                        q1.push({dis[nx][ny],{nx,ny}});
                    }
                    else if(dis[nx][ny]==ncst)
                    {
                        cnt[nx][ny]=((cnt[nx][ny]%MOD)+(cnt[x][y]%MOD))%MOD;
                    }
                }
            }
        }

        if(dis[0][0]==-1)return {0,0};
        return {dis[0][0],cnt[0][0]};
        
    }
};
