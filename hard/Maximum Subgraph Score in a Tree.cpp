class Solution {
public:

    vector<int>psum,ans;
    void helper(int in,int extra,int par,vector<vector<int>>&adj,vector<int>&good)
    {
        ans[in]=psum[in]+extra;
        int csum=psum[in];
        for(auto x:adj[in])
        {
            if(x!=par)
            {
                int tp=max(0,csum+extra-max(0,psum[x]));
                helper(x,tp,in,adj,good);
            }
        }
    }

    void build(int in,int par,vector<vector<int>>&adj,vector<int>&good)
    {
        int sum=0;
        for(auto x:adj[in])
        {
            if(x!=par)
            {
                build(x,in,adj,good);
                sum+=max(0,psum[x]);
            }
        }
        if(good[in])sum++;
        else sum--;
        psum[in]=sum;
    }

    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) 
    {
        vector<vector<int>>adj(n);
        for(auto x:edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }        
        ans=vector<int>(n,0);
        psum=vector<int>(n,0);
        build(0,-1,adj,good);
        helper(0,0,-1,adj,good);
        return ans;
    }
};
