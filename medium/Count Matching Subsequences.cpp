#define ll long long
class Solution {
  public:
  
    const ll MOD=1e9+7;
    ll dp[1001][1001];
    ll helper(ll i,ll j,string&s1,string&s2)
    {
        if(j>=s2.size())return 1;
        if(i>=s1.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        ll op1=helper(i+1,j,s1,s2);  
        ll op2=0;
        if(s1[i]==s2[j])op2=helper(i+1,j+1,s1,s2);
        return dp[i][j]=( op1%MOD + op2%MOD )%MOD;
    }
  
  
    int countWays(string &s1, string &s2) 
    {
        memset(dp,-1,sizeof(dp));
        return helper(0,0,s1,s2);
    }
};
