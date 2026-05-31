class Solution {
public:

    void add(int node,int i,int j,int in,int val,vector<int>&tree)
    {
        if(i==j)
        {
            tree[node]=val;
            return;
        }
        int mid=i+(j-i)/2;
        if(in<=mid)add(2*node+1,i,mid,in,val,tree);
        else add(2*node+2,mid+1,j,in,val,tree);
        tree[node]=max(tree[2*node+1],tree[2*node+2]);
    }

    int query(int node,int i,int j,int l,int r,vector<int>&tree)
    {
        if(l<=i && j<=r)return tree[node];
        if(j<l || r<i)return 0;
        int mid=i+(j-i)/2;
        return max(query(2*node+1,i,mid,l,r,tree),query(2*node+2,mid+1,j,l,r,tree));
    }

    vector<bool> getResults(vector<vector<int>>& queries) 
    {
        int mx=100005;

        set<int>s1;
        vector<int>dis(mx,0);
        s1.insert(0);
        dis[0]=mx;

        vector<int>tree(4*mx,0);

        vector<bool>ans;
        for(auto x:queries)
        {
            if(x[0]==1)
            {
                int nb=x[1];
                auto itr=s1.lower_bound(nb);
                itr--;
                int v=*itr;
                dis[nb]=v+dis[v]-nb;
                dis[v]=nb-v;
                s1.insert(nb);
                add(0,0,mx-1,v,dis[v],tree);
                add(0,0,mx-1,nb,dis[nb],tree);
            }
            else
            {
                int nb=x[1];
                int sz=x[2];
                int res=query(0,0,mx-1,0,nb-sz,tree);
                if(res>=sz)ans.push_back(1);
                else ans.push_back(0);
            }
        }
        return ans;
    }
};
