#define ll long long
class Solution {
public:

    const ll INF=1e15;
    ll helper(int in,int tk,vector<ll>&v1,vector<vector<ll>>&dp)
    {
        if(in>=v1.size())return 0;
        if(dp[in][tk]!=-1)return dp[in][tk];
        ll op1=INF;
        if(tk==0)op1=helper(in+1,1,v1,dp);
        ll op2=v1[in]+helper(in+2,tk,v1,dp);
        return dp[in][tk]=min(op1,op2);
    }

    long long minIncrease(vector<int>&nums) 
    {
        ll n=nums.size();
        vector<ll>cost;
        for(int i=1;i<n-1;i++)cost.push_back(max(0,1+max(nums[i+1],nums[i-1])-nums[i]));
        ll op1=0;
        for(int i=0;i<cost.size();i+=2)op1+=cost[i];
        if(n%2)return op1;

        vector<vector<ll>>dp(n,vector<ll>(2,-1));
        return helper(0,0,cost,dp);
    }
};

