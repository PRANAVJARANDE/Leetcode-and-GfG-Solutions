class Solution {
  public:
    
    int n;
    int dp[9][100];
    int helper(int in,int sum)
    {
        if(sum<0)return 0;
        if(in>=n)return sum==0;
        if(dp[in][sum]!=-1)return dp[in][sum];
        
        int st=0;
        if(in==0)st=1;
        
        int ans=0;
        for(int i=st;i<=9;i++)
        {
            ans+=helper(in+1,sum-i);
        }
        return dp[in][sum]=ans;
    }
  
  
    int countWays(int n, int sum) 
    {
        this->n=n;
        memset(dp,-1,sizeof(dp));
        int res=helper(0,sum);
        if(res==0)res=-1;
        return res;
    }
};
