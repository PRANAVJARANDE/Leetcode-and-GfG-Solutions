class Solution {
  public:
    
    int n,m;
    int helper(int i,int j,int k,vector<vector<int>>&a,vector<vector<vector<int>>>&dp)
    {
        if(k<0)return 0;
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        if(i==n-1 && j==m-1)
        {
            if(k==a[i][j])return dp[i][j][k]=1;
            return dp[i][j][k]=0;
        }
        int op1=0,op2=0;
        if(i+1<n)op1=helper(i+1,j,k-a[i][j],a,dp);
        if(j+1<m)op2=helper(i,j+1,k-a[i][j],a,dp);
        return dp[i][j][k]=op1+op2;
    }
  
    int numberOfPath(vector<vector<int>>& a, int k) {
        
        n=a.size(),m=a[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        return helper(0,0,k,a,dp);
    }
};
