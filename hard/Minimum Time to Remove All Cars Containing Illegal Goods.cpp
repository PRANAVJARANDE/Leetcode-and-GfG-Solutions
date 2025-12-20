#define ll long long
class Solution {
public:

    ll n;
    ll helper(int in,int cnt,vector<int>&v1,vector<vector<int>>&dp)
    {
        if(cnt>=2)return 0;
        if(in>=v1.size())return INT_MAX;
        if(dp[in][cnt]!=-1)return dp[in][cnt];
        if(cnt==0)
        {
            //skip
            ll op1=helper(in+1,cnt,v1,dp);
            //take left stop
            ll op2=(v1[in]+1)+helper(in+1,1,v1,dp);
            return dp[in][cnt]=min(op1,op2);
        }
        else
        {
            //skip
            ll op1=2+helper(in+1,cnt,v1,dp);
            //take right stop
            ll op2=(n-v1[in])+helper(in+1,2,v1,dp);
            return dp[in][cnt]=min(op1,op2);
        }
    }

    int minimumTime(string s) 
    {
        n=s.size();
        vector<int>v1;
        v1.push_back(-1);
        for(int i=0;i<n;i++)if(s[i]=='1')v1.push_back(i);
        v1.push_back(n);

        vector<vector<int>>dp(v1.size(),vector<int>(3,-1));
        return helper(0,0,v1,dp);
    }
};
