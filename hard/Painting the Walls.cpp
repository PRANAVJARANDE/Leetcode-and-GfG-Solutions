class Solution {
public:

    const int INF=1e9;
    int n;
    int helper(int in,int rem,vector<int>& cost, vector<int>& time,vector<vector<int>>&dp) 
    {
        if(rem<=0)return 0;
        if(in>=n)return INF;
        if(dp[in][rem]!=-1)return dp[in][rem];
        int op1=helper(in+1,rem,cost,time,dp);
        int op2=cost[in]+helper(in+1,rem-1-time[in],cost,time,dp);
        return dp[in][rem]=min(op1,op2);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) 
    {
        n=cost.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return helper(0,n,cost,time,dp);
    }
};
