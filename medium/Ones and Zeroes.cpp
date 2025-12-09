class Solution {
public:

    int helper(int in,int m,int n,vector<pair<int,int>>&a,vector<vector<vector<int>>>&dp)
    {
        if(m<0 || n<0)return INT_MIN;
        if(in>=a.size())return 0;

        if(dp[in][m][n]!=-1)return dp[in][m][n];

        int op1=helper(in+1,m,n,a,dp);
        int op2=1+helper(in+1,m-a[in].first,n-a[in].second,a,dp);
        return dp[in][m][n]=max(op1,op2);
    }

    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        vector<pair<int,int>>v1;
        for(auto x:strs)
        {
            int zc=0,oc=0;
            for(auto c:x)
            {
                if(c=='0')zc++;
                else oc++;
            }
            v1.push_back({zc,oc});
        }
        vector<vector<vector<int>>>dp(v1.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        int ans=helper(0,m,n,v1,dp);
        return ans;
    }
};
