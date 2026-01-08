class Solution {
public:
    int n,m;
    int helper(int i,int j,bool pv,vector<int>&nums1,vector<int>&nums2,vector<vector<vector<int>>>&dp)
    {
        if(i>=n || j>=m)
        {
            if(pv)return 0;
            return INT_MIN;
        }
        if(dp[i][j][pv]!=-1)return dp[i][j][pv];
        int op1=nums1[i]*nums2[j]+helper(i+1,j+1,1,nums1,nums2,dp);
        int op2=helper(i+1,j,pv,nums1,nums2,dp);
        int op3=helper(i,j+1,pv,nums1,nums2,dp);
        return dp[i][j][pv]=max(op1,max(op2,op3));
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) 
    {
        n=nums1.size();
        m=nums2.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(2,-1)));
        return helper(0,0,0,nums1,nums2,dp);
    }
};
