#define ll long long
class Solution {
public:
 
    /*
        1 0 1 0 1 1 0 1 1 1 0

        i       j 

        cnt1 = psum[j]-psum[i-1]
        size = j-(i-1)

        cnt0 = (j-(i-1)) - (psum[j]-psum[i-1])

        cnt0 = size - cnt1

        want
        cnt1>cnt0
        cnt1> size - cnt1
        2*cnt1 > size

        2psum[j] - 2psum[i-1] > j - (i-1)

        2psum[j] - j > 2psum[i-1]-(i-1)

    */

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

    ll query(int node,int i,int j,int l,int r,vector<ll>&tree)
    {
        if(l>r)return 0;
        if(j<l || r<i)return 0;
        if(l<=i && j<=r)return tree[node];
        int mid=i+(j-i)/2;
        return query(2*node+1,i,mid,l,r,tree)+query(2*node+2,mid+1,j,l,r,tree);
    }

    long long countMajoritySubarrays(vector<int>& nums, int target) 
    {
        ll n=nums.size();
        for(auto &x:nums)
        {
            if(x==target)x=1;
            else x=0;
        }
        int OFFSET=n+2;
        for(int i=1;i<n;i++)nums[i]+=nums[i-1];
        ll sz=2*n + 10;
        vector<ll>tree(4*sz,0);
        update(0,0,sz-1,1+OFFSET,tree);

        ll ans=0;
        for(int j=0;j<n;j++)
        {
            int curr=2*nums[j]-j;
            ans+=query(0,0,sz-1,0,curr+OFFSET-1,tree);
            update(0,0,sz-1,curr+OFFSET,tree);    
        }
        return ans;
    }
};
