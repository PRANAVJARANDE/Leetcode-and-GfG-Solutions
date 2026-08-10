class Solution {
  public:
    int n;
    int dp[100001][2];
    int helper(int in,bool pv,vector<int>&a,vector<int>&b)
    {
        if(in>=n)return 0;
        if(dp[in][pv]!=-1)return dp[in][pv];
        int op1=0;
        if(pv==0)op1=a[in]+helper(in+1,1,a,b);
        int op2=helper(in+1,0,a,b);
        int op3=b[in]+helper(in+1,1,a,b);
        return dp[in][pv]=max(op1,max(op2,op3));
    }
  
    int maxTask(vector<int>& h, vector<int>& l) 
    {
        n=h.size();
        memset(dp,-1,sizeof(dp));
        return helper(0,0,h,l);
    }
};


