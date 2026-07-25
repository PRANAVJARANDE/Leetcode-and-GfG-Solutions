class Solution {
  public:
    int maximumSum(vector<vector<int>>& a, int k) 
    {
        int n=a.size();
        int m=a[0].size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i-1>=0)a[i][j]+=a[i-1][j];
                if(j-1>=0)a[i][j]+=a[i][j-1];
                if(i-1>=0 && j-1>=0)a[i][j]-=a[i-1][j-1];
            
                if(i>=k-1 && j>=k-1)
                {
                    int sum=a[i][j];
                    if(i-k>=0)sum-=a[i-k][j];
                    if(j-k>=0)sum-=a[i][j-k];
                    if(i-k>=0 && j-k>=0)sum+=a[i-k][j-k];
                    ans=max(ans,sum);
                }
            }
        }
        return ans;
    }
};
