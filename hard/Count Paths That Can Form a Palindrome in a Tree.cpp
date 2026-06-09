#define ll long long
class Solution {
public:

    int n;
    vector<vector<vector<int>>>adj;
    vector<int>mask;
    unordered_map<int,int>maskcnt;

    void build(int in,int cmask)
    {
        mask[in]=cmask;
        maskcnt[cmask]++;
        for(auto x:adj[in])
        {
            int nmask=cmask;
            int v=x[1];
            nmask=nmask^(1<<v);
            build(x[0],nmask);
        }
    }

    ll helper(int in)
    {
        int cmask=mask[in];
        ll res=maskcnt[cmask]-1;
        for(int i=0;i<26;i++)
        {
            if(!(cmask & (1<<i)))res+=maskcnt[cmask | (1<<i)];
            else res+=maskcnt[cmask ^ (1<<i)];
        }
        for(auto x:adj[in])res+=helper(x[0]);
        return res;
    }

    long long countPalindromePaths(vector<int>& parent, string s) 
    {
        n=parent.size();
        adj=vector<vector<vector<int>>>(n);
        for(int i=1;i<n;i++)adj[parent[i]].push_back({i,s[i]-'a'});
        mask=vector<int>(n,0);
        build(0,0);
        ll ans=helper(0)/2;
        return ans;
    }
};
