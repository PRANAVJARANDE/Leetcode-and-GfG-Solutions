class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) 
    {
        int n=mat.size();
        bool flag1=1,flag2=1,flag3=1,flag4=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(target[i][j]!=mat[n-j-1][i])flag1=0;
                if(target[i][j]!=mat[n-i-1][n-j-1])flag2=0;    
                if(target[i][j]!=mat[j][n-i-1])flag3=0;
                if(target[i][j]!=mat[i][j])flag4=0;
            }
        }
        return flag1 || flag2 || flag3 || flag4;
    }
};
