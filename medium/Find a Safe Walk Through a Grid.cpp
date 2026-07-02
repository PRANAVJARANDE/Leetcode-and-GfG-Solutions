class Solution {
public:

    int n,m;
    bool issafe(int i,int j)
    {
        return i>=0 && j>=0 && i<n && j<m;
    }

    vector<int>dx{-1,1,0,0};
    vector<int>dy{0,0,-1,1};

    bool findSafeWalk(vector<vector<int>>& a, int health) 
    {
        n=a.size();
        m=a[0].size();

        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        dis[0][0]=a[0][0];

        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q1;
        q1.push({dis[0][0],{0,0}});

        while(!q1.empty())
        {
            auto tp=q1.top();
            q1.pop();

            int cst=tp.first;
            int x=tp.second.first;
            int y=tp.second.second;

            //if(cst>dis[x][y])continue;

            for(int z=0;z<4;z++)
            {
                int nx=x+dx[z];
                int ny=y+dy[z];
                if(issafe(nx,ny) && dis[nx][ny]>cst+a[nx][ny])
                {
                    dis[nx][ny]=cst+a[nx][ny];
                    q1.push({dis[nx][ny],{nx,ny}});
                }
            }
        }

        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         cout<<dis[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }


        return dis[n-1][m-1]<health;
    }
};
