class Solution {
  public:
    
    int n;
    int helper(int in,vector<vector<int>>&a,vector<int>&dp)
    {
        if(in>=n)return 0;
        if(dp[in]!=-1)return dp[in];
        //skip
        int op1=helper(in+1,a,dp);
        
        //take 
        
        int e=a[in][1];
        int nx=n;
        int l=0,r=n-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(a[mid][0]>=e)
            {
                nx=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        
        int op2=a[in][2]+helper(nx,a,dp);
        return dp[in]=max(op1,op2);
    }    
  
    int maxProfit(vector<vector<int>> &a) 
    {
        n=a.size();
        sort(a.begin(),a.end());
        vector<int>dp(n,-1);
        int ans=helper(0,a,dp);
        return ans;
    }
};
