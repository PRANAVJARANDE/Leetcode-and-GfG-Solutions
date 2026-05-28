class Solution {
  public:
    
    int n;
    int helper(int in,int pv,string&s,vector<vector<int>>&dp)
    {
        if(in>=n)return 1;
        if(dp[in][pv]!=-1)return dp[in][pv];
        int ans=0;
        int cs=0;
        for(int i=in;i<n;i++)
        {
            cs+=s[i]-'0';
            if(cs>=pv)
            {
                ans+=helper(i+1,cs,s,dp);
            }
        }
        return dp[in][pv]=ans;
    }
  
  
    int validGroups(string &s) 
    {
        n=s.size();
        vector<vector<int>>dp(n,vector<int>(n*9,-1));
        return helper(0,0,s,dp);
    }
};
