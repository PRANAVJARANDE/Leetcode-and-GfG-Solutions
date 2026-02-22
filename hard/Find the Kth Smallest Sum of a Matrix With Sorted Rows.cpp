class Solution {
public:

    int n,m;
    int helper(int in,int sum,vector<vector<int>>&a,vector<vector<int>>&dp)
    {
        if(sum<0)return 0;
        if(in>=n)return 1;
        if(dp[in][sum]!=-1)return dp[in][sum];
        int ans=0;
        for(int i=0;i<m;i++)
        {
            ans+=helper(in+1,sum-a[in][i],a,dp);
            if(ans>=300)
            {
                ans=300;
                break;
            }
        }
        return dp[in][sum]=ans;
    }

    int check(int mid,vector<vector<int>>&a)
    {
        vector<vector<int>>dp(n,vector<int>(mid+1,-1));
        return helper(0,mid,a,dp);
    }

    int kthSmallest(vector<vector<int>>& a, int k) 
    {
        n=a.size();
        m=a[0].size();
        int l=0,r=0;
        for(int i=0;i<n;i++)r+=a[i][m-1];
        int ans=-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(check(mid,a)>=k)
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};
