class Solution {
  public:
    
    int helper(int i,int j,string&a,string&b,string&c,vector<vector<int>>&dp)
    {
        if(i+j>=c.size())return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        if(i<a.size() && a[i]==c[i+j])
        {
            int op=helper(i+1,j,a,b,c,dp);
            if(op)return dp[i][j]=1;
        }
        
        if(j<b.size() && b[j]==c[i+j])
        {
            int op=helper(i,j+1,a,b,c,dp);
            if(op)return dp[i][j]=1;
        }
        return dp[i][j]=0;
    }
  
    bool isInterleave(string &a, string &b, string &c) 
    {
        if(c.size()!=a.size()+b.size())return 0;
        vector<vector<int>>dp(a.size()+1,vector<int>(b.size()+1,-1));
        return helper(0,0,a,b,c,dp);
    }
};
