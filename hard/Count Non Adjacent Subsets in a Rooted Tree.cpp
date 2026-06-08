#define ll long long
class Solution {
public:

    int k;
    vector<vector<int>>adj;
    vector<vector<vector<ll>>>dp;
    const int MOD=1e9+7;
    void helper(int in,int par,vector<int>&nums)
    {
        dp[in][0][0]=1;
        dp[in][1][nums[in]%k]=1;
        for(auto x:adj[in])
        {
            if(x!=par)
            {
                
                helper(x,in,nums);
                vector<ll>temp1(k,0);
                vector<ll>temp2(k,0);
                for(int i=0;i<k;i++)
                {
                    for(int j=0;j<k;j++)
                    {
                        temp1[(i+j)%k]=(temp1[(i+j)%k]+dp[in][1][i]*dp[x][0][j])%MOD;
                        temp2[(i+j)%k]=(temp2[(i+j)%k]+dp[in][0][i]*((dp[x][0][j]+dp[x][1][j])%MOD))%MOD;
                    }
                }
                dp[in][1]=temp1;
                dp[in][0]=temp2;
            }
        }
    }


    int countValidSubsets(vector<int>& parent,vector<int>& nums, int k) 
    {
        this->k=k;
        int n=parent.size();
        adj=vector<vector<int>>(n);
        for(int i=1;i<n;i++)
        {
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
        dp=vector<vector<vector<ll>>>(n,vector<vector<ll>>(2,vector<ll>(k,0)));
        helper(0,-1,nums);

        ll ans=((dp[0][1][0]%MOD)+(dp[0][0][0]%MOD)-1+MOD)%MOD;
        return ans;
    }
};




    

   
