class Solution {
public:

    vector<int>maxi,mini,lazy;
    int n;
    void push(int node,int l,int r) 
    {
        if(lazy[node]!=0) 
        {
            maxi[node]+=lazy[node];
            mini[node]+=lazy[node];
            if(l!=r) 
            {
                lazy[2*node+1]+=lazy[node];
                lazy[2*node+2]+=lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void build(int node,int l,int r,vector<int>&psum) 
    {
        if(l==r) 
        {
            maxi[node]=mini[node]=psum[l];
            return;
        }
        int mid=(l+r)/2;
        build(2*node+1,l,mid,psum);
        build(2*node+2,mid+1,r,psum);
        maxi[node]=max(maxi[2*node+1],maxi[2*node+2]);
        mini[node]=min(mini[2*node+1],mini[2*node+2]);
    }

    void range_add(int node,int l,int r,int ql,int qr,int val) 
    {
        push(node,l,r);
        if(r<ql || l>qr)return;
        if(ql<=l && r<=qr)
        {
            lazy[node]+=val;
            push(node,l,r);
            return;
        }
        int mid=(l+r)/2;
        range_add(2*node+1,l,mid,ql,qr,val);
        range_add(2*node+2,mid+1,r,ql,qr,val);
        maxi[node]=max(maxi[2*node+1],maxi[2*node+2]);
        mini[node]=min(mini[2*node+1],mini[2*node+2]);
    }

    int query_last_zero(int node,int l,int r,int start) 
    {
        push(node,l,r);
        if(r<start)return -1;
        if(mini[node]>0 || maxi[node]<0)return -1;
        if(l==r)return l;
        int mid=(l+r)/2;
        int right=query_last_zero(2*node+2,mid+1,r,start);
        if(right!=-1)return right;
        return query_last_zero(2*node+1,l,mid,start);
    }

    int longestBalanced(vector<int>& nums) 
    {
        n=nums.size();
        map<int,queue<int>>occ;

        auto sgn=[](int x) 
        {
            return(x%2==0)?1:-1;
        };

        vector<int>psum(n);
        psum[0]=sgn(nums[0]);
        occ[nums[0]].push(0);

        for(int i=1;i<n;i++) 
        {
            psum[i]=psum[i-1];
            if(occ[nums[i]].empty())psum[i]+=sgn(nums[i]);
            occ[nums[i]].push(i);
        }
        maxi.assign(4*n,0);
        mini.assign(4*n,0);
        lazy.assign(4*n,0);
        build(0,0,n-1,psum);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int r=query_last_zero(0,0,n-1,i+ans);
            if(r!=-1)ans=max(ans,r-i+1);
            occ[nums[i]].pop();
            int next_pos=n;
            if(!occ[nums[i]].empty())next_pos=occ[nums[i]].front();
            if(i+1<=next_pos-1)range_add(0,0,n-1,i+1,next_pos-1,-sgn(nums[i]));
        }

        return ans;
    }
};
