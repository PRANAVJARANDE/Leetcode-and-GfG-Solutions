class Solution {
public:

    // val - {nx1 ny1} - acceptable values
    //     - {nx2 ny2} - acceptable values

    vector<vector<int>>op1{{0,1},{1,0},{0,-1},{0,1},{0,-1},{0,1}};
    vector<vector<int>>op2{{0,-1},{-1,0},{1,0},{1,0},{-1,0},{-1,0}};
    
    vector<set<int>>ac1{{1,3,5},{2,5,6},{1,4,6},{1,3,5},{1,4,6},{1,3,5}};
    vector<set<int>>ac2{{1,4,6},{3,4,2},{2,5,6},{2,5,6},{3,4,2},{3,4,2}};
    
    int n,m;
    bool issafe(int a,int b)
    {
        return a>=0 && b>=0 && a<n && b<m;
    }

    bool hasValidPath(vector<vector<int>>& a) 
    {
        n=a.size();
        m=a[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q1;
        vis[0][0]=1;
        q1.push({0,0});

        while(!q1.empty())
        {
            auto x=q1.front().first;
            auto y=q1.front().second;
            q1.pop();

            int val=a[x][y]-1;
            int nx1=x+op1[val][0];
            int ny1=y+op1[val][1];
            int nx2=x+op2[val][0];
            int ny2=y+op2[val][1];
            if(issafe(nx1,ny1) && vis[nx1][ny1]==0 && ac1[val].count(a[nx1][ny1])!=0)
            {
                vis[nx1][ny1]=1;
                q1.push({nx1,ny1});
            }
            if(issafe(nx2,ny2) && vis[nx2][ny2]==0 && ac2[val].count(a[nx2][ny2])!=0)
            {
                vis[nx2][ny2]=1;
                q1.push({nx2,ny2});
            }
        }

        return vis[n-1][m-1];
    
        
    }
};
