class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& a) 
    {
        int n=a.size();
        int m=a[0].size();
        vector<vector<int>>psum(n,vector<int>(m,0));
        for(int j=0;j<m;j++)
        {
            for(int i=n-1;i>=0;i--)
            {
                if(a[i][j])
                {
                    psum[i][j]++;
                    if(i+1<n)psum[i][j]+=psum[i+1][j];
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            sort(psum[i].begin(),psum[i].end(),greater<int>());
            for(int j=0;j<m;j++)ans=max(ans,(j+1)*psum[i][j]);
        }
        return ans;
    }
};
