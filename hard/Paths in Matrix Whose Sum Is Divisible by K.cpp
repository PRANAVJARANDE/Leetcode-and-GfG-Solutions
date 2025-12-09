class Solution {
public:

    int n,m;
    const int MOD=1e9+7;
    int helper(int i,int j,int s,int k,vector<vector<int>>&a,vector<vector<vector<int>>>&dp)
    {
        int cs=(s+a[i][j])%k;
        if(i==n-1 && j==m-1)
        {
            if(cs==0)return 1;
            return 0;
        }
        if(dp[i][j][s]!=-1)return dp[i][j][s];
        int op1=0;
        if(i+1<n)op1=helper(i+1,j,cs,k,a,dp);
        int op2=0;
        if(j+1<m)op2=helper(i,j+1,cs,k,a,dp);
        return dp[i][j][s]=((op1%MOD) + (op2%MOD))%MOD;
    }

    int numberOfPaths(vector<vector<int>>& a, int k) 
    {
        n=a.size();
        m=a[0].size();  
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        int ans=helper(0,0,0,k,a,dp);
        return ans;      
    }
};
