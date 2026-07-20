class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& a, int k) 
    {
        int n=a.size(),m=a[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int in=i*m+j;
                int nin=(in+k)%(n*m);

                int ni=nin/m;
                int nj=nin%m;
                ans[ni][nj]=a[i][j];
            }
        }
        return ans;
    }
};
