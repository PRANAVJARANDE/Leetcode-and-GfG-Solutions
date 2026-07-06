class Solution {
  public:
    
    int dp[10001][2];
    int helper(int in,int flag,vector<int>&a,vector<int>&b)
    {
        if(flag==0 && in>=a.size())return 0;
        if(flag==1 && in>=b.size())return 0;
        
        if(dp[in][flag]!=-1)return dp[in][flag];
        
        int op1=helper(in+1,flag,a,b);
        if(flag==0)op1+=a[in];
        else op1+=b[in];
        
        int op2=INT_MIN;
        if(flag==0)
        {
            auto vin=lower_bound(b.begin(),b.end(),a[in])-b.begin();
            if(vin!=b.size() && b[vin]==a[in])
            {
                op2=a[in]+helper(vin+1,1,a,b);
            }
        }
        else
        {
            auto vin=lower_bound(a.begin(),a.end(),b[in])-a.begin();
            if(vin!=a.size() && a[vin]==b[in])
            {
                op2=b[in]+helper(vin+1,0,a,b);
            }
        }
        return dp[in][flag]=max(op1,op2);
    }
  
  
    int maxPathSum(vector<int> &a, vector<int> &b) {
        memset(dp,-1,sizeof(dp));
        return max(helper(0,0,a,b),helper(0,1,a,b));
    }
};
