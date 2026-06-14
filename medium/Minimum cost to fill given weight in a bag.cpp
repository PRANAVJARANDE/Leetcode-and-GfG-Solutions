class Solution {
  public:
  
  
    // cost  :    20 10  4 50 100
    // dp    :  0  M  M  M  M   M
    // i        0  1  2  3  4   5
  
    int minimumCost(vector<int> &cost, int w) 
    {
       vector<int>dp(w+1,INT_MAX);
       dp[0]=0;
       
       for(int i=1;i<=w;i++)
       {
           for(int j=0;j<i;j++)
           {
               int wt=i-j;
               if(i-j-1>=cost.size())continue;
               if(cost[i-j-1]==-1)continue;
               if(dp[j]==INT_MAX)continue;
               int cst=dp[j]+cost[i-j-1];
               dp[i]=min(dp[i],cst);
           }
       }
       int ans=dp[w];
       if(ans==INT_MAX)ans=-1;
       return ans;
    }
};
