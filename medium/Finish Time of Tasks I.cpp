#define ll long long
class Solution {
public:

    vector<ll>ans;
    void helper(ll in,ll par,vector<vector<int>>&adj,vector<int>&b)
    {
        ll maxi=LLONG_MIN,mini=LLONG_MAX;
        for(auto x:adj[in])
        {
            if(x!=par)
            {
                helper(x,in,adj,b);
                maxi=max(maxi,ans[x]);
                mini=min(mini,ans[x]);
            }
        }
        if(maxi==LLONG_MIN)
        {
            ans[in]=b[in];
            return;
        }
        ll cbase=2*maxi-mini+b[in];
        ans[in]=cbase;
        return;
    }
    
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) 
    {
        if(n==1)return baseTime[0];
        vector<vector<int>>adj(n);
        for(auto x:edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        ans=vector<ll>(n,0);
        helper(0,-1,adj,baseTime);
        return ans[0];
    }
};
