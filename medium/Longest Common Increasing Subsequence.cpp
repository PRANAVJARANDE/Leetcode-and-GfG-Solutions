class Solution {
public:
    int LCIS(vector<int> &a, vector<int> &b) 
    {
        int n=a.size(),m=b.size();
        vector<int>dp(m,0);
        for(int i=0;i<n;i++) 
        {
            int best=0;
            for(int j=0;j<m;j++) 
            {
                if(a[i]>b[j])best=max(best,dp[j]);
                else if(a[i]==b[j])dp[j]=best+1;
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
