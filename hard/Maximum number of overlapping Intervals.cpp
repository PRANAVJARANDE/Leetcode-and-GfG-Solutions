class Solution {
  public:
    
    int overlapInt(vector<vector<int>> &a) 
    {
        vector<int>dp(20002,0);
        for(auto x:a)
        {
            dp[x[0]]++;
            dp[x[1]+1]--;
        }
        for(int i=1;i<20002;i++)dp[i]+=dp[i-1];
        int ans=0;
        for(auto x:dp)ans=max(ans,x);
        return ans;
    }
};
