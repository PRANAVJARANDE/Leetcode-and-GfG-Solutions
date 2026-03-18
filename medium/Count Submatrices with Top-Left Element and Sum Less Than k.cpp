class Solution {
public:
    int countSubmatrices(vector<vector<int>>& a, int k) 
    {
        int n=a.size();
        int m=a[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i-1>=0)a[i][j]+=a[i-1][j];
                if(j-1>=0)a[i][j]+=a[i][j-1];
                if(i-1>=0 && j-1>=0)a[i][j]-=a[i-1][j-1];
                if(a[i][j]<=k)ans++;
            }
        }
        return ans;  
    }
};
