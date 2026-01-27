class Solution {
  public:
    
    int n,m;
    
    bool issafe(int i,int j)
    {
        return i>=0 && j>=0 && i<n && j<m;
    }
    
    vector<int>dx{-1,1,0,0};
    vector<int>dy{0,0,-1,1};
    bool helper(int i,int j,int in,vector<vector<int>>&vis,vector<vector<char>> &mat, string &word)
    {
        if(in>=word.size())return 1;
        if(word[in]==mat[i][j])
        {
            if(in==word.size()-1)return 1;
            for(int z=0;z<4;z++)
            {
                int nx=i+dx[z];
                int ny=j+dy[z];
                if(issafe(nx,ny) && vis[nx][ny]==0)
                {
                    vis[nx][ny]=1;
                    if(helper(nx,ny,in+1,vis,mat,word))return 1;
                    vis[nx][ny]=0;
                }
            }
        }
        return 0;
    }
    
  
    bool isWordExist(vector<vector<char>> &mat, string &word) 
    {
        n=mat.size();
        m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                vis[i][j]=1;
                if(helper(i,j,0,vis,mat,word))return 1;
                vis[i][j]=0;
            }
        }
        return 0;
    }
};
