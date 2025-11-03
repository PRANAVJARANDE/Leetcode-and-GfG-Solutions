class Solution {
public:

    vector<int> toptlogicalsort(int n,vector<vector<int>>&adj,vector<int>&indeg)
    {
        vector<int> ans;
        queue<int> q1;
        for(int i=0;i<n;i++)
        {
            if(indeg[i]==0 )
            {
                q1.push(i);
            }
        }
            while(!q1.empty())
            {
                int k=q1.front();
                q1.pop();
                ans.push_back(k);
                for(int x: adj[k])
                {
                    indeg[x]--;
                    if(indeg[x]==0)
                    {
                        q1.push(x);
                    }
                }
            }
        
        if(ans.size()==n)
        {
            return ans;
        }
        return {};
    }

    vector<int> findOrder(int n, vector<vector<int>>& pre) 
    {
        vector<int> indeg(n,0);
        vector<vector<int>> adj(n);
        for(auto x: pre)
        {
            indeg[x[0]]++;
            adj[x[1]].push_back(x[0]);
        }
    
        return toptlogicalsort(n,adj,indeg);
    }
};


// Gfg --------------------------------------------------------------
class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) 
    {
        vector<vector<int>>adj(n);
        vector<int>deg(n);
        for(auto x:prerequisites)
        {
            deg[x[0]]++;
            adj[x[1]].push_back(x[0]);
        }
        queue<int>q1;
        vector<int>vis(n,0);
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(deg[i]==0)
            {
                ans.push_back(i);
                q1.push(i);
                vis[i]=1;
            }
        }
        while(!q1.empty())
        {
            auto in=q1.front();
            q1.pop();
            for(auto x:adj[in])
            {
                if(vis[x]==0)
                {
                    deg[x]--;
                    if(deg[x]==0)
                    {
                        q1.push(x);
                        vis[x]=1;
                        ans.push_back(x);
                    }
                }
            }
        }
        if(ans.size()==n)return ans;
        return vector<int>(0);
        
    }
};
