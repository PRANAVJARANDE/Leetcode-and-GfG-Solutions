class Solution {
  public:
        
    int n,m;
    vector<int>dx{-1,1,0,0};
    vector<int>dy{0,0,-1,1};
    bool issafe(int i,int j)
    {
        return i>=0 && j>=0 && i<n && j<m;
    }
    int xd,yd;
    int ans;
    void helper(int i,int j,int cnt,vector<vector<int>>&a)
    {
        if(i==xd && j==yd)
        {
            ans=max(ans,cnt);
            return;
        }
        a[i][j]=0;
        for(int z=0;z<4;z++)
        {
            int nx=i+dx[z];
            int ny=j+dy[z];
            if(issafe(nx,ny) && a[nx][ny]==1)
            {
                helper(nx,ny,cnt+1,a);
            }
        }
        a[i][j]=1;
    }

    int longestPath(vector<vector<int>>& mat, int xs, int ys, int xd, int yd) 
    {
        this->xd=xd;
        this->yd=yd;
        ans=INT_MIN;
        n=mat.size();
        m=mat[0].size();
        helper(xs,ys,0,mat);
        if(ans==INT_MIN)ans=-1;
        return ans;
    }
};
