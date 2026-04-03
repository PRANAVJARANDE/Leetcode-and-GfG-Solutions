#define ll long long
class Solution {
public:

    ll modInverse(ll base)
    {
        ll res=1;
        ll exp=MOD-2;
        while(exp)
        {
            if(exp%2)res=(res*base)%MOD;
            base=(base*base)% MOD;
            exp/=2;
        }
        return res;
    }

    vector<ll>fact,invFact;
    const int MOD=1e9+7;
    ll helper(ll in,vector<vector<ll>>&adj,vector<ll>&sz)
    {   
        ll res=1;
        for(auto x:adj[in])
        {
            res=((res%MOD)*(helper(x,adj,sz)%MOD))%MOD;
            sz[in]+=sz[x];
        }
        ll ans=fact[sz[in]];
        for(auto x:adj[in])ans=((ans%MOD)*(invFact[sz[x]])%MOD)%MOD;
        res=((res%MOD)*(ans%MOD))%MOD;
        sz[in]++;
        return res;
    }

    int waysToBuildRooms(vector<int>& par) 
    {
        ll n=par.size();
        vector<vector<ll>>adj(n);
        fact=vector<ll>(n+1,1);
        invFact=vector<ll>(n+1,1);
        for(int i=1;i<=n;i++)fact[i]=(fact[i-1]*i)%MOD;
        invFact[n]=modInverse(fact[n]);
        for(int i=n-1;i>=0;i--)invFact[i]=(invFact[i+1]*(i+1))%MOD; 
        for(int i=1;i<n;i++)adj[par[i]].push_back(i);
        vector<ll>sz(n,0);
        return helper(0,adj,sz);
    }
};
