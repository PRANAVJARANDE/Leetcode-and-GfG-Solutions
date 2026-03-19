class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>x(n,vector<int>(m,0));
        vector<vector<int>>y(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='X')x[i][j]++;
                if(grid[i][j]=='Y')y[i][j]++;
                if(i-1>=0)
                {
                    x[i][j]+=x[i-1][j];
                    y[i][j]+=y[i-1][j];
                }
                if(j-1>=0)
                {
                    x[i][j]+=x[i][j-1];
                    y[i][j]+=y[i][j-1];
                }
                if(i-1>=0 && j-1>=0)
                {
                    x[i][j]-=x[i-1][j-1];
                    y[i][j]-=y[i-1][j-1];
                }
                if(x[i][j]==y[i][j] && x[i][j]!=0)ans++;
            }
        }
        return ans;
    }
};
