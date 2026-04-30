class Solution {
public:

    int n,m;
    int helper(int i,int j,int k,vector<vector<int>>&a,vector<vector<vector<int>>>&dp)
    {
        int ncst=k;
        if(a[i][j]>=1)ncst--;
        if(ncst<0)return INT_MIN;
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        if(i==n-1 && j==m-1)return dp[i][j][k]=a[n-1][m-1];
        int op1=INT_MIN,op2=INT_MIN;
        if(i+1<n)op1=a[i][j]+helper(i+1,j,ncst,a,dp);
        if(j+1<m)op2=a[i][j]+helper(i,j+1,ncst,a,dp);
        return dp[i][j][k]=max(op1,op2);
    }

    int maxPathScore(vector<vector<int>>& a, int k) 
    {
        n=a.size();
        m=a[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        int ans=helper(0,0,k,a,dp);
        if(ans<0)ans=-1;
        return ans;
    }
};
