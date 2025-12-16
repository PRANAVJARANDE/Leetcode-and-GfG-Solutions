#define ll long long
class Solution {
public:

    int b;
    vector<vector<int>>adj;
    vector<vector<vector<int>>>dp;

    vector<int>merge(vector<int>&v1,vector<int>&v2)
    {
        vector<int>res(b+1,INT_MIN);
        for(int i=0;i<=b;i++)
        {
            if(v1[i]<0)continue;
            for(int j=0;j<=b;j++)
            {
                if(v2[j]<0)continue;
                if(i+j<=b)
                {
                    res[i+j]=max(res[i+j],v1[i]+v2[j]);
                }
            }
        }
        return res;
    }

    void helper(int in,vector<int>&cp,vector<int>&sp)
    {
        for(auto x:adj[in])helper(x,cp,sp);

        //no par_buy 
        int profit1=sp[in]-cp[in];

        //ntake
        vector<int>ntake1(b+1,0);
        for(auto x:adj[in])ntake1=merge(ntake1,dp[x][0]);
        //take
        vector<int>take1(b+1,INT_MIN);
        if(cp[in]<=b)
        {
            vector<int>temp(b+1,0);
            for(auto x:adj[in])temp=merge(temp,dp[x][1]);
            for(int j=cp[in];j<=b;j++)take1[j]=temp[j-cp[in]]+profit1;
        }
        for(int i=0;i<=b;i++)dp[in][0][i]=max(ntake1[i],take1[i]);


        //par_buy
        int profit2=sp[in]-(cp[in]/2);
        //ntake
        vector<int>ntake2(b+1,0);
        for(auto x:adj[in])ntake2=merge(ntake2,dp[x][0]);
        //take
        vector<int>take2(b+1,INT_MIN);
        if((cp[in]/2)<=b)
        {
            vector<int>temp(b+1,0);
            for(auto x:adj[in])temp=merge(temp,dp[x][1]);
            for(int j=(cp[in]/2);j<=b;j++)take2[j]=temp[j-(cp[in]/2)]+profit2;
        }
        for(int i=0;i<=b;i++)dp[in][1][i]=max(ntake2[i],take2[i]);
    }

    int maxProfit(int n,vector<int>& cp,vector<int>&sp,vector<vector<int>>&edg,int budget) 
    {
        b=budget;
        adj=vector<vector<int>>(n);
        for(auto x:edg)adj[x[0]-1].push_back(x[1]-1);
        dp=vector<vector<vector<int>>>(n,vector<vector<int>>(2,vector<int>(b+1,INT_MIN)));

        helper(0,cp,sp);

        int ans=0;
        for(int i=0;i<=b;i++)ans=max(ans,dp[0][0][i]);
        return ans;
    }
};
