#define ll long long
class Solution {
public:

    map<ll,ll>mp;
    vector<int>v1;
    void update(ll node,ll l,ll r,vector<vector<ll>>&tree,ll in,int op)
    {
        if(l==r)
        {
            if(op==1)
            {
                tree[node][0]+=v1[in];
                tree[node][1]++;
            }
            else
            {
                tree[node][0]-=v1[in];
                tree[node][1]--;
            }
            return;
        }
        ll mid=l+(r-l)/2;
        if(in<=mid)update(2*node+1,l,mid,tree,in,op);
        else update(2*node+2,mid+1,r,tree,in,op);
        tree[node][0]=tree[2*node+1][0]+tree[2*node+2][0];
        tree[node][1]=tree[2*node+1][1]+tree[2*node+2][1];
    }

    ll query(ll node,ll l,ll r,vector<vector<ll>>&tree,ll&amt)
    {
        if(amt==0)return 0;
        if(tree[node][1]<=amt)
        {
            amt-=tree[node][1];
            return tree[node][0];
        }
        if(l==r)
        {
            ll res=tree[node][0]/tree[node][1];
            res*=amt;
            amt=0;
            return res;
        }
        ll mid=l+(r-l)/2;
        ll ans=query(2*node+1,l,mid,tree,amt)+query(2*node+2,mid+1,r,tree,amt);
        return ans;
    }

    long long minimumCost(vector<int>& nums, int k, int dist) 
    {
        v1=nums;
        sort(v1.begin(),v1.end());
        ll in=0;
        for(auto x:v1)mp[x]=in++;
        vector<vector<ll>>tree(4*in,vector<ll>(2,0));
        int n=nums.size();
        for(int i=n-1;i>=0;i--)
        {
            if(n-1-i<=dist)update(0,0,in-1,tree,mp[nums[i]],1);
            else break;
        }

        ll ans=LLONG_MAX;
        for(int i=n-1;i>=1;i--)
        {
            ll res=nums[0]+nums[i];
            update(0,0,in-1,tree,mp[nums[i]],-1);

            ll amt=k-2;
            ll tp=query(0,0,in-1,tree,amt);
            if(amt==0)
            {
                res+=tp;
                ans=min(ans,res);
            }
            if(i-dist-1>=1)update(0,0,in-1,tree,mp[nums[i-dist-1]],1);
        }
        return ans;
    }
};
