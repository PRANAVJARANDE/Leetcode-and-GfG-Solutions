#define ll long long
class Solution {
  public:
        
    ll n,m;
    ll helper(int i,int j,string&a,string&b,vector<vector<ll>>&dp)
    {
        if(i>=n && j>=m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        ll op1=INT_MAX,op2=INT_MAX,op3=INT_MAX;
        if(i<n && j<m && a[i]==b[j])op1=1+helper(i+1,j+1,a,b,dp);
        if(i<n)op2=1+helper(i+1,j,a,b,dp);
        if(j<m)op3=1+helper(i,j+1,a,b,dp);
        return dp[i][j]=min(op1,min(op2,op3));
    }
  
    int minSuperSeq(string &s1, string &s2)
    {
        n=s1.size();
        m=s2.size();
        vector<vector<ll>>dp(n+1,vector<ll>(m+1,-1));
        return helper(0,0,s1,s2,dp);
    }
};
