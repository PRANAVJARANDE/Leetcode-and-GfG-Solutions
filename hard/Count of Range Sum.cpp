#define ll long long
class Solution {
public:

    ll query(int node,int i,int j,int l,int r,vector<ll>&tree)
    {
        if(l<=i && j<=r)return tree[node];
        if(j<l || r<i)return 0;
        int mid=i+(j-i)/2;
        return query(2*node+1,i,mid,l,r,tree)+query(2*node+2,mid+1,j,l,r,tree);
    }

    void update(int node,int i,int j,int in,vector<ll>&tree)
    {
        if(i==j)
        {
            tree[node]++;
            return;
        }
        int mid=i+(j-i)/2;
        if(in<=mid)update(2*node+1,i,mid,in,tree);
        else update(2*node+2,mid+1,j,in,tree);
        tree[node]=tree[2*node+1]+tree[2*node+2];
    }

    int countRangeSum(vector<int>& nums, int L, int U) 
    {
        int n=nums.size();
        vector<ll>psum(n+1,0);
        for(int i=1;i<=n;i++)psum[i]=nums[i-1]+psum[i-1];
        set<ll>s1;
        for(int i=0;i<=n;i++)
        {
            s1.insert(psum[i]);
            s1.insert(psum[i]-U);
            s1.insert(psum[i]-L);
        }
        map<ll,ll>ind;
        ll sz=0;
        for(auto x:s1)ind[x]=sz++;

        vector<ll>tree(4*sz,0);
        int ans=0;
        for(auto x:psum)
        {
            ans+=query(0,0,sz-1,ind[x-U],ind[x-L],tree);
            update(0,0,sz-1,ind[x],tree);
        }
        return ans;
    }
};
