#define ll long long
class Solution {
  public:
    
    ll n,m;
    ll dp[1001][1001];
    ll helper(int i,int j,vector<int>&a,vector<int>&b)
    {
        if(j>=m)return 0;
        if(i>=n)return INT_MIN;
        if(dp[i][j]!=-1)return dp[i][j];
        
        ll op1=a[i]*b[j]+helper(i+1,j+1,a,b);
        ll op2=helper(i+1,j,a,b);
        return dp[i][j]=max(op1,op2);
    }
  
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        n=a.size();
        m=b.size();
        memset(dp,-1,sizeof(dp));
        return helper(0,0,a,b);
    }
};
