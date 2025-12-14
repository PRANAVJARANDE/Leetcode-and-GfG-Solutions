class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>>&a, vector<vector<int>>&q) 
    {
        int n=a.size();
        int m=a[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i-1>=0)a[i][j]+=a[i-1][j];
                if(j-1>=0)a[i][j]+=a[i][j-1];
                if(i-1>=0 && j-1>=0)a[i][j]-=a[i-1][j-1];
            }
        }
        
        vector<int>ans(q.size());
        for(int i=0;i<q.size();i++)
        {
            ans[i]=a[q[i][2]][q[i][3]];
            q[i][0]--;
            q[i][1]--;
            if(q[i][0]>=0)ans[i]-=a[q[i][0]][q[i][3]];
            if(q[i][1]>=0)ans[i]-=a[q[i][2]][q[i][1]];
            if(q[i][0]>=0 && q[i][1]>=0)ans[i]+=a[q[i][0]][q[i][1]];
        }
        return ans;
    }
};
