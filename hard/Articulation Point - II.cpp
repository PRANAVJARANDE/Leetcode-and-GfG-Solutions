#define ll long long
class Solution {
  public:
    
    ll timer;
    void dfs(ll in,ll par,vector<vector<ll>>&adj,vector<ll>&id,vector<ll>&low,vector<ll>&isArt)
    {
        id[in]=timer;
        low[in]=timer;
        timer++;
        
        ll child=0;
        for(auto x:adj[in])
        {
            if(x!=par)
            {
                if(id[x]==-1)   
                {
                    dfs(x,in,adj,id,low,isArt);
                    low[in]=min(low[in],low[x]);
                    if(low[x]>=id[in] && par!=-1)isArt[in]=1;
                    child++;
                }
                else
                {
                    low[in]=min(low[in],id[x]);
                }
            }
        }
        if(par==-1 && child>1)isArt[in]=1;
    }

  
    vector<int> articulationPoints(int n, vector<vector<int>>& edges) 
    {
        vector<vector<ll>>adj(n);
        for(auto &e:edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<ll>id(n,-1),low(n,-1),isArt(n,0);
        timer=0;
        for(int i=0;i<n;i++)if(id[i]==-1)dfs(i,-1,adj,id,low,isArt);
        vector<int>ans;
        for(int i=0;i<n;i++)if(isArt[i])ans.push_back(i);
        if(ans.empty())return {-1};
        return ans;
    }
};
